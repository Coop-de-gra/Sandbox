Great! I'll guide you through wiring the TB6612FNG motor controller to your Raspberry Pi and writing a C++ program using pigpio to control a 12V DC motor.

I'll gather information on:
- Proper wiring connections between the Raspberry Pi, TB6612FNG, and the motor
- Necessary components (e.g., external 12V power supply, logic-level connections)
- C++ code to control motor speed and direction using PWM and GPIO
- Safety considerations when handling motor drivers and higher voltages

I'll get back to you shortly with detailed instructions.

# Controlling a 12V DC Motor with TB6612FNG and Raspberry Pi

## Wiring Instructions

**Power Connections:** The TB6612FNG has separate pins for motor voltage (VM) and logic voltage (VCC). Connect the **VM pin** to your 12 V motor power source’s positive terminal, and connect **GND** pins to the negative terminal of the 12 V supply **and** to the Raspberry Pi’s ground (all grounds must be common) ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=1)). Connect the **VCC pin** on the TB6612FNG to the Pi’s 3.3 V power pin (e.g. physical pin 1 or 17) to power the driver’s logic ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=1)). (The TB6612FNG’s logic voltage can be 2.7–5.5 V, so 3.3 V from the Pi is within range ([TB6612FNG Dual Motor Driver](https://www.robotpark.com/TB6612FNG-Dual-Motor-Driver#:~:text=Since%20the%20logic%20voltage%20level,and%205V%20logic%20voltage%20levels)). *Using 3.3 V for VCC is recommended so that the Pi’s 3.3 V GPIO signals are recognized reliably ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/#:~:text=The%20Micro%20Metal%20Gear%20Motors,following%20post%20after%20this%20one)).*) Ensure a **common ground** connection between the Raspberry Pi, the motor driver, and the motor power supply ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=1)) – this is critical for the control signals to reference the same ground.

 ([Driving Small Motors With the  TB6612FNG : 8 Steps - Instructables](https://www.instructables.com/Driving-Small-Motors-With-the-TB6612FNG/)) *TB6612FNG breakout pinout and groups.* **Power pins** (red) include VM (to motor supply up to 15 V) and VCC (to logic 3.3 V/5 V), plus multiple GND pins ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=Pin%20Number%20Pin%20Name%20Description,A02%20Motor%20A%20output%20pins)). **Motor output pins** (purple/green) AO1, AO2 connect to Motor A, BO1, BO2 to Motor B ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=Pin%20Number%20Pin%20Name%20Description,A02%20Motor%20A%20output%20pins)). **Control input pins** (blue/green) include PWMA/PWMB for PWM speed control, AIN1/AIN2 and BIN1/BIN2 for direction control, and STBY (standby, orange) ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=Pin%20Number%20Pin%20Name%20Description,B02%20Motor%20B%20output%20pins)).

**Motor Connections:** Connect your DC motor leads to the output terminals **AO1** and **AO2** for channel A (use **BO1** and **BO2** for a second motor on channel B) ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=%2A%20GND%20,negative%20pole%20of%20motor%20battery)). It doesn’t matter which motor wire goes to AO1 vs AO2; reversing them will just flip the motor’s rotation direction. If using only one motor (channel A), you can leave the B-channel outputs unconnected. Remember to use a motor that draws under ~1.2 A continuously (TB6612FNG’s per-channel limit) to avoid overheating ([Using the Sparkfun Motor Driver 1A Dual TB6612FNG - a Beginner's Guide : 9 Steps - Instructables](https://www.instructables.com/Using-the-Sparkfun-Motor-Driver-1A-Dual-TB6612FNG-/#:~:text=Before%20you%20start%20,2A%20peak)).

**GPIO Control Connections:** Choose three GPIO pins on the Raspberry Pi to control the motor: two for direction and one for speed (PWM). For **motor A**, connect **AIN1** and **AIN2** on the TB6612FNG to two GPIO outputs on the Pi (these will be digital direction controls) ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=3)). Then connect **PWMA** on the TB6612FNG to a Pi GPIO that supports PWM output (for hardware PWM you can use BCM18 or BCM19 on a Pi, or you can use any GPIO with software PWM via the `pigpio` library). For example, you might use: 

- AIN1 → GPIO 17 (BCM 17, physical pin 11)  
- AIN2 → GPIO 27 (BCM 27, physical pin 13)  
- PWMA → GPIO 18 (BCM 18, physical pin 12, supports hardware PWM)

These are just example pins – you can use any available GPIOs for AIN1/AIN2, and any PWM-capable GPIO for PWMA ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/#:~:text=H,are%20convenient%20for%20my%20application)). If you plan to use the B channel for a second motor, also connect BIN1, BIN2 to two more GPIOs and PWMB to another PWM-capable GPIO in a similar manner.

**Standby Pin:** The TB6612FNG has a standby pin **STBY** that must be pulled HIGH to enable the motor driver ([Brief introduction of tb6612fng and its design of DC motor control system with single chip microcomputer - Latest Open Tech From Seeed](https://www.seeedstudio.com/blog/2020/09/30/brief-introduction-of-tb6612fng-and-its-design-of-dc-motor-control-system-with-single-chip-microcomputer/?srsltid=AfmBOorrUs32Ykd5PK37uQ_fOepxsi8ZbjrR4QSez0Sbr3xPCS8UBueg#:~:text=,logic%20level%20input%20terminals%20respectively)) ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=4)). Connect STBY to a Raspberry Pi GPIO (or directly to 3.3 V through a jumper) to control it. E.g., you could wire STBY to GPIO 22 (physical pin 15) and have your code set that pin HIGH when you want to enable the driver. (If you prefer simplicity and don’t need to turn the driver off in software, you can tie STBY to 3.3 V directly ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=%2A%20AIN2%20,VCC%20from%20Raspberry)). It has an internal pull-down, so leaving it unconnected will keep the driver in standby ([untitled](https://cdn.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf#:~:text=16%20BIN2%20I%20chB%20input2,down%20at%20internal)) ([untitled](https://cdn.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf#:~:text=VM1%20VM3%20VM2%20PWMA%20BIN1,BO2%20PGND2%20BO2%20PGND2%20BO1)).) By controlling STBY via GPIO, you can disable the motor outputs in standby mode when the motor is not needed or during startup to prevent any glitchy motion on boot ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/#:~:text=Note%20%E2%80%93%20Add%20a%20suitable,if%20building%20the%20circuit%20above)).

**Example Wiring Summary:** Suppose we use the example pins mentioned: Connect TB6612 **AIN1** to Pi GPIO 17, **AIN2** to GPIO 27, **PWMA** to GPIO 18, and **STBY** to GPIO 22. Tie all GNDs together (Pi GND, TB6612 GND, battery negative). Connect TB6612 **VM** to +12 V, **VCC** to Pi’s 3.3 V. Finally, connect the motor leads to **AO1/AO2**. Double-check all connections before powering up: the Pi’s GPIO pins should **never** be directly connected to 12 V; they only go to the TB6612’s input pins (which act as 3.3 V logic inputs to the driver).

 ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/)) *Example wiring concept:* A TB6612FNG breakout (red board) connected to a Raspberry Pi. The motor driver’s VM (yellow wire) is connected to an external battery (12 V) supply through a switch (black component on left), VCC (orange wire) goes to the Pi’s 3.3 V, GND (brown wires) to common ground. Control wires from the Pi’s GPIO (blue/purple) connect to the TB6612’s AIN1, AIN2, BIN1, BIN2, and PWM pins for two motors (this example shows a dual-motor setup). The standby pin is tied to 3.3 V in this setup (orange jumper) to keep the driver enabled ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=%2A%20AIN2%20,GND%20of%20Raspberry)).

## Software & Code

Once the wiring is set up, you can control the motor through the Raspberry Pi’s GPIO pins using the `pigpio` library. Below is how to prepare the software and an example C++ program to control motor direction and speed with PWM.

**Setting up pigpio:** Ensure the pigpio library is installed on your Raspberry Pi. You can install it via apt if needed (e.g. `sudo apt install pigpio` for the daemon and `sudo apt install libpigpio-dev` for C/C++ development). Start the pigpio daemon with `sudo pigpiod` or initialize it in code. In a C++ program, you’ll include pigpio (`#include <pigpio.h>`) and call `gpioInitialise()` at the start of your program. Remember that using pigpio usually requires root privileges (run your program with `sudo` or ensure the daemon is running). The pigpio library lets you set GPIO modes, write digital values, and generate PWM signals on GPIO pins programmatically.

**TB6612FNG control logic:** Each motor channel is controlled by three inputs: IN1, IN2, and PWM. For channel A, these correspond to AIN1, AIN2, PWMA. To drive the motor **forward**, you set one input HIGH and the other LOW (which one is HIGH/LOW determines the direction). For example, AIN1 = HIGH and AIN2 = LOW might spin the motor clockwise ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=I%20don%E2%80%99t%20use%20PWM%20and,connect%20it%20to%20VCC)). To drive **reverse**, flip those: AIN1 = LOW, AIN2 = HIGH (spins counter-clockwise) ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=I%20don%E2%80%99t%20use%20PWM%20and,connect%20it%20to%20VCC)). The PWM pin (PWMA) controls speed: a PWM duty cycle of 0% (0 out of 255) means stop, and 100% (255/255) means full speed. Intermediate values modulate the speed by rapidly turning the motor on/off. If you set both AIN1 and AIN2 LOW (and PWM HIGH), the motor will coast to a stop (outputs off – this is a **stop** mode). If you set both AIN1 and AIN2 HIGH while the PWM is HIGH, the driver activates **short brake** mode, dynamically braking the motor by shorting its terminals. In practice, to **stop** the motor you can simply set the PWM duty to 0%, which effectively removes drive voltage (allowing a coast), or explicitly drive both inputs LOW. To **enable movement**, make sure STBY is HIGH (the driver is active) ([Brief introduction of tb6612fng and its design of DC motor control system with single chip microcomputer - Latest Open Tech From Seeed](https://www.seeedstudio.com/blog/2020/09/30/brief-introduction-of-tb6612fng-and-its-design-of-dc-motor-control-system-with-single-chip-microcomputer/?srsltid=AfmBOorrUs32Ykd5PK37uQ_fOepxsi8ZbjrR4QSez0Sbr3xPCS8UBueg#:~:text=,logic%20level%20input%20terminals%20respectively)).

**C++ Code Example (using pigpio):** Below is a simple C++ program demonstrating how to initialize the GPIO, set motor direction, and vary speed using PWM. It assumes the following wiring: AIN1 → GPIO 17, AIN2 → GPIO 27, PWMA → GPIO 18, STBY → GPIO 22 (these correspond to the constants in the code). The program ramps the motor speed up and down in forward direction, then does the same in reverse:

```cpp
#include <pigpio.h>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const unsigned PIN_AIN1 = 17;   // GPIO for AIN1
const unsigned PIN_AIN2 = 27;   // GPIO for AIN2
const unsigned PIN_PWMA = 18;   // GPIO for PWMA (must be PWM-capable)
const unsigned PIN_STBY = 22;   // GPIO for STBY (standby)

int main() {
    if (gpioInitialise() < 0) {
        cerr << "pigpio init failed\n";
        return -1;
    }
    // Set up pins as outputs
    gpioSetMode(PIN_AIN1, PI_OUTPUT);
    gpioSetMode(PIN_AIN2, PI_OUTPUT);
    gpioSetMode(PIN_PWMA, PI_OUTPUT);
    gpioSetMode(PIN_STBY, PI_OUTPUT);
    
    // Ensure motor driver is enabled
    gpioWrite(PIN_STBY, 1);        // take STBY out of standby (HIGH = active)
    gpioWrite(PIN_AIN1, 0);
    gpioWrite(PIN_AIN2, 0);
    gpioPWM(PIN_PWMA, 0);         // start with PWM=0 (motor off)

    // Set PWM frequency (optional, e.g. 1000 Hz) and range (0-255)
    gpioSetPWMfrequency(PIN_PWMA, 1000);
    gpioSetPWMrange(PIN_PWMA, 255);

    // Spin motor forward (AIN1=HIGH, AIN2=LOW) and ramp speed up
    gpioWrite(PIN_AIN1, 1);
    gpioWrite(PIN_AIN2, 0);
    for (int duty = 0; duty <= 255; duty += 5) {
        gpioPWM(PIN_PWMA, duty);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    // Ramp speed down to 0
    for (int duty = 255; duty >= 0; duty -= 5) {
        gpioPWM(PIN_PWMA, duty);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    // Brief stop
    gpioPWM(PIN_PWMA, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // Spin motor in reverse (AIN1=LOW, AIN2=HIGH) and ramp speed up
    gpioWrite(PIN_AIN1, 0);
    gpioWrite(PIN_AIN2, 1);
    for (int duty = 0; duty <= 255; duty += 5) {
        gpioPWM(PIN_PWMA, duty);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    // Ramp down again
    for (int duty = 255; duty >= 0; duty -= 5) {
        gpioPWM(PIN_PWMA, duty);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    // Stop motor and cleanup
    gpioPWM(PIN_PWMA, 0);
    gpioWrite(PIN_AIN1, 0);
    gpioWrite(PIN_AIN2, 0);
    gpioWrite(PIN_STBY, 0);  // optionally put driver in standby
    gpioTerminate();
    return 0;
}
```

In this code, `gpioWrite(PIN_AIN1, 1)`/`gpioWrite(..., 0)` set the IN1/IN2 pins HIGH or LOW to choose direction, and `gpioPWM(PIN_PWMA, duty)` drives the PWMA pin with a PWM signal of the specified duty cycle (0–255). We set a PWM frequency of 1 kHz (1000 Hz) for smooth motor control – you can adjust this frequency if needed. A lower PWM frequency (e.g. 100 Hz) will also work but might produce an audible hum at certain speeds, while a very high frequency might be limited by pigpio’s capabilities or the motor driver’s switching speed (the TB6612 can handle up to 100 kHz PWM according to the datasheet ([untitled](https://cdn.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf#:~:text=Switching%20frequency%20fPWM%20,Internal%20200k%CE%A9%20circuit%20%E5%87%BA%E5%8A%9B%E7%AB%AF%E5%AD%90%3B%20O1%2CO2))). The code above gradually increases the duty cycle to accelerate the motor, then decreases it to decelerate, first in one direction then the other. You can adapt this logic to your needs (e.g. set a fixed speed or respond to user input).

**How it works:** When `AIN1=1` and `AIN2=0`, the motor driver will drive the motor in one direction (let’s call that “forward”). When `AIN1=0` and `AIN2=1`, it drives it in the opposite direction (“reverse”) ([RaspRob, the Raspberry Robot : 7 Steps (with Pictures) - Instructables](https://www.instructables.com/RaspRob-the-Raspberry-Robot/#:~:text=I%20don%E2%80%99t%20use%20PWM%20and,connect%20it%20to%20VCC)). The PWM signal on PWMA effectively turns the motor on and off rapidly – a higher duty cycle means the motor is powered for a larger fraction of the time, so it spins faster. Setting PWM to 0 turns the motor off (coasting stop), while setting PWM to the max (255) gives full speed. We also ensured the STBY pin is high during operation (we set it to 1) so that the driver isn’t in standby mode ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=4)). After we’re done, we set STBY low and do `gpioTerminate()` to clean up.

## Safety Considerations

Controlling motors involves handling higher currents and voltages, so keep these safety best practices in mind:

- **Use proper supply voltages:** Make sure **12 V from the motor supply NEVER goes into the Raspberry Pi’s 5 V or 3.3 V lines or any GPIO pins.** The motor power (VM) should only connect to the TB6612FNG’s VM input. Likewise, the TB6612’s VCC should be connected to a safe logic voltage (3.3 V from the Pi). Double-check polarity; reversing VM and GND or connecting 12 V to the wrong pin can destroy the driver or Pi. Stay within the TB6612FNG’s voltage limits (up to ~13.5 V on VM, and 2.7–5.5 V on VCC) ([Using the Sparkfun Motor Driver 1A Dual TB6612FNG - a Beginner's Guide : 9 Steps - Instructables](https://www.instructables.com/Using-the-Sparkfun-Motor-Driver-1A-Dual-TB6612FNG-/#:~:text=Before%20you%20start%20,2A%20peak)).

- **Common ground:** Always connect the grounds of the Raspberry Pi, the motor driver, and the motor power source together ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=1)). A missing common ground is a common mistake that prevents the control signal from referencing the motor driver properly. Use a thick enough ground wire to handle the motor current.

- **Power source and current:** Use a proper **12 V power source** capable of supplying the stall current of your DC motor. A motor can draw significantly more current at startup or stall than its running current. If you’re using a battery, ensure it’s adequately rated (and recharged as needed – running the Pi off a dying battery can cause undervoltage issues and SD card corruption ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/#:~:text=motors%2C%20they%20start%20to%20lose,corrupt%20the%20OS%20SD%20Card))). If using an AC/DC adapter or bench supply, it should have a current limit above the motor’s peak draw. **Do not power the motor from the Pi’s 5 V pin** unless the motor is very small – the Pi’s 5 V rail comes from USB or its regulator and isn’t meant for high-current motors. For a 12 V motor, an external supply is mandatory.

- **Back-EMF and noise:** DC motors generate voltage spikes (back EMF) when they switch on/off or reverse. The TB6612FNG includes internal flyback diode protection for these spikes ([Driving Small Motors With the  TB6612FNG : 8 Steps - Instructables](https://www.instructables.com/Driving-Small-Motors-With-the-TB6612FNG/#:~:text=Capacitors%20are%20soldered%20on%20to,ceramic%20capacitors%20to%20the%20motors)), and many breakout boards have onboard capacitors to smooth noise ([Driving Small Motors With the  TB6612FNG : 8 Steps - Instructables](https://www.instructables.com/Driving-Small-Motors-With-the-TB6612FNG/#:~:text=Capacitors%20are%20soldered%20on%20to,ceramic%20capacitors%20to%20the%20motors)). However, it’s good practice to add additional noise suppression if needed. You can place a **decoupling capacitor** (for example, 100 µF electrolytic in parallel with 0.1 µF ceramic) across the motor’s power supply (VM to GND) close to the driver to smooth the supply. For extra protection, you can also solder a small capacitor (0.1 µF ceramic) across the motor’s terminals to reduce brush noise. If your motor is large or you’re extra cautious, you might add **flyback diodes** across the motor terminals as well (one diode in each direction, or a single diode if you ensure current flows only one way) ([Using the Sparkfun Motor Driver 1A Dual TB6612FNG - a Beginner's Guide : 9 Steps - Instructables](https://www.instructables.com/Using-the-Sparkfun-Motor-Driver-1A-Dual-TB6612FNG-/#:~:text=match%20at%20L253%20Back%20EMF,to%20use%20is%20the%201N4001)). These diodes shunt sudden voltage spikes back into the motor rather than into your circuit. (Note: Most H-bridge drivers like the TB6612FNG internally handle this, so external diodes are usually optional ([Driving Small Motors With the  TB6612FNG : 8 Steps - Instructables](https://www.instructables.com/Driving-Small-Motors-With-the-TB6612FNG/#:~:text=The%20IC%20also%20comes%20with,I%27m%20short%20on%20diodes)).)

- **Standby and startup state:** Take advantage of the STBY (standby) pin to ensure the motor stays off when you want it off. For example, keep STBY low during boot-up and only set it HIGH when your program is ready to control the motor. This prevents any unintended motor motion if the GPIO pins float or glitch during boot ([Motor Driver for Raspberry Pi Robot using TB6612FNG - bluetin.io](https://www.bluetin.io/dc-motors/motor-driver-raspberry-pi-tb6612fng/#:~:text=Note%20%E2%80%93%20Add%20a%20suitable,if%20building%20the%20circuit%20above)). The TB6612FNG’s standby default (pulled down) helps – if STBY is tied to Pi and Pi boots with that pin as input (low), the driver will default to standby (motor off) until your code explicitly enables it ([untitled](https://cdn.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf#:~:text=16%20BIN2%20I%20chB%20input2,down%20at%20internal)). Nonetheless, explicitly initializing your GPIOs (setting IN1, IN2 low and PWM 0) at program start is good practice.

- **Thermal and current limits:** The TB6612FNG can provide about 1.2 A continuous per channel (up to ~3 A peak for short bursts) ([Using the Sparkfun Motor Driver 1A Dual TB6612FNG - a Beginner's Guide : 9 Steps - Instructables](https://www.instructables.com/Using-the-Sparkfun-Motor-Driver-1A-Dual-TB6612FNG-/#:~:text=Before%20you%20start%20,2A%20peak)). Pushing it near the limits will cause it to heat up. The chip has internal thermal shutdown, but you should avoid hitting that. If your motor draws close to or above this current, consider using a heatsink on the driver or active cooling, or use a higher-rated motor driver. Always test the driver’s temperature if running near the max current and give it some airflow if needed ([How to Use TB6612FNG Motor Driver: Pinouts, Specs, and Examples | Cirkit Designer](https://docs.cirkitdesigner.com/component/b3459e0a-8cf5-4208-b080-7033efd95a22/tb6612fng-motor-driver#:~:text=,currents%20near%20the%20peak%20ratings)). If the driver overheats, it will shut down to protect itself (and the motor will stop until it cools).

- **Physical safety:** When the motor is powered, ensure it and any connected mechanism can move freely without hitting anything or tangling wires. A 12 V motor can have significant torque, so secure the motor firmly and be careful of any rotating parts (wheels, gears) when testing your code. It’s wise to test at low speeds first and have a plan to cut power if the motor runs unexpectedly (for example, keep the 12 V supply on a switch or be ready to unplug it).

By following these guidelines – proper wiring, careful software control, and safety measures – you can reliably control a 12 V DC motor with a TB6612FNG driver using your Raspberry Pi. Enjoy your motor project, and always double-check connections when dealing with mixed voltages to protect your Pi and yourself!  ([ME 491: TB6612 Wiring and Usage Guide](http://web.cecs.pdx.edu/~gerry/class/ME491/notes/motor_driver_TB6612_hookup.html#:~:text=From%20the%20Adafruit%20tutorial%3A)) ([Driving Small Motors With the  TB6612FNG : 8 Steps - Instructables](https://www.instructables.com/Driving-Small-Motors-With-the-TB6612FNG/#:~:text=Capacitors%20are%20soldered%20on%20to,ceramic%20capacitors%20to%20the%20motors))

