int arr[8]={13,12,11,10,9,8,7,6};

void setup()
{
  // put your setup code here, to run once:
  for(int i=0;i<8;i++)
  pinMode(arr[i],OUTPUT);

}

void loop()   
{
 
    for(int j=0;j<8;j++ )
    {
      if(j<4)
      {
      digitalWrite(arr[j],HIGH);
      //delay(1000);
      }
    else
      {
        digitalWrite(arr[j],LOW);
        delay(1000);
      }
      
  }

  delay(1000);
    for(int k=0;k<8;k++)
      {
      if(k%2==0)
      {digitalWrite(arr[k],LOW);
      
      }
      else
      {digitalWrite(arr[k],HIGH);
      
      }
      
      }
      delay(1000);

      
    for(int j=0;j<8;j++ )
    {
      if(j<4)
    {digitalWrite(arr[j],LOW);
    //delay(1000);
    }
    else
    {digitalWrite(arr[j],HIGH);
    //delay(1000);
    }
    
    }

    delay(1000);
    for(int j=0;j<8;j++ )
      {
      digitalWrite(arr[j],HIGH);
      //delay(1000);
      } 

      delay(1000);
    for(int k=0;k<8;k++)
    {
      if(k%2!=0)
      {digitalWrite(arr[k],LOW);
      //delay(1000);
      }
      else
      {digitalWrite(arr[k],HIGH);
     // delay(1000);
     }

     }
     delay(1000);
    for(int l=0;l<8;l++ )
      {
      digitalWrite(arr[l],LOW);
      //delay(1000);
      
      }
      delay(1000);  

    }
