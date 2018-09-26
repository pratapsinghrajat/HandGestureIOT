int rnum=0;
int rdel=0;
int l=13;

int l2=12;
int l3=11;
void setup() 
{
randomSeed(analogRead(0));
pinMode(l,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
 rnum=random(3,11);
 rdel=random(25,300);
digitalWrite(l,HIGH);
digitalWrite(l2,HIGH);
digitalWrite(l3,HIGH);
delay(rnum);
digitalWrite(l,LOW);
digitalWrite(l2,LOW);
digitalWrite(l3,LOW);
delay(rdel);
}
