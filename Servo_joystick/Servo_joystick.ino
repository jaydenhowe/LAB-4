/*  the goal of this program is to control a servo motor with a joystick.
    the theme of this program is analog input.
*/

#include <Servo.h>   //includes the servo library

Servo myservo;  //creates servo object to control servo motor
int joypin = A0;  //analog pin used to control the joystick
int val;          // variable to read the value from analog pin


void setup() {
  // put your setup code here, to run once:

  myservo.attach(9);    // attaches pin 9 to the servo motor

}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(joypin);          //reads the value of the joystick
  val = map(val, 0, 1023, 0, 180);     //scale it for use with the servo
  myservo.write(val);               //sets the servo positioning according to the scaoled value
  delay(15);                      //delays it by 15 milliseconds

}
