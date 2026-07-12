# 🚀 Quad-Servo Control System

**Author:** Waseem Al-wedyani  
**Field:** Electrical Engineering - Umm Al-Qura University

## 📄 Project Overview
This project constitutes a practical submission for the assigned task under the Smart Methods Summer Training 2026 program. The primary objective was to design, wire, and simulate an embedded control system using an Arduino Uno to synchronously operate four micro servo motors. The system focuses on safe power distribution and non-blocking time management to execute precise mechanical movements.

---

## 🔗 Live Simulation
You can view and run the interactive simulation of this project directly on Tinkercad:
**[👉 Click Here to Open the Tinkercad Simulation](https://www.tinkercad.com/things/dQmnYFLVLkk-quad-servo-control-system)**

---

## 🛠️ Technical Implementation Process
A structured engineering approach was followed to execute this task:
<img width="1165" height="754" alt="image" src="https://github.com/user-attachments/assets/210e0501-8543-43a1-8b48-ef80410b5063" />


**1. Hardware Setup & Wiring Phase**
* **Power Distribution:** A half-size breadboard was utilized to map shared 5V and GND rails. This ensures the Arduino's internal voltage regulator is protected from the high current draw required by four simultaneous inductive loads.
* **Signal Routing:** The signal wires of the four SG90 servo motors were routed directly to the Arduino's PWM-capable digital pins (3, 5, 6, and 9) to guarantee smooth angular displacement.

**2. Logic & Coding Phase**
* **Time Management:** Standard `delay()` functions freeze the entire system. Instead, the `millis()` function was implemented to track real-time execution like an internal stopwatch.
* **Phase 1 (Sweep):** For the first 2 seconds (2000 ms) of uptime, a `for` loop smoothly sweeps all four motors from 0° to 180° and back.
* **Phase 2 (Hold):** Exactly after the 2-second mark, the condition shifts, and a static 90° angle is permanently written to all motors, locking them safely in their center position.

---

## ⚙️ Core Code Logic (Simplified)
Below is the simplified, highly readable core logic used to drive the servos based on system uptime:

```cpp
#include <Servo.h>

// Initialize 4 servos
Servo s1, s2, s3, s4;

void setup() {
  // Attach servos to PWM pins
  s1.attach(3); s2.attach(5); s3.attach(6); s4.attach(9);
}

void loop() {
  // Start an internal stopwatch (milliseconds)
  unsigned long time = millis(); 

  // Check if less than 2 seconds (2000 ms) have passed
  if (time < 2000) {
    // Sweep all motors from 0 to 180 and back
    for(int p = 0; p <= 180; p += 2) { 
      s1.write(p); s2.write(p); s3.write(p); s4.write(p); delay(10); 
    }
    for(int p = 180; p >= 0; p -= 2) { 
      s1.write(p); s2.write(p); s3.write(p); s4.write(p); delay(10); 
    }
  } 
  // After 2 seconds have passed
  else {
    // Stop sweeping and lock all motors at 90 degrees
    s1.write(90); s2.write(90); s3.write(90); s4.write(90);
  }
}
