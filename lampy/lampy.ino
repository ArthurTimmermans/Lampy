/* 
 *  Lampy
 *  
 *  Version: 1.0
 *  
 */

  int disablePin = 7;  
  int disableReading;
  
void setup() {

  pinMode(2, OUTPUT); //Status led RED
  pinMode(3, OUTPUT); //Status led YELLOW
  pinMode(4, OUTPUT); //Status led GREEN

  pinMode(5, INPUT); //InfraRed receiver cable

  pinMode(disablePin, INPUT); //Switch 1 (Disable lampy)
  pinMode(8, INPUT); //Button 2 (Browse colors)

  pinMode(9, OUTPUT); // RGB RED
  pinMode(10, OUTPUT); //RGB GREEN
  pinMode(11, OUTPUT); //RGB BLUE

  Serial.begin(9600);
}

void loop() {
  disableReading = digitalRead(disablePin);  
  if(disableReading == HIGH){
  //Everything is disabled
  }else{
  //Everything is enabled
        
  }

}
