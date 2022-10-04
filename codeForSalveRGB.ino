//Written by Zack for Engineering Foundations 5/1/2020

int redLED = 6;
int greenLED = 5;
int blueLED = 3;
int redNew = (int)random(0, 255);
int blueNew = (int)random(0, 255);
int greenNew = (int)random(0, 255);
int red, green, blue = 0;
int dataValue;
int count;
int i;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);

}

void loop() {
if(i==155){
    i=0;
    count = 0;
  red = redNew;
  green = greenNew;
  blue = blueNew;
  redNew = (int)random(0, 255);
  greenNew = (int)random(0, 255);
  blueNew = (int)random(0, 255);
  }
analogWrite(9,i);
  i++;
  
  Serial.println(i);
  for(int i = 0;i<50;i++){
  dataValue += analogRead(A0);
  }dataValue/=50;
float voltage = dataValue * (5.0 / 1023.0);
 Serial.print(voltage);
 Serial.println("v");

  if(/*at rest*/ (voltage <.5)&&(voltage>=0)){
    rgbFade();
  }
  if(/*doorLocked*/(voltage>=.5)&&(voltage<1)){
    Serial.println("locked");
    setColor(255,0,0);
    red = 255;
    green=0;
    blue=0;
  }
  if(/*door unlocked*/(voltage>=1)&&(voltage<2.5)){
    setColor(0,255,0);Serial.println("unlock");
    red = 0;
    green=255;
    blue=0;
  }
  if(/*incorect finger*/(voltage>=2.5)&&(voltage<3)){
    
    Serial.println("incorrect finger");
    for(int i=0;i<3;i++){
    setColor(255,0,0);
    delay(250);
    setColor(0,0,0);
    delay(250);
    red = 255;
    green=0;
    blue=0;
    }
  }
  delay(100);
}


void whiteFade() {
  Serial.println("White Fade");
  for (int i = 0; i < 255; i++) {
    analogWrite(redLED, i);
    analogWrite(greenLED, i);
    analogWrite(blueLED, i);
    delay(10);
    Serial.println(i);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(redLED, i);
    analogWrite(greenLED, i);
    analogWrite(blueLED, i);
    delay(10);
    Serial.println(i);
  }
}

void rgbFlash() {
  Serial.println("rgb flash");
  analogWrite(redLED, (int)random(0, 255));
  analogWrite(greenLED, (int)random(0, 255));
  analogWrite(blueLED, (int)random(0, 255));
  delay(500);
}
void rgbFade() {
  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.println(blue);
   dataValue = analogRead(A0);
float voltage = dataValue * (5.0 / 1023.0);
  if(voltage<1){
  Serial.println("rgb fade");
  //if(i == 0){
    //------------------------------------
 // }
  if (red < redNew) {
    analogWrite(redLED, red);
    red++;
    delay(10);
  }
  if (red > redNew) {
    analogWrite(redLED, red);
    red--;
    delay(10);
  }
  //--
  if (green < greenNew) {
    analogWrite(greenLED, green);
    green++;
    delay(10);
  }
  if (green > greenNew) {
    analogWrite(greenLED, green);
    green--;
    delay(10);
  }
  //--
  if (blue < blueNew) {
    analogWrite(blueLED, blue);
    blue++;
    delay(10);
  }
  if (blue > blueNew) {
    analogWrite(blueLED, blue);
    blue--;
    delay(10);
  }
  
}
delay(10);
}

void setColor(int red, int green, int blue) {
  Serial.println("set color");
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
}