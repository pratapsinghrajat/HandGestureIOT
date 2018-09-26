//#include <TTS.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,7,6,5,4,3);
//TTS text2speech;
int thumb=A4;
int index=A3;
int middle=A2;
int ring=A1;
int little=A0;
bool flag = true;
bool steadyValue = false;
unsigned long time_old  = 0;
int j = 0;
unsigned int thumb_threshold = 0;
unsigned int index_threshold = 0;
unsigned int middle_threshold = 0;
unsigned int ring_threshold = 0;
unsigned int little_threshold = 0;

int decVal;
char lookupTable[]={97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,121,121,46,121,120,32};
int digiStore[5];
int temp[5];
char words[100];
char string[10];

void calibrate()
{
  lcd.begin(16,2); 
  lcd.setCursor(0,0); 
    lcd.print("GESTURE TO      " );
     lcd.setCursor(0,1); 
    lcd.print("SPEECH CONVERTER" );
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("Bend fingers");
  delay(2000);
  lcd.clear();
  lcd.print("Starting Calibration ....");
   lcd.clear();
  lcd.print("Bend fingers");
  delay(5000);
  int t_low=analogRead(thumb);
  int i_low=analogRead(index);
  int m_low=analogRead(middle);
  int r_low=analogRead(ring);
  int l_low=analogRead(little);
  lcd.clear();
   lcd.setCursor(0,0);
 lcd.print("Un-bend fingers");
  delay(5000);
  int t_high=analogRead(thumb);
  int i_high=analogRead(index);
  int m_high=analogRead(middle);
  int r_high=analogRead(ring);
  int l_high=analogRead(little);

  thumb_threshold = (t_low + t_high)/2;
  index_threshold = (i_low + i_high)/2;
  middle_threshold = (m_low + m_high)/2;
  ring_threshold = (r_low + r_high)/2;
  little_threshold = (l_low + l_high)/2;
  delay(1000);

 // Serial.println("Calibrated values are - ");
  //Serial.println(thumb_threshold);
  //Serial.println(index_threshold);
  //Serial.println(middle_threshold);
  //Serial.println(ring_threshold);
  Serial.print("HELLO WELCOME ");
  delay(1000);
  Serial.print("TO TALKING GLOVE");
 lcd.clear(); 
}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(thumb, INPUT);
 pinMode(index, INPUT);
 pinMode(middle, INPUT);
 pinMode(ring, INPUT);
 pinMode(little, INPUT);
 calibrate();
}

void loop() {
  // put your main code here, to run repeatedly:
//  char sentence[50];
delay(1000);
    int t=analogRead(thumb);
         if(t>=thumb_threshold){
         digiStore[0]=1;
         }
           else{
           digiStore[0]=0;
         };
      int i=analogRead(index);
       if(i>=index_threshold){
         digiStore[1]=1;
       }
           else{
           digiStore[1]=0;
         };
      int m=analogRead(middle);
       if(m>=middle_threshold){
         digiStore[2]=1;
       }
           else{
           digiStore[2]=0;
         };
      int r=analogRead(ring);
         if(r>=ring_threshold){
         digiStore[3]=1;
         }
         else{
         digiStore[3]=0;
         };
     int l=analogRead(little);
       if(l>=little_threshold){
       digiStore[4]=1;
       }
       else{
       digiStore[4]=0;
       };
       if(flag)
       {
        for(int k = 0; k<5; k++)
        {
          temp[k] = digiStore[k];
        }
        flag = false;
        time_old = millis();
       }
       if(!flag)
       {
        if(millis() - time_old > 1100)
        {
          if(temp[0] == digiStore[0] && temp[1] == digiStore[1] && temp[2] == digiStore[2] && temp[3] == digiStore[3] && temp[4] == digiStore[4])
            steadyValue = true;
          else
            steadyValue = false;
          if(steadyValue)
            {
              decVal=16*digiStore[0]+8*digiStore[1]+4*digiStore[2]+2*digiStore[3]+1*digiStore[4];
              //Serial.println(decVal);
              if(j!= 0 && words[j-1] == 32 && decVal == 31)
              {
              }
              else
              {
                words[j]=lookupTable[decVal];
               // Serial.println(words[j]);
               lcd.print(words[j]);
                j++;
                if(decVal == 31)
                {
                for(int k = 0; ;k++)
                {
                  if(words[k]!= 32)
                    Serial.print(words[k]);
                   else
                   {
                    Serial.println("");
                    break;
                   }
                }
               }
               if(decVal == 28)
               {
                for(int k = 0; ;k++)
                {
                  if(words[k]!= 46)
                    Serial.print(words[k]);
                   else
                   {
                    Serial.print(words[k]);
                    
                    words[k+1] = '\0'; 
                    Serial.println("");
                    strcpy(string,words);
                    //text2speech.sayText(string);
                    j = 0;
                    break;
                   }
                }
               }  
              }
             }
             time_old = millis();
             steadyValue = false;
             flag = true;
       }
      }
}

