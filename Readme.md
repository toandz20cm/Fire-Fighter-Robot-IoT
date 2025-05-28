# Fire-Fighter-Robot-System

## Project Status
- **Started:** 16/05/2025  
- **Status:**  _Ongoing_  
- **Expected Completion:** TBD  

---
Fire fighter robot can be used to control the fire. this robot can detect the fire by itself and control the fire by throwing water. there are some sensors we are using that can detect fire and robots can move there to fire extinguish.The fire fighting robot has the same structure as Bluetooth control RC car. the robot has 3 sensors 1 sensor at the front side which see if there is anything in front of the robot.

The other two at the both front corner which also searches for fire. if any sensor detects fire at any site the robot will sensor and move towards it. the fire fighting robot has 4 wheels, 3 sensors, one water tank, one nozzle, and a computer which help him to take decision according to the Arduino code.

**Fire Detection and Fighter Robot** is a two-part embedded system designed to detect indoor fires and autonomously dispatch a robotic vehicle to suppress them. It is composed of:
- A **Vehicle** ...
- A **Remote Annena (RF)** ...

Wireless communication between both units is established using an **ESP-01 WiFi module**, enabling decentralized and responsive fire management.

---

## Overview

The job of a firefighter is one of the most dangerous jobs in the world. They have to face risky situations while rescuing victims or extinguishing fires. The jobs of these fire fighters can be made a lot easier if there can be a robot which itself can extinguish small fires automatically. A robot can also reach places which are not easily reachable by a human. Also in households, a robot which automatically detects fire and extinguishes it can be a blessing, as it can extinguish a small house-fire before it spreads and becomes a life-threatening one.

---
## Features

### Manual Mode

- **Remote Operation:** Control via Bluetooth, RF module, or IR remote.
- **Device Support:** Compatible with smartphones, laptops, or joysticks.
- **Custom Movement:** Full directional control and water pump activation.

### Autonomous Mode

- **Fire Detection:** IR flame sensors detect heat sources.
- **Navigation:** Zigzag pathfinding with obstacle avoidance using ultrasonic sensors.
- **Response:** Fire is extinguished using a water pump upon detection.

---
## Algorithm

1. **Zigzag Patrolling:** The robot roams in a zigzag pattern using a variable `nextTurn` to determine its turning direction.
2. **Obstacle Handling:**  
   - If an obstacle is in front, check `nextTurn` direction.
   - If blocked in all directions, move backward, reassess, and continue.
3. **Fire Response:**
   - If fire is detected in the **front**, move forward until the fire is reached, then activate suppression.
   - If fire is detected on the **left/right**, turn towards the source and follow the same logic.
   - After extinguishing the fire, treat the area as an obstacle to avoid revisiting.

---
##  Circuit Diagram
### Vehicle
_Updating ..._

### Remote
_Updating ..._

---

## Working Principle
### Vehicle
Updating ...

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

| Component | Function |
|----------|----------|
| ESP32 Dev Module | Fire detection & logic processing |
| Arduino Uno | Motor and actuator control |
| ESP-01 WiFi Module | Wireless communication |
| IR Flame Sensors | Fire detection (multi-directional) |
| L298N Motor Driver | Drives DC motors |
| Servo Motor / Pump | Sprays water on fire |
| 12V Battery Pack | Powers motors and pump |
| Buck Converter | Voltage regulation |
| Single Channel Relay | Controls water pump |
| Resistors, Jumper Wires | Circuit connections |
| Breadboard | Circuit prototyping |
| 4-Wheel Robot Chassis | Mobile base |
---

## Testing Checklist
•	✅ ESP32 detects fire and sends correct message

•	✅ ESP-01 correctly relays message to Arduino

•	✅ Suppression system activates after arrival

•	✅ No false positives or unnecessary dispatch
