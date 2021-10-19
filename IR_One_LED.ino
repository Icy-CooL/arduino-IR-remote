#include <IRremote.h>
int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;
int fan = 7;
int bulb = 8;
void setup()
{
   pinMode(fan, OUTPUT);
   pinMode(bulb, OUTPUT);
   Serial.begin(9600);
   irrecv.enableIRIn();
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); 
     
  if(results.value== 3772793023)                                       
  {
             digitalWrite(fan,HIGH);
  }
  if(results.value == 3772782313) 
  {
             digitalWrite(fan,LOW);
  }
  if(results.value== 3772784863)                                       
  {
             digitalWrite(bulb,HIGH);
  }
  if(results.value == 3772833823) 
  {
             digitalWrite(bulb,LOW);
  }
  }
}
