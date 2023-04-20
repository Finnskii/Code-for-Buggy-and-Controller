#define ledPin 8
#define IN1 5
#define IN2 4
#define IN3 3
#define IN4 2
#define Servopin 6
#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left servo signal
Servo servoRight;     
char state = 0;
bool Toggle = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);
  digitalWrite(ledPin, LOW);
  pinMode(IN1,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(Servopin, OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
  
  
}

void loop() {
  
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED

  
  if(state =='0'){
   // digitalWrite(ledPin, LOW); // LED ON
    servoLeft.writeMicroseconds(1500);         // stop
    servoRight.writeMicroseconds(1500);
    state = 0;
    
  }
  else if(state =='1'){
    if (Toggle == false){    
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Toggle = true ; 
      digitalWrite(Servopin, HIGH)  ;        
      }
    else if (Toggle == true){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(Servopin, LOW);
      Toggle = false;
    }
    //digitalWrite(ledPin, HIGH); // LED ON
    state = 0;
  }
  else if(state == '2'){//left
    servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
    servoRight.writeMicroseconds(1300);
    state = 0;
  }  
  else if(state == '3'){//Right
    servoLeft.writeMicroseconds(1700);         // 1.7 ms -> counterclockwise
    servoRight.writeMicroseconds(1700);
    state = 0;
  }  
  else if(state == '4'){//Forwards
    servoLeft.writeMicroseconds(1700);         // 1.7 ms -> counterclockwise
      servoRight.writeMicroseconds(1300);
    state = 0;
  }  
  else if(state == '5'){//Backwards
    servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
      servoRight.writeMicroseconds(1700);
    state = 0;
  } 
 /*   
 

*/

 }







