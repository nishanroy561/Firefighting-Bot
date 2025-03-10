#include <Servo.h>  // Include the Servo library

// Define motor control pins
const int enA = 5; // Enable pin for motor A
const int in1 = 6; // Input pin 1 for motor A
const int in2 = 7; // Input pin 2 for motor A
const int enB = 10; // Enable pin for motor B
const int in3 = 8; // Input pin 1 for motor B
const int in4 = 9; // Input pin 2 for motor B

// Flame sensor pins
#define AO_PIN A0  // Arduino's pin connected to AO pin of the flame sensor
#define A1_PIN A1  // Arduino's pin connected to the middle flame sensor
#define A2_PIN A2  // Arduino's pin connected to the left flame sensor
#define SERVO_PIN A4 // Arduino's pin connected to the servo
#define PUMP_PIN A5  // Arduino's pin connected to the DC pump

Servo myServo;  // Create a Servo object

void setup() {
    // Set motor control pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    // Initialize pump and servo
    pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, HIGH); // Ensure the pump is off initially
    myServo.attach(SERVO_PIN);  // Attach the servo to the defined pin

    // Initialize serial communication for flame sensor
    Serial.begin(9600);
}

void loop() {
    // Read flame sensor values
    int thrash = 900;
    int hold = 300;
    int flameValueRight = analogRead(AO_PIN);
    int flameValueMiddle = analogRead(A1_PIN);
    int flameValueLeft = analogRead(A2_PIN);

    // Print the flame values for debugging
    Serial.print("Right: ");
    Serial.print(flameValueRight);
    Serial.print(" Middle: ");
    Serial.print(flameValueMiddle);
    Serial.print(" Left: ");
    Serial.println(flameValueLeft);

    // Check the right flame sensor value
    if (flameValueRight < thrash) {
        myServo.write(45);  // Turn servo to the right
        turnRight();  // Turn right if flame is detected on the right
        if (flameValueRight < hold) {
            stopMotors(); // Stop motors when flame is detected
            digitalWrite(PUMP_PIN, LOW); // Turn on the DC pump
        } else {
            digitalWrite(PUMP_PIN, HIGH); // Turn off the DC pump if no flame detected
        }
    } else if (flameValueMiddle < thrash) {
        myServo.write(90);  // Center servo position
        moveForward(); // Move forward if flame is detected in the middle
        if (flameValueMiddle < hold) {
            stopMotors();
            digitalWrite(PUMP_PIN, LOW); // Turn on the DC pump
        } else {
            digitalWrite(PUMP_PIN, HIGH); // Turn off the DC pump if no flame detected
        }        
    } else if (flameValueLeft < thrash) {
        myServo.write(135);  // Turn servo to the left
        turnLeft(); // Turn left if flame is detected on the left
        if (flameValueLeft < hold) {
            stopMotors(); // Stop motors when flame is detected
            digitalWrite(PUMP_PIN, LOW); // Turn on the DC pump
        } else {
            digitalWrite(PUMP_PIN, HIGH); // Turn off the DC pump if no flame detected
        }        
    } else {
        stopMotors(); // Stop if no flame is detected
        digitalWrite(PUMP_PIN, HIGH); // Ensure pump is off if no flame detected
    }
}

// Function to move forward
void moveForward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255); // Set speed for motor A
    analogWrite(enB, 255); // Set speed for motor B
}

// Function to turn right
void turnRight() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 255); // Set speed for motor A
    analogWrite(enB, 0);    // Stop motor B
}

// Function to turn left
void turnLeft() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 0);    // Stop motor A
    analogWrite(enB, 255); // Set speed for motor B
}

// Function to stop motors
void stopMotors() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Stop motor A
    analogWrite(enB, 0); // Stop motor B
}
