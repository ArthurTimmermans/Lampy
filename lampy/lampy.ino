/* 
 *  Lampy
 *  
 *  Version: 1.0
 *  
 */

void setup() {

  pinMode(2, OUTPUT); //Status led RED
  pinMode(3, OUTPUT); //Status led YELLOW
  pinMode(4, OUTPUT); //Status led GREEN

  pinMode(5, INPUT); //InfraRed receiver cable

  pinMode(7, INPUT); //Button 1 (On/Off)
  pinMode(8, INPUT); //Button 2 (Browse colors)

  pinMode(9, OUTPUT); // RGB RED
  pinMode(10, OUTPUT); //RGB GREEN
  pinMode(11, OUTPUT); //RGB BLUE

  Serial.begin(9600);
}

void loop() {
  
}
