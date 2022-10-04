
void servoToggle(){
  int doorOpen = EEPROM.read(1);
Serial.println(doorOpen);
  if(doorOpen==0){ //locked
    myservo.write(135);
    analogWrite(slaveArd, 100);//~1-2v
  
    display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Status: UNLOCKED");
  display.setTextSize(3);
   display.println("Come in");
   display.display();
    doorOpen=1;
    EEPROM.write(1,1); // (address,value)
    delay(2000);
  }
  else{
    myservo.write(45);
    analogWrite(slaveArd, 50);//~.5-1v
    
    display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Status: LOCKED");
  display.setTextSize(1.5);
   display.println("Please don't come in");
   display.display();
    doorOpen=1;
    doorOpen=0;
    EEPROM.write(1,0);
    delay(2000);
  }

}
