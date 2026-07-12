readme_content = """# 🚀 Quad-Servo Control System

## 📄 Project Overview

This project constitutes a practical submission for the assigned task under the Smart Methods Summer Training 2026 program. The primary objective was to design, wire, and simulate an embedded control system using an Arduino Uno to synchronously operate four micro servo motors. The system focuses on safe power distribution and non-blocking time management to execute precise mechanical movements.

---

## 🛠️ Technical Implementation Process
<img width="823" height="461" alt="Screenshot 2026-07-12 055136" src="https://github.com/user-attachments/assets/49768c76-ddcb-47de-a01b-54dbb1532786" />


A structured engineering approach was followed to execute this task:

**1. Hardware Setup & Wiring Phase**
* **Power Distribution:** A half-size breadboard was utilized to map shared 5V and GND rails. This ensures the Arduino's internal voltage regulator is protected from the high current draw required by four simultaneous inductive loads.
* **Signal Routing:** The signal wires of the four SG90 servo motors were routed directly to the Arduino's PWM-capable digital pins (3, 5, 6, and 9) to guarantee smooth angular displacement.

**2. Logic & Coding Phase**
* **Time Management:** Standard `delay()` functions freeze the entire system. Instead, the `millis()` function was implemented to track real-time execution like an internal stopwatch.
* **Phase 1 (Sweep):** For the first 2 seconds (2000 ms) of uptime, a `for` loop smoothly sweeps all four motors from 0° to 180° and back.
* **Phase 2 (Hold):** Exactly after the 2-second mark, the condition shifts, and a static 90° angle is permanently written to all motors, locking them safely in their center position.

**3. Simulation & Deployment**
* **Verification:** The entire circuit architecture and firmware were simulated and verified using Tinkercad Circuits, confirming the exact timing and mechanical synchronization before any physical deployment.

---

## ⚙️ Core Code Logic (Simplified)

Below is the simplified, highly readable core logic used to drive the servos based on system uptime:
<img width="429" height="751" alt="Screenshot 2026-07-12 055114" src="https://github.com/user-attachments/assets/06ee550f-2a5e-41b4-a03d-42b06f2b96ac" />
