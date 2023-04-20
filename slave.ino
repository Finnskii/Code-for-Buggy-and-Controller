#define button 8
#define serv7 7
#define mag 6
#define back5 5
#define for4 4
#define right3 3
#define left2 2



int buttonState = 0;
int leftState = 0;
int rightState = 0;
int forwState = 0;
int backState = 0;


void setup() {
  pinMode(button, INPUT);
  pinMode(left2, INPUT);
  pinMode(right3, INPUT);
  pinMode(for4, INPUT);
  pinMode(back5, INPUT);
  //pinMode(button, INPUT);
  
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 // Reading the button
  buttonState = digitalRead(button);
  leftState = digitalRead(left2);
  rightState = digitalRead(right3);
  forwState = digitalRead(for4);
  backState = digitalRead(back5);
 if (buttonState == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on LED
  
 }
  else if(leftState == HIGH){
    Serial.write('2');
  }

   else if(rightState == HIGH){
    Serial.write('3');
  }
   else if(forwState == HIGH){
    Serial.write('4');
  }
   else if(backState == HIGH){
    Serial.write('5');
  }
   
 else {
   Serial.write('0');
   
 }  
 /*


the addition below clears the serial bus by waiting until data is output
then ends the serial berfor opening it again to clear it

it needs to be on the send area as this is where all the data is written
when written on the master board, the buggy would not move, possibly due to deleting the serial before it is read but deleting it on the slave works soooooo

*/
  Serial.flush();
  Serial.end();
  Serial.begin(38400);

}