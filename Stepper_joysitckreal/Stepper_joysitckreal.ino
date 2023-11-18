/*  the goal of this program is to control the stepper motor with a joystick.
    the theme of this program is analog input.
*/


#include <Stepper.h>                  //includes the stepper library
int stepsperrev = 2048;               // sets the steps per revolution of the stepper to 2048
int speed = 20;                              //sets the integer speed of the motor to 20
Stepper mystepper(stepsperrev, 8,10,9,11);        //initializes the stepper to pin 8, 10, 9, 11
int joypin = A0;                               //sets the pin A0 as joypin
int IN1 = 8;                                   //sets the pin 8 as IN1
int IN2 = 10;                                   //sets the pin 10 as IN2
int IN3 = 9;                                   //sets the pin 9 as IN3
int IN4 = 11;                                   //sets the pin 11 as IN4

void setup() {
  // put your setup code here, to run once:
  mystepper.setSpeed(speed);                   //sets the motor on speed 20
  pinMode(joypin, INPUT);                     //has the pin A0 to an input
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(joypin);                   //reads pin A0 and defines it to val
  val = map(val, 0, 1023, 0, 2);                //maps the value of val from 0-1023 to 0-2

if (val == 1) {                 //makes the condition of if to val is = to 1
  mystepper.step(0);              //makes the stepper stop moving
}

if (val == 0) {                 //makes the condition of if to val is = to 0
  mystepper.step(1);             //makes the stepper move clockwise
}
if (val == 2) {                //makes the condition of if to val = 2
  mystepper.step(-1);           //makes the stepper move counterclockwise
}
}










