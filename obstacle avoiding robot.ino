#include<Servo.h>
Servo m; 
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance,cdistance,rdistance,ldistance;
int in1 =8;  //Right motor pole 1
int in2 =9 ; //Right motor pole 2
int in3=10;//left motor pole 1
int in4=11;  //left motor pole 1
void setup() {
  m.attach(4);
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() {
cdistance=ultrasonic();
if(cdistance>12)
forward();
{
stopx();
servox();
if(rdistance>ldistance){
right();
delay(500);
}
else{
left();
delay(500);
}
}
}

 void servox(){
       for(int x = 90; x <= 180; x++)  
  {                                  
    m.write(x);               
    delay(10); 
    if(x==180){
      delay(500);
      ldistance=ultrasonic();
      }                
  } 
     for(int x = 180; x >= 0; x--)  
  {                                  
    m.write(x); 
      if(x==0){
      delay(500);
      rdistance=ultrasonic();
      }                          
    delay(10);                 
  } 
    for(int x = 0; x <= 90; x++)  
  {                                  
    m.write(x);               
    delay(10);                 
  } 
  }
  int ultrasonic(void)
{
  distance=0;
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return distance;
}
void backward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void forward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void  left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void stopx(){
   digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(110);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
