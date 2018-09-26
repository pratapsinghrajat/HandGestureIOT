#include <LiquidCrystal.h>
#include<stdio.h>
//#include<String.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,10,11,12,13);
//for(int i=0;i<6;i++)
char pass[]="123456";
//int len=pass.length();
char inp[6];
int i=0;
int k=0;

while(pass[i] != '\0')
{
if(inp[i]==pass[i])
{
if(i==6)
lcd.println("PASS MATCHED");
delay(500);
i++;
lcd.clear();
}
else
{
lcd.println("WRONG PASS"); 
delay(500);
}
}
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
for(int i=0;i<4;i++)
pinMode(i,OUTPUT);
for(int i=4;i<8;i++)
pinMode(i,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<8;i++) 
   digitalWrite(i,HIGH);      //all ip/op high at once !
  
    
    while(1)
  {
 digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  if(digitalRead(4)==0)
    {
     inp[i]= 7 ;
      break;
     
    }
     if(digitalRead(5)==0)
    {
     inp[i]= 8 ;
      break;
      
    }
     if(digitalRead(6)==0)
    {
      inp[i]= 9 ;
      break;
    }
     if(digitalRead(7)==0)
    {
      lcd.println("ERROR");
        delay(100);
      lcd.clear();
     break;
    }



//*******************************************************//


    
   digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  if(digitalRead(4)==0)
    {
       inp[i]= 6 ;
      break;
    }
     if(digitalRead(5)==0)
    {
       inp[i]= 5 ;
      break;
    }
     if(digitalRead(6)==0)
    {
      inp[i]= 4 ;
      break;
    } if(digitalRead(7)==0)
    {
      lcd.println("ERROR");
        delay(100);
      lcd.clear();
     break;
    }
    


//*******************************************************//
    
   digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);

  if(digitalRead(4)==0)
    {
       inp[i]= 3 ;
      break;
    }
     if(digitalRead(5)==0)
    {
      inp[i]= 2 ;
      break;
    }
     if(digitalRead(6)==0)
    {
     inp[i]= 1 ;
      break;
    }
     if(digitalRead(7)==0)
    {
      lcd.println("ERROR");
        delay(100);
      lcd.clear();
     break;
    }


//*******************************************************//

  
    digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);

  if(digitalRead(4)==0)
    {
      lcd.println("Enter password ");
        delay(1000);
      lcd.clear();
      break;
    }
     if(digitalRead(5)==0)
    {
     inp[i]= 0 ;
      break;
    }
     if(digitalRead(6)==0)
    {
      lcd.println("ERROR");
        delay(100);
      lcd.clear();
      break;
    }
     if(digitalRead(7)==0)
    {
      lcd.println("ERROR");
        delay(1000);
      lcd.clear();
     break;
    }
    delay(100);
  }
    

}
