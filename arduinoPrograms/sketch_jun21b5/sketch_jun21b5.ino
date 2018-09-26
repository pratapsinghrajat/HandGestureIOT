int arr1[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

int arr[10][7] = {        { 0,0,0,0,0,0,1 },    // 0
                          { 1,0,0,1,1,1,1 },    // 1
                          { 0,0,1,0,0,1,0 },    // 2
                          { 0,0,0,0,1,1,0 },    // 3
                          { 1,0,0,1,1,0,0 },    // 4
                          { 0,1,0,0,1,0,0 },    // 5
                          { 0,1,0,0,0,0,0 },    // 6
                          { 0,0,0,1,1,1,1 },    // 7
                          { 0,0,0,0,0,0,0 },    // 8
                          { 0,0,0,1,1,0,0 }};   // 9
void setup() 
{ 
  // set pin modes
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //digitalWrite(12,HIGH);
 // digitalWrite(13,HIGH);
 
}
int pin=2;int c=0;
void loop() 
{
  
  //counter loop
  
  for (int i = 0; i <10; i++) 
  {
   for (int j = 0; j <=i; j++)
    {
      for(int x=0;x<40;x++)
      {
      pin=2;
     
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
     
        for (int m = 0; m < 7; m++)
        {
          digitalWrite(pin,arr1[i][m]);
          pin++;
          c++;
        }
        delay(15);
        pin=2;
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);

      //for(int k=0;k<=c;k++)
     {
     for (int m = 0; m<7; m++)
        {
          digitalWrite(pin,arr1[j][m]);
          pin++;
        }
     }
        //c=0;
        delay(15);
    }
    }
    
   }
}


