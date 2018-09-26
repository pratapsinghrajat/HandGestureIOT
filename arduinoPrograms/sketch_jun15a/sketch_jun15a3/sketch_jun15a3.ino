int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

int unit_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

                          
                                       
//function header
void Num_Write(int);

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
  
 
}
int n=9;
void loop() 
{
  
  //counter loop
  
  for (int counter = 10; counter > 0; counter--) 
  {
   //delay(100);
   
   digitalWrite(13,LOW);
   Num_Write(counter-1);
   
   
 
  for(int i=10;i>0;i--)
   {
    digitalWrite(12,LOW);
    delay(500);digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    
   Num_Write(i-1);
   
  }
   //delay(50); 
   
   }
  delay(800);
}

// this functions writes values to the sev seg pins  
void Num_Write(int number) 
{
  
   
   
   int pin2=2;
   for(int i=0;i<7;i++)
   {digitalWrite(pin2, unit_array[number][i]);
   pin2++;}
  
}
