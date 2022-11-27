// Define pins: you can use from 2 to 12 and then if you need more from A0 to A?
const int controlPins[10] = {2,3,4,5,6,7,8,9,10,11}; 

// Relay connection: relay can be connected to Allways On or Allways Off
const int triggerType = LOW;

// Delay in the loop (not sure what this does)
int loopDelay = 100;

// Also no idea what it does
int tmpStat =1;

// Initial setup that runs only once
void setup() {

  // Loop that runs as many elements in controlPins
  for( int i = 0; i < 10; i++ )
  {
    // Set pins as output
    pinMode(controlPins[i], OUTPUT);
    if ( triggerType == LOW ) {
      // Set initial state OFF for low trigger relay
      digitalWrite( controlPins[i], HIGH );
    } else {
      // Set initial state OFF for high trigger relay     
      digitalWrite( controlPins[i], LOW );
    }
  }
  
  // initialize serial monitor with 9600 baud
  Serial.begin(9600);
  
}

void loop() {

  // Example of pin control
  //channelControl(6,1, 2000); // turn relay 7 ON for 2 seconds
  //channelControl(6,0, 5000); // turn relay 7 OFF for 5 seconds
  
  // wait for loopDelay ms
  delay(loopDelay);
          
}

/*
 function: channelControl
 what: turns ON or OFF specific relay channel
 @param relayChannel is integer value channel from 0 to 15
 @param action is 1 for ON or 0 for OFF
 @param t is time in melisecond
 */

void channelControl(int relayChannel, int action, int t)
{
  // Why it's state type int if the content
  int state = LOW;
  String statTXT = " ON";
  if(triggerType == LOW)
  {   
    // if OFF requested 
    if (action == 0)
      {
        state = HIGH;
        statTXT = " OFF";
      }

    digitalWrite(controlPins[relayChannel], state);

    if (t >0 )
      {
        delay(t);
      }
    Serial.print ("Channel: ");
    Serial.print(relayChannel);
    Serial.print(statTXT);
    Serial.print(" - "); 
    Serial.println(t);

  } else {

    // if ON requested
    if (action ==1)
    {

      state = HIGH;

    } else {

      statTXT = " OFF";

    }

    digitalWrite(controlPins[relayChannel], state);

    if ( t > 0 )
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
