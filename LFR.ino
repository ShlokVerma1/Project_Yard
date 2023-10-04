
#define LS 2 
#define RS 3  
#define LM1 4 
#define LM2 5 
#define RM1 6 
#define RM2 7 

void setup()
{
 pinMode (LS,INPUT);
 pinMode (RS,INPUT);
 pinMode (LM1,OUTPUT);
 pinMode (LM2,OUTPUT);
 pinMode (RM1,OUTPUT);
 pinMode (RM2,OUTPUT);
}

void loop()
{
  
  if(digitalRead(LS) && digitalRead(RS))                 // MOVE FORWARD 
  {
   digitalWrite (LM1,HIGH);
   digitalWrite (LM2,LOW);
   digitalWrite (RM1,HIGH);
   digitalWrite (RM2,LOW); 
  }
  
  
  if((digitalRead(LS)) && !digitalRead(RS))            // TURN LEFT
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
  }
  
  
  if(!digitalRead(LS) && (digitalRead(RS)))           // TURN RIGHT
  {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
  }
  
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))        // STOP
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);  
  }
}
