

#include <LiquidCrystal.h>
#include <Servo.h>

const int button=3 ;


const int rs = A0, e = A1, D4 = A2, D5 = A3, D6 = A4, D7 = A5;
LiquidCrystal lcd(rs, e, D4, D5, D6, D7);

int a=1;
Servo myServo;


long starttime;
long rpin;


void setup() {
  myServo.attach(2);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(button,INPUT);
  myServo.write(0);
  lcd.print("Press any key to unlock");
  
}
void loop(){
  lcd.print("Press any key to unlock");
  while(a){
  while (Serial.available() == 0) {}  
  String key = Serial.readString();
  if (key){
    key="";
    myServo.write(90); 
    lcd.clear();  
    lcd.setCursor(0,0);                             //Unlocked state
    lcd.print("Unlocked! ");
    lcd.setCursor(0,1);
    lcd.print("Open the lid ");
  while(a){
    delay(100);
      if (digitalRead(button)==LOW){
        lcd.clear();  
        lcd.setCursor(0,0);                             
        lcd.print("Put package in ");
        lcd.setCursor(0,1);
        lcd.print("Close the lid ");}
        else {
            continue;
          }
  while(a){
        if (digitalRead(button)==HIGH){
          lcd.clear();  
          lcd.setCursor(0,0);                            
          lcd.print("Press any key ");
          lcd.setCursor(0,1);
          lcd.print("to lock ");
          starttime=millis();}
          else {
            continue;
          }
    while(a){
     while (Serial.available() == 0) {}  
     String key = Serial.readString();
          if (key!="" || ((millis()-starttime)>30000)){
            myServo.write(0);
            lcd.clear();  
            lcd.setCursor(0,0);                             //Locked state
            lcd.print("Locked!");
            lcd.setCursor(0,1);
            lcd.print("Thank you");
            rpin=random(10001,100000);
            Serial.println("Package received.\nYour one time pin is: "+String(rpin));
            delay(5000);
            a=0;enterpin();
            
            
          }
    }
    }
  }
  }
}
}
void enterpin(){
  int a=1;
  lcd.clear();
  lcd.print("Enter pin");
  String pin;
  while(a){
  while (Serial.available() == 0) {}  
  String key = Serial.readString();
  pin=key;
  
  if (key){
  String gpin=String(rpin)+"\n";
      if (String(pin)==String(gpin)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct pin");
      myServo.write(90);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Retrive your");
      lcd.setCursor(0,1);
      lcd.print("     package   ");
      }
      else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Wrong! Try Again");
      pin="";
      
       }}
   
    else{
      lcd.setCursor(0,1);
      lcd.print("Use number only");}
      
  }}
