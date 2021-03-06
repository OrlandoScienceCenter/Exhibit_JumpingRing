  /*
Suraj Patel
Orlando Science Center
Jumping Ring, July 2015

Jumping Ring:
Fires two Solid State Relays for 40 milliseconds when button is pressed. 
Built in delay of 5 seconds between consecutive launches.

 The circuit:
 * Button attached from 5V to pin 1
 * 10K resistor attached to pin 1 from ground
 * Solid State Relay #1 (SSR1) attached to Pin 0 and ground
 * Solid State Relay #1 (SSR1) attached to Pin 2 and ground

Based on code for the Arduino Button tutorial: http://www.arduino.cc/en/Tutorial/Button

*/


// set pin numbers:
const int buttonPin = 1;         // the number of the pushbutton pin
const int SSR1 =  0;             // the number of the Solid State Relay #1 pin
const int SSR2 =  2;             // the number of the Solid State Relay #2 pin
const int TimeSSRon = 40;        // Time (ms) to leave the SSRs on for (For 120VAC, one period is 8.33ms)
const int timebuttondelay = 5000;// Time (ms) between possible button state reads


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status



void setup() {
// initialize the SSR pins as outputs, set SSRs to low when Arduino is first powered up:
  pinMode(SSR1, OUTPUT);
  pinMode(SSR2, OUTPUT);
  digitalWrite(SSR1, LOW);
  digitalWrite(SSR2, LOW);
  
// initialize the button pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {
// read the state of the button value:
  buttonState = digitalRead(buttonPin);

// check if the pushbutton is pressed.
// if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
     // turn SSR1 and SSR2 on:
    digitalWrite(SSR1, HIGH);
    digitalWrite(SSR2, HIGH);

    //Leave SSRs on for "timeSSRon":
    delay(TimeSSRon);

    //Turn off SSR and SSR2 and wait "timebuttondelay" before reading button state again:
    digitalWrite(SSR1, LOW);
    digitalWrite(SSR2, LOW);
    delay(timebuttondelay);
    
    
  }

}

