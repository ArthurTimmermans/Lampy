/* 
 *  Lampy
 *  
 *  Version: 1.0
 *  
 */

  int disablePin = 7;  
  int disableReading;

  int statusRedPin = 2;
  int statusGreenPin = 4;

  int ledRed = 9;
  int ledGreen = 10;
  int ledBlue = 11;

  int buttonPagePin = 8;
  int buttonPage = 0;
  int buttonAmountPages = 3;
  int buttonState = 0;
  int lastButtonState = 0;
  
  
void setup() {

  pinMode(statusRedPin, OUTPUT); //Status led RED
  pinMode(13, OUTPUT); //Status led YELLOW
  pinMode(statusGreenPin, OUTPUT); //Status led GREEN

  pinMode(5, INPUT); //InfraRed receiver cable

  pinMode(disablePin, INPUT); //Switch 1 (Disable lampy)
  pinMode(buttonPagePin, INPUT); //Button 2 (Browse colors)

  pinMode(ledRed, OUTPUT); // RGB RED
  pinMode(ledGreen, OUTPUT); //RGB GREEN
  pinMode(ledBlue, OUTPUT); //RGB BLUE

  Serial.begin(9600);
}

void loop() {
  disableReading = digitalRead(disablePin);  
  if(disableReading == HIGH){
    //Everything is disabled
    digitalWrite(statusRedPin, HIGH);
    digitalWrite(statusGreenPin, LOW);
  }else{
    //Everything is enabled
    digitalWrite(statusRedPin, LOW);
    digitalWrite(statusGreenPin, HIGH);

    buttonState = digitalRead(buttonPagePin);

    if(buttonState != lastButtonState){
      if(buttonState == HIGH){
        if(buttonPage < buttonAmountPages){
          buttonPage++;
        }else{
          buttonPage = 0;
        }
        Serial.print(buttonPage);
        resetLights();
      }
      delay(50); //avoid bouncing
    }
    lastButtonState = buttonState;
    lightScene(buttonPage);
  }

}

void resetLights(){
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  for(int resetRGB = 9; resetRGB < 12; resetRGB++){
    digitalWrite(resetRGB, LOW);
  }
  digitalWrite(13, LOW);
}

void lightScene(int page){
  switch(page){
    case 0:
      // nothing
      break;
    case 1:
      // Red Light
      resetLights();
      digitalWrite(ledRed, HIGH);
      break;
    case 2:
      resetLights();
      digitalWrite(ledGreen, HIGH);
      break;
    case 3:
      resetLights();
      digitalWrite(ledBlue, HIGH);
      break;
  }
}

