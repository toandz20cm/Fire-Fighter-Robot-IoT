# Fire-Fighter-Robot-System
Fire fighter robot can be used to control the fire. this robot can detect the fire by itself and control the fire by throwing water. there are some sensors we are using that can detect fire and robots can move there to fire extinguish.The fire fighting robot has the same structure as Bluetooth control RC car. the robot has 3 sensors 1 sensor at the front side which see if there is anything in front of the robot.

The other two at the both front corner which also searches for fire. if any sensor detects fire at any site the robot will sensor and move towards it. the fire fighting robot has 4 wheels, 3 sensors, one water tank, one nozzle, and a computer which help him to take decision according to the Arduino code.

**Fire Detection and Fighter Robot** is a three-part embedded system designed to detect indoor fires and autonomously dispatch a robotic vehicle to suppress them. It is composed of:

- A **Detect** ...
- A **Vehicle** ...
- A **Remote Annena (RF)** ...

Wireless communication between both units is established using an **ESP-01 WiFi module**, enabling decentralized and responsive fire management.

---

## Overview

The job of a firefighter is one of the most dangerous jobs in the world. They have to face risky situations while rescuing victims or extinguishing fires. The jobs of these fire fighters can be made a lot easier if there can be a robot which itself can extinguish small fires automatically. A robot can also reach places which are not easily reachable by a human. Also in households, a robot which automatically detects fire and extinguishes it can be a blessing, as it can extinguish a small house-fire before it spreads and becomes a life-threatening one.

---
## Features

1. **Manual Mode:**
   - **Remote Operation:** Control the robot remotely using Bluetooth, RF Module, or IR Remote.
   - **Device Compatibility:** Operate the robot from a mobile phone, laptop, or joystick.
   - **Movement Control:** Have full control over the robot's movement.
   - **Water Pump Activation:** Activate the water pump manually for firefighting purposes.

2. **Autonomous Firefighting:**
   - **Fire Detection:** Utilize sensors for autonomous detection of fires.
   - **Automated Response:** Enable the robot to engage in firefighting actions without human intervention.
   - **Intelligent Navigation:** Implement algorithms for efficient and safe navigation in firefighting scenarios.
---
## Algorithm

The robot will continuously roam around the room following a zigzag pattern. For this, we have used a variable nextTurn indicating the next turn of the robot. When the robot reaches a wall in its front,  it will turn in the direction indicated by nextTurn. It will go forward a bit and then turn in the direction indicated by nextTurn again, making it a U-turn and continuing on its zigzag path.

When the robot detects an obstacle in front (if the value of the front ultrasonic sensor is less than 20?), it will check the value of the ultrasonic sensor of the direction indicated by nextTurn(eg. right). If there is no obstacle in that direction, it will turn in that direction(right) and move forward a bit. After moving forward, it checks in the other direction(left). If it detects an obstacle, it will treat it whole as a wall and turn again (right), making it a U-turn. If however there is no obstacle there, it will take a turn in the other direction (left), move forward for some time and take another turn (left), move forward again, and then take a turn in the other direction(right), thus avoiding the obstacle in front and continuing on its path.

If the robot detects an obstacle in front and there is also an obstacle in the direction indicated by nextTurn(eg. right), it will check the value of the ultrasonic sensor on the other side(left). If there is no obstacle there, it will follow the same pattern above for that direction(left).
If the robot detects an obstacle in all three directions (if the values in all of the ultrasonic sensors is less than 20?), then it will move backward a bit and then check for obstacle in the direction indicated by nextTurn, and then follow the same algorithm above.

If the robot detects fire in its front(the range measured in the front fire sensor is less than 4?), it automatically means that there is no obstacle in the path between the robot and the fire, so it will move forward and get closer to the fire. If the robot detects fire in left or right direction, it will turn in that direction while simultaneously searching for fire in the front sensor. When it detects fire in the front, it will follow the same algorithm as if it detected the fire in front, going closer to the fire. When it gets close enough(the range measured in the front fire sensor is 0?), the buzzer will buzz and the robot will spray water on fire using the servo motor and servo bracket until the fire is extinguished(value in the front fire sensor is not 0?). After extinguishing the fire, the robot will avoid that area treating it as an obstacle and continue on its zigzag motion, searching for another fire.

---
##  Circuit Diagram
### Vehicle
Updating ...
### Remote
Updating ...
---

## Working Principle
### Vehicle

### Remote
Updating ...
---

## Developed Fire Fighting Robot

The real-time firefighting robot is described in this project.
It moves at a constant speed, detects fires, and then puts
them out using a pumping mechanism. In addition to
having a small body and a light structure, it includes
advantageous features such as the capacity to detect the
position of fire automatically. The robot's diminutive form
allows it to be deployed in places with narrow entrances
and cramped areas. The method may help support
firefighters and halt an outbreak. Additionally, the
operator can put out fires remotely and at a greater
distance. According to the findings of the experiments, the
robot can quickly and reliably detect fire.

---

## 🔩 Hardware Used

|Component | Purpose|
| :---------------- | :------: |
|ESP32 Dev Module | Fire monitoring and logic|
|Arduino Uno |Vehicle control|
|ESP-01 WiFi Module | WiFi communication bridge| 
|IR Flame Sensor |Fire detection|
|L298N Motor Driver| Controls DC motors |
|Servo Motor / Water Pump |Fire suppression|
|12V Battery Pack |Power supply for motors and pump|
|Resistor (220 ohm) |        |
|Jumper Wires |        |
|Breadboard |        |
|Buck Converter |        |
|Robot Chassis with 4 motors and 4 wheels|        |
|Single channel relay|   |
---

## Testing Checklist
	•	✅ ESP32 detects fire and sends correct message
	•	✅ ESP-01 correctly relays message to Arduino
	•	✅ Rover responds to room(x) messages
	•	✅ Suppression system activates after arrival
	•	✅ No false positives or unnecessary dispatch