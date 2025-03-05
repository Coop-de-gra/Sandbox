// Function prototypes (declarations)
void encoderISR();
void setMotorPWM(float pwmVal);
void stopMotor();

// ======== Pin Assignments ========

// --- Encoder pins ---
const int encoderPinA = 2;
const int encoderPinB = 3;

// --- Motor driver pins (TB6612FNG) ---
const int motorPWMPin  = 9;
const int motorIn1Pin  = 7;
const int motorIn2Pin  = 8;
const int motorSTBYPin = 6;

// ======== PID & System Variables ========
volatile long encoderCount = 0; 

// Motor and output speeds
float motorRPM  = 0.0;  
float outputRPM = 0.0;  
float targetRPM = 50.0;  // Default target RPM (capped at 100 RPM)

// Manually set PID gains via Serial
float Kp = 2.0;
float Ki = 0.5;
float Kd = 0.1;

// Intermediate PID variables
float integral  = 0.0;
float lastError = 0.0;
float controlOutput = 0.0;

// Gear ratio
float gearRatio = 50.0;  // 50:1 gear ratio (need to physically count this)
float pulsesPerRev = 350.0;  // Adjust if needed (need to physically count this)

// Timing
unsigned long prevMillis = 0;

// Serial Control
bool loopEnabled = false; 

void setup() {
  Serial.begin(9600);
  
  // --- Encoder Pins ---
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderISR, CHANGE);

  // --- Motor Driver Pins ---
  pinMode(motorPWMPin, OUTPUT);
  pinMode(motorIn1Pin, OUTPUT);
  pinMode(motorIn2Pin, OUTPUT);
  pinMode(motorSTBYPin, OUTPUT);

  // Enable the driver
  digitalWrite(motorSTBYPin, HIGH);
  
  // Initialize motor outputs
  stopMotor();
  
  Serial.println("Send commands: T[Value] for Target RPM, P[Value] for Kp, I[Value] for Ki, D[Value] for Kd");
}

void loop() {
  // Handle Serial Commands
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); 

    if (command == "1") {
      loopEnabled = true;
      Serial.println("Loop started");
    } else if (command == "0") {
      loopEnabled = false;
      Serial.println("Loop stopped");
      stopMotor();
    } else if (command[0] == 'T') {
      targetRPM = command.substring(1).toFloat();
      targetRPM = constrain(targetRPM, 0, 100);  // Ensure max RPM is 100
      Serial.print("Target RPM set to: ");
      Serial.println(targetRPM);
    } else if (command[0] == 'P') {
      Kp = command.substring(1).toFloat();
      Serial.print("Kp set to: ");
      Serial.println(Kp);
    } else if (command[0] == 'I') {
      Ki = command.substring(1).toFloat();
      Serial.print("Ki set to: ");
      Serial.println(Ki);
    } else if (command[0] == 'D') {
      Kd = command.substring(1).toFloat();
      Serial.print("Kd set to: ");
      Serial.println(Kd);
    }
  }

  // Only run control logic if enabled
  if (loopEnabled) {
    unsigned long currentMillis = millis();

    // Run every 100ms
    if (currentMillis - prevMillis >= 100) {
      prevMillis = currentMillis;

      // Copy and reset the encoder count
      long count = encoderCount;
      encoderCount = 0;

      // Calculate RPM
      float intervalSec = 0.1;
      motorRPM = (count / pulsesPerRev) / intervalSec * 60.0;
      outputRPM = motorRPM / gearRatio;

      // PID calculation
      float error = targetRPM - outputRPM;
      integral += error * intervalSec;
      float derivative = (error - lastError) / intervalSec;
      lastError = error;

      controlOutput = (Kp * error) + (Ki * integral) + (Kd * derivative);
      controlOutput = constrain(controlOutput, 0, 255);

      // Drive the motor
      setMotorPWM(controlOutput);

      // Debug Print
      Serial.print("T:");
      Serial.print(targetRPM);
      Serial.print(" | O:");
      Serial.print(outputRPM);
      Serial.print(" | P:");
      Serial.print(Kp);
      Serial.print(" | I:");
      Serial.print(Ki);
      Serial.print(" | D:");
      Serial.print(Kd);
      Serial.print(" | PWM:");
      Serial.println(controlOutput);
    }
  } else {
    stopMotor();
  }
}

// Interrupt Service Routine for encoder (motor shaft)
void encoderISR() {
  encoderCount++;
}

// Helper function to set motor direction + PWM
void setMotorPWM(float pwmVal) {
  digitalWrite(motorIn1Pin, HIGH);
  digitalWrite(motorIn2Pin, LOW);
  analogWrite(motorPWMPin, (int)pwmVal);
}

// Function to stop the motor
void stopMotor() {
  digitalWrite(motorIn1Pin, LOW);
  digitalWrite(motorIn2Pin, LOW);
  analogWrite(motorPWMPin, 0);
}
