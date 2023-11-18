/*  the goal of this program is display the voltage, bitvalue and resistance of the LDR on
    the serial monitor and to also control the servo motor using the LDR. the theme of this
    program is analog input.
*/

#include <Servo.h>  //includes the servo library

Servo myservo;  //create servo project to control a servo
int ldr = A0;     //defines A0 as ldr
int val;          // sets val as an integer


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);          //starts the serial communication at 9600 bits per second
  myservo.attach(9);        //attaches pin 9 to the servo motor

}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(ldr);             // reads the value of the ldr
  val = map(val, 0, 1023, 0, 180);    // scale it for use with the servo
  myservo.write(val);                // sets the servo position according to the scaled value

  Serial.print("bitvalue= ");       //serial prints "bitvalue"
  Serial.println(val);                //serial prints the value of the ldr
  float V = (5.0/1023.0) * val;       // floats V and creates an equation of y=mx=b
  Serial.print("Voltage= ");            //serial prints "Voltage= "
  Serial.println(V);                 //serial prints the value of V
  float current = ((5.0 - V)/1000);          //floats the current and sets equation of ohms law
  float ohms = (V/current);              //floats the ohms and sets equation to find resistance
  Serial.print("Resisance= ");            // serial prints "Resistance= "
  Serial.println(ohms);                //serial prints the value of ohms
  delay(15);               //delay it for 15 milliseconds
}
