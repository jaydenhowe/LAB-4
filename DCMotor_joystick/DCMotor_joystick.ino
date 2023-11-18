/* the goal of this program is to control the direction and speed of the DC motor
   using a joystick. the theme of this program is Digital Output and Analog Input.
   */

int en=5;       //sets en as an integer attached to pin 5
int in1=4;       //sets in1 as an integer attached to pin 4  
int in2=3;       //sets in2 as an integer attached to pin 3
int Speed;       // set Speed as an integer
int Joypin=A1;       //sets Joypin as an integer attached to pin A1
int JoyVal;            // set JoyVal as an integer
 
void setup() {
  // put your setup code here, to run once:
pinMode(en, OUTPUT);    //sets pin 5 as an output
pinMode(in1, OUTPUT);    //sets pin 4 as an output
pinMode(in2, OUTPUT);    //sets pin 3 as an output
pinMode(Joypin, INPUT);    //sets pin A1 as an input
Serial.begin(9600);      //starts the serial communcitation at 9600 bits per second
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
JoyVal = analogRead(Joypin);          //analogreads pin A1 and sets it as "JoyVal"
Serial.println (JoyVal);             //Serial prints the value of "JoyVal"

if (JoyVal<512){               // uses if command and sets the statement 
digitalWrite(in1, LOW);          //writes pin 4 as LOW
digitalWrite(in2, HIGH);         //sets pin 3 as HIGH
Speed=-255./512.*JoyVal+255.;       //calculates the speed using the Joystick value (JoyVal)
analogWrite(en, Speed);         //writes pin 5 to the speed it is calculated to
}

if(JoyVal>=512){                  // uses if command and sets the statement 
digitalWrite(in1, HIGH);                    //writes pin 4 as HIGH
digitalWrite(in2, LOW);                     //sets pin 3 as LOW
Speed=(255./512.)*JoyVal-255.;         //calculates the speed using the Joystick value (JoyVal)
analogWrite(en, Speed);              //writes pin 5 to the speed it is calculated to
}
}
