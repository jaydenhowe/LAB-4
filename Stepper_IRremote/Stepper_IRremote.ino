/*  the goal of this program is to control a stepper motor with
    an IR remote. the theme of this program is digital input. 
*/

#include <Stepper.h>                //include the stepper library
#include <IRremote.h>                //include the IR remote library

int stepsperrev = 2048;                // sets the steps per revolution to 2048
int stepperspeed = 20;                      //has the speed to 20
Stepper mystepper(stepsperrev, 8,10,9,11);     //initializes the stepper to pin 8, 10, 9, 11
int IN1 = 8;                               //sets pin 8 to IN1
int IN2 = 10;                             //sets pin 10 to IN2
int IN3 = 9;                             //sets pin 9 to IN3
int IN4 = 11;                             //sets pin 11 to IN4
#define left 68                    //defines the key code 68 to left
#define right 67                 //defines the key code 67 to right
#define pause 21               //defines the key code 21 to pause
#define IRrecpin 7                 //deinfes the IR receiver to pin 7

void setup() {
  // put your setup code here, to run once:
  mystepper.setSpeed(stepperspeed);           //sets the speed of the stepper to 20
  pinMode(IRrecpin, INPUT);                         //sets pin 7 to an input
  IrReceiver.begin(IRrecpin, ENABLE_LED_FEEDBACK);       //begins the IR receiver
}

void loop() {

const int myremote = IrReceiver.decodedIRData.command;     //decodes the IR receiver and sets it to "myremote"
  if (IrReceiver.decode()) {                            //if the IR receiver is decoded then resume the receiver
        IrReceiver.resume();
  }
  if (myremote == left) {          //sets the condition of if to "myremote" = to the left key
    mystepper.step(1);                //moves the stepper clockwise
    delayMicroseconds(10);        //delays it my 10 microseconds
  }
  if (myremote == right) {          //sets the condition of if to "myremote" = to the right key       
    mystepper.step(-1);              //moves the stepper counterclockwise
    delayMicroseconds(10);       //delays it my 10 microseconds
    }
  if (myremote == pause) {         //sets the condition of if to "myremote" = to the pause key
    mystepper.step(0);                  //stops the stepper motor
    delayMicroseconds(10);       //delays it my 10 microseconds
  }
}

