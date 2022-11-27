// Define pins: you can use from 2 to 12 and then if you need more from A0 to A?
const int controlPin[16] = {2,3,4,5,6,7,8,9,10,11}; 

// Relay connection: relay can be connected to Allways On or Allways Off
const int triggerType = LOW;

// Delay in the loop (not sure what this does)
int loopDelay = 100;

// Also no idea what it does
int tmpStat =1;


void setup() {
  for(int i=0; i<16; i++)
  {
    pinMode(controlPin[i], OUTPUT);// set pin as output
    if(triggerType ==LOW){
      digitalWrite(controlPin[i], HIGH); // set initial state OFF for low trigger relay
    }else{
       digitalWrite(controlPin[i], LOW); // set initial state OFF for high trigger relay     
    }
  }
  
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  
}

void loop() {

 //channelControl(6,1, 2000); // turn relay 7 ON for 2 seconds
 //channelControl(6,0, 5000); // turn relay 7 OFF for 5 seconds
 //channelControl(9,1, 3000); // turn relay 10 OFF for ever

 delay(loopDelay);// wait for loopDelay ms
          
}

/*
 * function: channelControl
 * turns ON or OFF specific relay channel
 * @param relayChannel is integer value channel from 0 to 15
 * @param action is 1 for ON or 0 for OFF
 * @param t is time in melisecond
 */

void channelControl(int relayChannel, int action, int t)
{
  int state =LOW;
  String statTXT =" ON";
  if(triggerType == LOW)
  {    
    if (action ==0)// if OFF requested
    {
      state = HIGH;
      statTXT = " OFF";
    }
    digitalWrite(controlPin[relayChannel], state);
    if(t >0 )
    {
      delay(t);
    }
       Serial.print ("Channel: ");
       Serial.print(relayChannel); 
       Serial.print(statTXT);
       Serial.print(" - "); 
       Serial.println(t);        
  }else{
    if (action ==1)// if ON requested
    {
      state = HIGH;     
    }else{
      statTXT = " OFF";    
    }
    digitalWrite(controlPin[relayChannel], state);
    if(t >0 )
    {
      delay(t);
    }
       Serial.print ("Channel: ");
       Serial.print(relayChannel); 
       Serial.print(statTXT);
       Serial.print(" - "); 
       Serial.println(t);    
  }

}
