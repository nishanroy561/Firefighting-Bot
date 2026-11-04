# Firefighting Bot

An Arduino robot that finds a flame and sprays it with water.

**Demo video:** [Watch on YouTube](https://youtube.com/shorts/WLKGPGwkYAA)

## Operation

1. The robot reads three flame sensors (left, middle, right).
2. A lower sensor value shows a stronger flame.
3. The robot turns or moves toward the sensor that shows a flame.
4. The servo points the nozzle in the same direction (right 45°, center 90°, left 135°).
5. When the flame is close, the robot stops and the pump starts.
6. When no flame is found, the robot stops and the pump stays off.

## Parts

- Arduino board
- 3 analog flame sensors
- Dual H-bridge motor driver
- 2 DC drive motors
- Servo motor (aims the nozzle)
- DC water pump (switches on when pin A5 is LOW)
- Battery pack and chassis

## Connection diagram

![Connection diagram](wiring-diagram.png)

## Pin connections

| Function | Pin |
|---|---|
| Motor A: enable, in1, in2 | 5, 6, 7 |
| Motor B: enable, in3, in4 | 10, 8, 9 |
| Right flame sensor | A0 |
| Middle flame sensor | A1 |
| Left flame sensor | A2 |
| Servo | A4 |
| Pump | A5 |

## Installation

1. Connect the parts as shown in the connection diagram and the pin table.
2. Open `Fire_bot.ino` in the Arduino IDE.
3. Upload the sketch to the board.
4. Open the Serial Monitor and set the speed to 9600 baud.
5. Read the sensor values on the screen.

## Adjustment

Two values in `loop()` set the sensor limits:

- `thrash` (900): the robot detects a flame below this value.
- `hold` (300): the flame is close. The robot stops and the pump starts.

Change these values to match your sensors and the light in the room.

## Limitations

- The robot has no obstacle avoidance.
- The software does not filter the sensor signal.
- The threshold values are fixed. Ambient light can change the sensor readings.
- The right sensor has priority. The software does not compare the three readings.
- The project did not reach a finished state.

## What this project covers

- Reading analog sensors.
- Driving two DC motors with an H-bridge driver.
- Controlling a servo and a water pump from one Arduino.
- Debugging with serial output.

## Possible improvements

- Calibrate the sensors and filter the readings.
- Add an ultrasonic sensor for obstacle avoidance.
- Use proportional steering instead of fixed left and right turns.
