# SumoBot: body

In this folder you will find everything you need to assemble the physical part of the robot discounting the circuit.
This includes (with images):
1. List of commercial components.
2. Links original files for 3D printing in GrabCAD.
3. Printing instructions
4. Assembly instructions.
6. Recommendations and observations



## Commercial components
- 1 x UNO R3 (UNO Full Microcontrolador Compatible, based on an ATmega microcontroller) (1)
- 2 x Motor Reductor 192rpm marca Troy modelo Luxor 25GA 12V (2)
- 1 x Driver L298N Puente H (3)
- 1 x Linear Regulator L7805CV  (4)
- 3 x Sensor Ultrasonico HC-SR04 (5)
- 3 x Push Button Momentary Switch 12mm (6)
- Floureon LiPo Battery 7,4 V 1500 mAh (7)
- 4 x analog Infrared reflective sensor 1-a (8)
- 1 x Universal protoboard (8 cm x 12 cm)  (9)
- mini 3PI car N20 Caster (10)
- Cabos  (11)
- 2 x conector T-DEAN (12)
- 24 x M3 x 10        (13)
- 24 x tuercas 3 mm   (14)
- 8 x M2 x 10         (15)
- 1 x resistor 47k    (16)




| ![Component 2](./images/component2.png) | ![Component 1](./images/component1.png) |
| :-------------------------------------: | :-------------------------------------: |


## 3D components
To manufacture this robot, 3D printing was produced as the main manufacturing resource. Fusion360 was used to create the models, supporting commercial component models created by the community.

In [this link](https://grabcad.com/library/robot-sumo-10) you can find the necessary components, in .step and .f3d format (except those obtained from the community for commercial components that are only in .step format)

Inside the CAD folder you will find the following files:
- Base delantera (1)
- Base trasera (2)
- Soporte Ultrasonido (3)
- Rampa (4)
- Segundo piso 1 (5)
- Segundo piso 2 (6)
- Rueda (7) *
- Soporte motor (8) *

Whose number in parentheses corresponds to those labeled in the following image
[3D components](./images/3d_component.png)

In the components folder you can find the commercial components used in .stl format. These are not to be printed, only used for a better visualization of the space.




## Printing instructions
To print these 8 components, it is considered that those marked with an * must be printed 2 times, since there are 2 wheels and motors that need support.

For this, an ender3 printer is used with the following parameters:
Wall : 2
Infill : 30%
Fill pattern :grid
Initial Layer Height : 0.28
Layer height : 0.32
Filament : PLA

The printing of all these pieces, in total, takes several hours. The files used are those that are in .stl format, so they do not need further adaptations.

## Assembly instructions
1. Base
As a first step, what can be seen in the image is assembled.
This corresponds to the following:
- 4 QTR-1d sensors to the base each with 1 bolt and nut M3 x 10
- Assemble the same to the ultrasonic sensor supports, using 4 M2 x10 bolts for each of the sensors.
- Motors on their respective supports held by part 8. 2 M3 x 10 nuts and bolts are used for each motor.
- The two parts of the base are joined with 2 M3 x 10 bolts with nuts.
- Piece 3 is joined with three M3 x 10 people. This piece also joins the two parts of the base.
The expected result is the one in the photo.
[1 step](./images/step_1.png)

2. First electrical connections

To each added sensor, use an arduino cable and connect it. Ideally, these connections should be soldered. For now, the other end is not connected.

3. Second layer of assembly
- In this step, pieces 5 and 6 are joined, which correspond to the second floor where the plate will be left. For this, 2 M3 x 10 bolts are used.
- Piece 4 is assembled. This is done by fitting the hole in the middle with the box of piece 1, in the lower part it has some cylinders that must be fitted with piece 1.
- Part 4 is joined to part 2 using 2 M3 x 10 bolts.
- Piece 4 is joined with pieces 5 and 6 with two M3 x10 buts.
[3 step](./images/step_2.png)

4. Circuit in universal protoboard

The circuit is then prepared. For this, a universal breadboard is used.
- Solder microcontroller to breadboard. It is important to leave space on the arduino to upload the program, access must be easy.
- Solder L298N to the breadboard 
- A button is welding to the breadboard.
- Paths are made on the breadboard to join the elements as indicated in the instructions in the circuit folder.
- A small breadboard resting on part 2 is used to connect gnd and 5v to all the sensors.
- With arduino cables, the sensors are connected to the microcontroller.

Separately, connect the batteries in series. For this, piece 12 is used. If you have a single battery with sufficient voltage, this can be omitted. You must connect the ground with the rest of the circuit, connect the battery to the L298N and to the voltage regulator, from which the microcontroller and sensors are fed. 
In general, it is as follows:
[4 step](./images/step_3.png)
[4 step](./images/step_35.png)

5. Last step
Attach wheels to engines carefully.
Confirm that the battery is firm.
Secure the breadboard with 4 bolts to parts 5 and 6.  

## Recommendations and observations
- It is important to have separately reviewed the circuit. Care must be taken in the connections.
- Separately printed parts are weak, they must be handled with care. Once assembled the structure is much more resistant
- It is important to follow the order in which the elements are connected. Otherwise it may not be possible to locate bolts correctly due to small gaps.
- The box of part 1 is to locate some point of contact with the ground to manage stability. They serve many elements, but it is recommended to use the commercial component 10.
- The connections must be made at the indicated time or there is a risk of not having enough space, for example below the ramp there are 2 sensors that must be wired before positioning it.
