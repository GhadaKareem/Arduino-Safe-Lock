#include <Keypad.h>
#include<Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define redled 11
#define greenled 10
Servo myservo;
String arr="12345";
String master="";
int counter=0;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
int a = 21;  
int b = 20;  
int c = 19;  
int d = 18; 
int e = 17; 
int f = 16;  
int g = 15;
byte rowPins[ROWS] = {25, 26, 27, 28}; 
byte colPins[COLS] = {24, 23, 22}; 

Keypad keypads = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 

void setup(){
  pinMode(greenled,OUTPUT);
   pinMode(redled,OUTPUT);
   myservo.attach(9);
   myservo.write(0);
  Serial.begin(9600);
   lcd.begin(16, 2);
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);  
  pinMode(c, OUTPUT);  
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT);  
  pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);  
  
 
}
  
void loop(){
  char key = keypads.getKey();
  if (key){
    
    if(key=='*')
    {
      if( master == arr )
      {
      lcd.print(" Success! ");
      digitalWrite(greenled,HIGH); 
      myservo.write(90);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
       master="";
      digitalWrite(greenled, LOW);
      }
      else
      {
      counter+=1;
      lcd.print(" Faild!");
      digitalWrite(redled , HIGH);
     displayDigit(counter);
       delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      digitalWrite(redled , LOW);
      master="";
    
     turnOff();
    
      }
    }
    else if(key=='#')
    {
       myservo.write(0);
    }
    else 
    {
      if(master.length() >= 5)
      {
        counter+=1;
        lcd.print("too long");
        digitalWrite(redled , HIGH);
       displayDigit(counter);
       delay(1000);
        master="";
       lcd.clear();
       lcd.setCursor(0, 0);
       turnOff(); 
       digitalWrite(redled , LOW);
       
      }
      else 
      master +=(String)key;
    }
    
  }
 
}
void displayDigit(int digit)
{
  switch ( digit ) {
  case 1:
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    break;
  case 2:
    digitalWrite(g,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    
    break;
    case 3:
    digitalWrite(g,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    
    break;
    case 4:
     digitalWrite(f,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(b,HIGH);
    break;
    case 5:
     digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    break;
    case 6:
     digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(c,HIGH);
    break;
     case 7:
     digitalWrite(g,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(e,HIGH);
    break;
    case 8:
     digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(c,HIGH);
     digitalWrite(f,HIGH);
    break;
  default:
   digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(f,HIGH);
    
}
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
