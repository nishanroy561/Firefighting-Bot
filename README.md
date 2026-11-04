# Firefighting Bot

An Arduino-based autonomous firefighting robot that detects flames using infrared flame sensors, navigates toward the detected fire, and activates a water pump to extinguish it.

## Demo

[![Watch Demo on YouTube](https://img.youtube.com/vi/WLKGPGwkYAA/maxresdefault.jpg)](https://youtube.com/shorts/WLKGPGwkYAA)

**[Watch the Demo Video](https://youtube.com/shorts/WLKGPGwkYAA)**

## How It Works

The robot uses three analog flame sensors positioned at the front to detect the direction of a flame.

1. **Flame Detection:** Three sensors continuously monitor the left, middle, and right directions.
2. **Direction Detection:** Lower analog readings indicate stronger flame detection.
3. **Navigation:** The Arduino controls two DC motors through a dual H-bridge motor driver to move toward the detected flame.
4. **Nozzle Positioning:** A servo motor adjusts the water nozzle according to the detected direction:
   - Right: 45°
   - Center: 90°
   - Left: 135°
5. **Fire Extinguishing:** When the flame reading reaches the close-range threshold, the robot stops and activates the water pump.
6. **Idle State:** When no flame is detected, the robot stops and keeps the pump off.

## Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Main controller |
| Analog IR flame sensors | 3 | Flame detection |
| Dual H-bridge motor driver | 1 | DC motor control |
| DC geared motors | 2 | Robot movement |
| SG90 servo motor | 1 | Nozzle positioning |
| DC water pump | 1 | Water spraying |
| Battery pack | 1 | Power supply |
| Robot chassis | 1 | Mechanical assembly |

## Connection Diagram

<p align="center">
  <img src="bot%20connections.png" alt="Firefighting Bot Hardware Connection Diagram" width="850">
</p>

*Arduino wiring connections. Battery and motor power wiring are not shown.*

## Pin Configuration

### Flame Sensors

| Sensor | Arduino Pin |
|---|---|
| Right | A0 |
| Middle | A1 |
| Left | A2 |

### Motor Driver (Dual H-Bridge)

| Function | Arduino Pin |
|---|---|
| ENA | D5 |
| IN1 | D6 |
| IN2 | D7 |
| ENB | D10 |
| IN3 | D8 |
| IN4 | D9 |

### Other Outputs

| Component | Arduino Pin | Description |
|---|---|---|
| Servo motor | A4 | Nozzle positioning |
| Water pump | A5 | Active LOW |

**Pump control:** Setting A5 to LOW activates the water pump. Setting it HIGH keeps the pump off.

## Installation and Setup

1. Clone the repository:

   ```bash
   git clone https://github.com/nishanroy561/Firefighting-Bot.git
   ```

2. Open the project directory:

   ```bash
   cd Firefighting-Bot
   ```

3. Open `Fire_bot.ino` in the Arduino IDE.
4. Connect the Arduino board to your computer.
5. Select the appropriate board and COM port.
6. Upload the sketch.
7. Open the Serial Monitor and set the baud rate to **9600**.
8. Observe the sensor readings and test the robot.

## Sensor Calibration

The detection logic uses two threshold values defined in `loop()`:

| Parameter | Default Value | Purpose |
|---|---:|---|
| `thrash` | 900 | Flame detection threshold |
| `hold` | 300 | Close-range flame threshold |

- When a sensor reading falls below `thrash`, the robot detects a flame.
- When the reading falls below `hold`, the robot stops and activates the pump.

These values may require adjustment depending on sensor sensitivity, ambient lighting, and operating conditions.

## Known Limitations

This project is an experimental prototype and has several limitations:

- **No obstacle avoidance:** The robot cannot detect or navigate around obstacles.
- **No sensor filtering:** Raw analog readings are used without signal smoothing.
- **Fixed thresholds:** Detection thresholds are not calibrated automatically.
- **Sensor priority:** The right sensor has priority. The software does not independently compare all three readings to identify the strongest flame.
- **Incomplete implementation:** The project did not reach a fully finished autonomous firefighting system.

## Possible Improvements

- Implement automatic flame sensor calibration.
- Add moving-average or other filtering techniques to reduce sensor noise.
- Introduce ultrasonic sensors for obstacle detection and avoidance.
- Implement proportional steering based on sensor readings.
- Improve flame direction estimation by comparing all three sensor values.
- Add battery voltage monitoring.
- Improve nozzle positioning and water distribution.

## What I Learned

This project explores several embedded systems and robotics concepts:

- Analog sensor interfacing and signal acquisition.
- DC motor control using a dual H-bridge driver.
- Servo motor positioning using PWM.
- Controlling external actuators through digital outputs.
- Serial communication and hardware debugging.
- Integrating multiple hardware components into a single Arduino-based system.

## Repository Structure

```text
Firefighting-Bot/
├── Fire_bot.ino
├── bot connections.png
└── README.md
```

## License

This project is available for educational and experimental purposes.
