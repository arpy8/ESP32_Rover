#include <SoftwareSerial.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

// bool is_on = false;

// MOTOR PINS
int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;

// // BLUETOOTH CONFIGURATION
// SoftwareSerial bluetooth(11, 12);  // RX, TX

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  
  pinMode(13, OUTPUT);
  
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }

}

void executeCommand(char command) {
  // if (command==START)
  //   is_on = true;
  Serial.println(command);
  switch (command) {
    case FORWARD:
      moveFwd(255);
      break;
    case BACKWARD:
      moveBwd(255);
      break;
    case LEFT:
      moveLft(255);
      break;
    case RIGHT:
      moveRgt(255);
      break;
    case CIRCLE:
      moveRgt(127);
      break;
    case CROSS:
      moveBwd(127);
      break;
    case TRIANGLE:
      moveFwd(127);
      break;
    case SQUARE:
      moveLft(127);
      break;
    // case START:
    //   is_on = true;
    //   break;
    // case PAUSE:
    //   is_on = false;
    //   break;
    default:
      stopMotor();
      break;
  }
}



//   // Bluetooth setup
//   bluetooth.begin(9600);
// }

// void loop() {
//   digitalWrite(13, HIGH);

//   // Check Bluetooth input
//   if (bluetooth.available() > 0) {
//     char key = bluetooth.read();
  
//     if (key != NO_KEY) {
//       switch (key) {
//         case 'F':  // Move forward
//           moveFwd();
//           break;
//         case 'B':  // Move backward
//           moveBwd();
//           break;
//         case 'L':  // Move left
//           moveLft();
//           break;
//         case 'R':  // Move right
//           moveRgt();
//           break;
//         case 'S':  // Stop
//           stopMotor();
//           break;
//       }
//     }
//   }


// Motor control functions
void moveFwd(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, speed);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, speed);
}

void moveBwd(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, speed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, speed);
}

void moveLft(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, speed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, speed);
}

void moveRgt(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, speed);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, speed);
}

void stopMotor() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}