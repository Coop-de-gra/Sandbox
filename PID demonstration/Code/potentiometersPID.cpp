// Function prototypes (declarations)
void encoderISR();
void setMotorPWM(float pwmVal);
void stopMotor();

// ======== Pin Assignments ========

// --- Encoder pins ---
const int encoderPinA = 2;   // Must be interrupt-capable on many Arduinos
const int encoderPinB = 3;   // Optional for direction or improved resolution

// --- Motor driver pins (TB6612FNG) ---
const int motorPWMPin  = 9;
const int motorIn1Pin  = 7;
const int motorIn2Pin  = 8;
const int motorSTBYPin = 6;  // If controlling STBY from Arduino

// --- Potentiometer pins ---
const int potPinSP = A0; // Setpoint
const int potPinKP = A1; // Kp
const int potPinKI = A2; // Ki
const int potPinKD = A3; // Kd

// --- ON/OFF pins ---
const int ONOFF  = 4;

// ======== PID & System Variables ========

// Volatile because updated in ISR
volatile long encoderCount = 0; 

// Motor and output speeds
float motorRPM  = 0.0;  
float outputRPM = 0.0;  
float targetRPM = 0.0;  

// PID gains (updated in real-time from pots)
float Kp = 2.0;   // default/initial
float Ki = 0.5;   // default/initial
float Kd = 0.1;   // default/initial

// Intermediate PID variables
float integral  = 0.0;
float lastError = 0.0;
float controlOutput = 0.0;

// Gear ratio: 50:1
float gearRatio = 50.0;

// Encoder pulses per motor revolution (example; yours may differ!)
float pulsesPerRev = 20.0;

// Timing
unsigned long prevMillis = 0;

// Serial Control
bool loopEnabled = false;  // Start with loop disabled

void setup() {
  Serial.begin(9600);
  
  // --- Encoder Pins ---
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderISR, RISING);

  // --- Motor Driver Pins ---
  pinMode(motorPWMPin, OUTPUT);
  pinMode(motorIn1Pin, OUTPUT);
  pinMode(motorIn2Pin, OUTPUT);
  pinMode(motorSTBYPin, OUTPUT);

  // Enable the driver
  digitalWrite(motorSTBYPin, HIGH);

  // Initialize motor outputs
  digitalWrite(motorIn1Pin, LOW);
  digitalWrite(motorIn2Pin, LOW);
  analogWrite(motorPWMPin, 0);

  // --- Potentiometer Pins ---
  pinMode(potPinSP, INPUT);
  pinMode(potPinKP, INPUT);
  pinMode(potPinKI, INPUT);
  pinMode(potPinKD, INPUT);

  // --- ON/OFF pins ---
  pinMode(ONOFF, INPUT);
}

void loop() {
  // Handle Serial Commands
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      loopEnabled = true;
      Serial.println("Loop started");
    } else if (command == '0') {
      loopEnabled = false;
      Serial.println("Loop stopped");
      stopMotor();  // Turn off the motor immediately
    }
  }

  // Only run control logic if enabled
  if (loopEnabled) {
    unsigned long currentMillis = millis();

    // 1) Read Potentiometers
    int potValSP = analogRead(potPinSP);
    targetRPM = map(potValSP, 0, 1023, 0, 200);

    int potValKP = analogRead(potPinKP);
    Kp = (float)potValKP / 1023.0 * 5.0;

    int potValKI = analogRead(potPinKI);
    Ki = (float)potValKI / 1023.0 * 2.0;

    int potValKD = analogRead(potPinKD);
    Kd = (float)potValKD / 1023.0 * 2.0;

    // 2) Every 100 ms, update speed measurement and run PID
    if (currentMillis - prevMillis >= 100) {
      prevMillis = currentMillis;

      // Copy and reset the encoder count
      long count = encoderCount;
      encoderCount = 0;

      // motorRPM based on motor shaft pulses
      float intervalSec = 0.1; // 100 ms
      motorRPM = (count / pulsesPerRev) / intervalSec * 60.0;

      // Convert to output shaft RPM
      outputRPM = motorRPM / gearRatio;

      // 3) PID calculation on output shaft speed
      float error = targetRPM - outputRPM;
      integral += error * intervalSec;
      float derivative = (error - lastError) / intervalSec;
      lastError = error;

      controlOutput = (Kp * error) + (Ki * integral) + (Kd * derivative);

      // 4) Constrain the control output for Arduino PWM [0..255]
      controlOutput = constrain(controlOutput, 0, 255);

      // 5) Drive the motor
      setMotorPWM(controlOutput);

      // 6) Debug Print
      Serial.print(targetRPM);
      Serial.print(" ");
      Serial.print(outputRPM);
      Serial.print(" ");
      Serial.print(motorRPM);
      Serial.print(" ");
      Serial.print(Kp);
      Serial.print(" ");
      Serial.print(Ki);
      Serial.print(" ");
      Serial.println(Kd);
    }
  } else {
    stopMotor();  // Ensure motor is off when the loop is disabled
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
  analogWrite(motorPWMPin, 0);  // Stop PWM signal
}
