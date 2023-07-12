# SumoBot

In this folder you can find:
- A .pdf file named "sumo_circuit" with the connections of the circuit made in Kicad 6.0
- Explanation of the microcontroller pins used.
- Recommendations for the implementation of the circuit.

### components
Component specifications can be found in the list of commercial components [here](https://github.com/valeeBurgos/SumoBot/tree/main/hardware/body)

### Pins

The connections to the Arduino Uno R3 board are listed below. First, the digital pins are listed in order, followed by the analog pins.

Digital pins:
- 13 EchoM 
- 12 TrigL
- 11 EchoR
- 10 TrigR
- 9 ENA
- 8 IN1
- 7 IN2
- 6 EchoL
- 5 TrigM
- 4 IN4
- 3 ENB
- 2 IN3


Where the pins with the words Trig and Echo belong to ultrasound sensors. The letters that accompany it indicate its position: L is left, R right, M is middle.
The pins belonging to the system to control the motors are ENA, IN1, IN2, ENB, IN3, IN4.


Analog pins:
- A0 S1
- A1 S2
- A2 S3
- A3 S4
- A4 button

The connected pins correspond to the infrared sensors for line detection. In this case, they are digital pins but the analog inputs are used.
A button is also connected to an analog input.

### Notes
1. You can notice that almost all available pins of the place are used. If you want to add new elements, you must consider the space or change the microcontroller.
2. Infrared and ultrasonic sensors can interchange pins with respect to their same type. If these are interchanged, the code must be changed to ensure correct operation and expected behavior.
3. A 16V voltage is being used, but a 12V source is sufficient.
4. A regulator is used to go from 16V to 5V to power the microcontroller and sensors. It is important not to connect directly to 16V.
5. It is considered a good option to use a switch to control the power. It is not implemented in this circuit.
