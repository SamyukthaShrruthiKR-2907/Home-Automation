int lamp = 9;
int sensor = 8;
int led = 10;
unsigned long t=0;
const int trigger = A1;
const int echo = A2;
int vcc = A0;
int gnd = A3;
int OP = 11;
long Time;
float distanceCM;
float distance = 15;  // set threshold distance in cm
float resultCM;

void setup() 
{
  Serial.begin(9600);
  pinMode(OP,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(vcc,OUTPUT);
  pinMode(gnd,OUTPUT);

  pinMode(lamp, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(lamp,HIGH);
  digitalWrite(led,LOW);

  while(millis()<13000)
  {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
  }
  digitalWrite(led,LOW);
  
}


void loop() 
{
  int j=analogRead(A4);
  j=j*0.48;
  digitalWrite(vcc,HIGH);
digitalWrite(gnd,LOW);
digitalWrite(trigger,LOW);
delay(10);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
Time=pulseIn(echo,HIGH);
distanceCM=Time*0.034;
resultCM=distanceCM/2;
if(resultCM<=distance)
{
digitalWrite(OP,HIGH);
delay(10);
}
if(resultCM>=distance)
{
digitalWrite(OP,HIGH);
delay(500);
}
else
{
 digitalWrite(OP,LOW);
 delay(500);
}
delay(10);
  if(j>=27)
  {
    digitalWrite(5,1);
    digitalWrite(6,0);
  }
  else if(j<27)
  {
    digitalWrite(5,0);
    digitalWrite(6,0);
  }

  digitalWrite(lamp,HIGH);
  digitalWrite(led,LOW);
  delay(10);
  t = digitalRead(sensor); 
if (t== HIGH)
{ 
digitalWrite(lamp, HIGH); 
delay(200);
} 
else {
digitalWrite(lamp, LOW); 
delay(200);
      }
   }
