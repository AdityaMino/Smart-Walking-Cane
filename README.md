[![LabVIEW](https://img.shields.io/badge/LabVIEW-%23FFDB00.svg?style=for-the-badge&logo=ni-labview&logoColor=black)](https://www.ni.com/en-us/shop/labview.html)
[![Arduino IDE](https://img.shields.io/badge/Arduino%20IDE-%2300979D.svg?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)

# Smart-Walking-Cane
Ultrasonic sensing technology has had multiple applications since its emergence and some of these include home security systems, robotics applications, distance
measurement, tank level measurement, production lines, and proximity detection applications. These innumerable applications have made it possible to solve technical
problems faster and cheaper without compromising safety, quality, and stability.

The system’s design is in such a way that the ultrasonic sensor is mounted on a servo motor to allow full 360-degree rotations so that in any direction an ject/intruder approaches, the sensor would be able to detect the proximity. Once an object is detected, the system automatically emits a beeping sound, which can be used as either an alarm system for the specially-abled as a Guidance Stick. The stick would guide them into a different walking path, which is obstacle free, hence reducing their chances of collision with a foreign object.

## Introduction
Ultrasonic sensors, reminiscent of the natural echolocation used by bats and dolphins, function as the electronic eyes of contemporary SONAR systems. These sensors utilize high-frequency sound waves, known as ultrasonic waves, to explore and identify objects in their environment. Think of them as technological sentinels, employing sound to construct a detailed representation of the surroundings.

![image](https://github.com/user-attachments/assets/9dfb689b-f3d7-4bda-a16f-5ea3b294f463)

**Principle of Ultrasonic Sensing**

In an innovative initiative designed to enable the independence of differently abled individuals, our project takes advantage of ultrasonic sensors as a pivotal element. This endeavour focuses on creating a navigation system that empowers specially-abled individuals to navigate their surroundings more freely. 
Incorporated into mobility aids like canes or wheelchairs, these ultrasonic sensors serve as watchful companions, identifying obstacles in the user's path. Upon detecting an obstacle, the sensors relay signals to a Microcontroller/Microprocessor, alerting the user through vibrations or audible signals, offering real-time information regarding the proximity and location of obstacles. This application of ultrasonic technology not only promotes self-sufficiency for individuals with mobility challenges but also represents a significant step towards **fostering a more inclusive and accessible environment, with a direct social impact.**

## Working Principle
The Ultrasonic sensors used in SONAR are **piezoelectric-based**
1.	When voltage is applied to piezoelectric ceramics, mechanical distortion is generated according to the voltage and frequency. On the other hand, when vibration is applied to piezoelectric ceramics, an electric charge is produced. 
2.	By applying this principle, when an electric signal is added to a vibrator, constructed of 2 sheets of piezoelectric ceramics or a sheet of piezoelectric ceramics and a metal sheet, an electric signal is radiated by flexure vibration.
3.	As a reverse effect, when an ultrasonic vibration is added to the vibrator, an electric signal is produced. Because of these effects, piezoelectric ceramics are utilized as ultrasonic sensors.

![image](https://github.com/user-attachments/assets/74912d8d-4c43-4684-a493-a300a1e24a0c)

**Block Diagram of the System**

The system’s design is as follows:
- The HC-SR04 Ultrasonic sensor is mounted on a servo motor to allow for a 180-degree rotation of the sensor, to detect obstacles ahead of the user.
- Once an object is detected, the system automatically emits a beeping sound, through a piezo-buzzer, which can be used as an alarm system for the specially-abled.
- The stick would guide them into a different walking path, by means of a hand-held servomotor which steers them away from the obstacle. The servomotor will be used as a compass, so that any specially-abled person can access it, by their sense of touch.

## Methodology
The figure alongside represents the circuit diagram of our Smart Walking Cane Project. 

![image](https://github.com/user-attachments/assets/925f2bf8-3e79-485a-96b9-09ec9f048398)

**Circuit Diagram of the System, on Tinkercad**

The main attributes of the circuit are as follows-
1.	An HC-SR04 Ultrasonic Distance Sensor is used as the main transducer. It is mounted on a servo motor which is controlled by the Arduino UNO. It rotates the sensor from 0 to 180 degrees, and vice versa to allow for a full scan of the surroundings ahead.
2.	To initiate distance measurement, a trigger pulse is sent to the Trigger pin (usually labeled as "Trig"). This pulse is typically a 10 microsecond (μs) high signal. When triggered, the HC-SR04 emits a short ultrasonic burst. This burst consists of eight cycles of ultrasonic sound waves at a frequency of 40 kHz. After emitting the ultrasonic burst, the sensor waits for the echo to return. The Echo pin (usually labeled as "Echo") receives this echo signal. The time taken for the ultrasonic waves to travel to the object and back is measured. 
3.	The Arduino ATMEGA328P processes the data from the sensor and calculates the distance to impact. Once the Arduino is initialized the following actions take place-
- The Liquid Crystal I2C powers on and displays the default text. It then displays the distance to the object and accordingly gives directions to avoid it.
- The Ultrasonic Sensor mounted on the Servo Motor starts rotating.
- The 3 LEDs light up, based on the distance of the nearest obstacle.
  
  Red - Distance > 70cm
  
  Yellow – 70cm >Distance > 50 cm
  
  Green – Distance < 50 cm
  
- The Piezo Buzzer emits sound of frequency 300Hz, with varying distances to the object.
- The second Servo Motor, which steers the person away from the obstacle, starts working only when the distance to the object is less than 50cm.
4.	When an object is detected, the following occurs –
- Red LED lights up
- Piezo Buzzer continuously emits sound of frequency 300 Hz.
- Servo Motor steers the person away from the obstacle
- LCD displays the distance to the object.

![image](https://github.com/user-attachments/assets/0e5b10ac-376d-4cc6-b091-d8b73c2412bd)

**Flowchart of Design Problem**

![image](https://github.com/user-attachments/assets/49a01826-f6fa-42bd-981f-5ba14edeaae6)

**Software Simulation Results from LabVIEW**

## Limitations & Challenges 
Challenges faced in the project include: -
1.	Interfacing Arduino to LabVIEW. Finding and installing the right packages from NI Package Manager to interface the Arduino with LabVIEW.
2.	Finding the right positioning of this whole package of power supply and sensor to be mounted on a walking cane to give us an optimal output.
3.	This project does not work ideally with moving objects as it cannot detect the velocity of the obstacle and estimate its time of impact.
4.	The ultrasonic sensor can only detect obstacles ahead of the user, it cannot alert the user of any objects that may be approaching it from behind.

![image](https://github.com/user-attachments/assets/8cd7302b-abfb-41a0-ae05-a88220b8df1d)

**Hardware Snapshot**
