#include <Servo.h>
Servo servoMotor;
int servoPin = 6;    
int IRSensor = 9; 
int stepDelay = 10;
int leftM=3;
int reightM=4;
int MV=5;
int sensorStatus = 1;
bool fire = false;
bool leftF = false;
bool reightF = false;
bool forwardF =false;
void setup(){
 
  pinMode(IRSensor, INPUT);
  pinMode(leftM, OUTPUT); 
  pinMode(reightM, OUTPUT); 
  pinMode(MV, OUTPUT);
  servoMotor.attach(servoPin);
}

void forward()
{
  digitalWrite(leftM,HIGH);
  digitalWrite(reightM,HIGH);
  delay(300);
  digitalWrite(leftM,LOW);
  digitalWrite(reightM,LOW);

}
void left()
{
  digitalWrite(reightM,HIGH);
  delay(210);
  digitalWrite(reightM,LOW);
}
void right()
{
  digitalWrite(leftM,HIGH);
  delay(210);
  digitalWrite(leftM,LOW);
}
void putOutTheFire()
{
  digitalWrite(MV,HIGH);
  delay(3000);
  digitalWrite(MV,LOW);
  
  leftF = false;
  reightF = false;
  forwardF =false;
}

void loop(){
    servoMotor.write(90);  // pstavuvanje na senzorot na sredina
    delay(1000);
    int sensorStatus1 = digitalRead(IRSensor); // Set the GPIO as Input
    if(sensorStatus1 == 0)
    {
      forwardF=true;
        forward();
      putOutTheFire();
    }
    
    servoMotor.write(15);
     delay(1000);
    int sensorStatus2 = digitalRead(IRSensor); // Set the GPIO as Input
    if(sensorStatus2 == 0)
    {
      
         right();
         reightF= true;
    }
   
     servoMotor.write(90);  // pstavuvanje na senzorot na sredina
      delay(1000);
    int sensorStatus3 = digitalRead(IRSensor); // Set the GPIO as Input
    if(sensorStatus3 == 0)
    {
        forward();
        putOutTheFire();
    }
    
     servoMotor.write(165);  // pstavuvanje na senzorot na sredina
     delay(1000);
     int sensorStatus4 = digitalRead(IRSensor); // Set the GPIO as Input
    if(sensorStatus4 == 0)
    {
       
        left();
        leftF = true;
    }
       
    if(leftF==false&& reightF == false&& forwardF==false)
    {
      forward();
    }

}

