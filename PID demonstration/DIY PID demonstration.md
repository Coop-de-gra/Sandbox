## N20 DC Motor ##

* https://www.adafruit.com/product/4638

#### How to hook it up ####

* M1 (White) - Power - Motor Power Supply -
* GND (Blue) - Power - Encoder GND -
* C1 (Green) - output - Encoder A Phase
* C2 (Yellow) - output - Encoder B Phase
* VCC (Black) - power - Encoder Power Supply +
* M2 (Red) - power - Motor Power Supply +

## TB6612FNG Motor Controller ##

* (https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide/all)

#### How to hook it up ####

* VM - Motor Voltage - power - 2.2-13.5VDC
* VCC - Logic Voltage - power - power chip and talk to microcontroller - 2.7-5.5vDC
* GND - Ground - power
* STBY - Standby - input - Allows H-bridges to work when high - must be high for motors to drive
* AIN1/BIN1 - input 1 for channels A/B - input - one of two inputs that determine direction
* AIN2/BIN2 - input 2 for channels A/B - input - one of two inputs that determine direction
* PWMA/PWMB - PWM input for channels A/B - input - PWM input that controls the speed
* A01/B01 - output 1 for channels A/B - output - one of the two outputs the connect to the motor
* A02/B02 - output 2 for channels A/B - output - one of the two outputs the connect to the motor

#### How to control each of the channels ####
```
In1    In2    PWM    Out1    Out2      Mode
H      H      H/L    L        L      Short brake
L      H      H      L        H      CCW
L      H      L      L        L      Short brake
H      L      H      H        L      CW
H      L      L      L        L      Short brake
L      L      H      OFF      OFF    Stop
```

```
#include <pigpio.h>
#include <iostream>

int main() {
    // Initialize pigpio.
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed!" << std::endl;
        return 1;
    }

    // Set GPIO as an output.
    gpioSetMode(18, PI_OUTPUT);
    gpioSetMode(23, PI_OUTPUT);

    gpioSetMode(13, PI_OUTPUT); //PWMA
    gpioSetMode(19, PI_OUTPUT); //AIN1
    gpioSetMode(26, PI_OUTPUT); //AIN2


    int blinkCount = 0;
    while (blinkCount < 6) {
         // Turn the LED on
        gpioWrite(18, 1);
        gpioDelay(100000); // Delay in microseconds

        // Turn the LED off
        gpioWrite(18, 0);
        gpioDelay(100000); // Delay in microseconds

        // Turn the LED on
        gpioWrite(23, 1);
        gpioDelay(100000); // Delay in microseconds

        // Turn the LED off
        gpioWrite(23, 0);
        gpioDelay(100000); // Delay in microseconds

        blinkCount++;
    }

    int motorTestLoop = 0;
    while (motorTestLoop < 1) {
        gpioWrite(19, 0); //IN1 L
        gpioWrite(26, 1); //IN2 H
        gpioWrite(13, 1); //PWM H
        gpioDelay(100000);
        motorTestLoop++;
    }

    // Terminate pigpio.
    gpioTerminate();
    return 0;
}
```
