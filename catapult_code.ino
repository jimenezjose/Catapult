/* 
* Jose Jimenez
*
* (Arduino Uno or Adafruit's Circuit Playground)
* The purpose of this program is to be able to use  
* an IR remote to launch a catault from at least 20 
* ft away. 
*/

#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <IRremoteInt.h>
//everything above are libraries needed to be called for the IR sensor and remote to work //http://z3t0.github.io/Arduino-IRremote/
                       
//#include <Adafruit_CircuitPlayground.h>         // load library for special functions for the Adafruit Circuit Playground  //https://github.com/adafruit/Adafruit_CircuitPlayground *****
#include <Servo.h>                              //load library for servo  

const int servoPin = 9;                         // the pin that the servo is connected to
const int ledPin = 10;                          // the pin that the led is connected to
const int RECV_PIN = 12;                        // The IR sensor pin

const int rest = 15;                            // initialize variable rest of type int to 0 (position of servo)  ((coordinate system angle is 180deg))
const int fire = 105;                           // servo position is now 90 degrees   ((coordinate system angle is 270deg)
const int servoDelay = 25;                      // give the servo time to delay
const int sensorDelay = 30;                     // allow the the sensor to wait 50ms before it can read input again
const int fireDelay = 1500;                     // sensor delay will hold the "fire position" and "turn ON led" for 1500ms.
const int countdown = 100;

int remoteLevel;                                // store the input of the IR remote into remoteLevel

Servo myServo;                                  // create servo object

IRrecv irrecv(RECV_PIN);                        // initialize what pin the IR sensor is connected to

/*
 * The function setup() returns no values 
 * and no arguments. The purpose of setup()
 * is to write code that I only want to 
 * be executed once. setup() is used to 
 * define what the inputs and outputs are.
 * Also, define where those i/o are connected
 * to the arduino.
 */
void setup() {
  Serial.begin(9600);                           // the rate communication is between the arduino and computer
  irrecv.enableIRIn();                          // set the IR sensor as an input
//  CircuitPlayground.begin();                    // allow functions that are built in to the arduino to be used *****
  pinMode(ledPin, OUTPUT);                      // set the led as the output
  myServo.attach(servoPin);                     //now arduino knows that there is an object called mySwitch which is connected to pin 9
}

/*
 * loop() returns no value and arguments.
 * The purpose of loop() is to repeatedly 
 * execute code. In this case, the loop 
 * is used to read the pressing of the IR 
 * remote (OFF button), and with that 
 * input it will turn ON the LED and 
 * rotate the servo 90 degrees.
 */
void loop() {
  remoteLevel = digitalRead(RECV_PIN);          // store what the IR sensor reads in the variable remoteLevel

  digitalWrite(ledPin, LOW);                    // initialize the LED to OFF
//  turnBlue();                                   // initialize the arduino pixels *****
  myServo.write(rest);                          // initialize the servo's positition to "rest"
  
  Serial.print ("The IR sensor is reading:");   // print what the IR sensor is reading on Serial monitor
  Serial.println(remoteLevel); 
  delay(sensorDelay);                           // allow a 50ms pause to diplay what the IR sensor is reading 
  if ( remoteLevel == 0) {                      // if the button is pressed then execute what is within the curly braces
    //power on
    Serial.println("TURN ONNN");                // print out "TURN ONNN" because the IR sesnor (remoteLevel) read that the power button has been pressed  
    digitalWrite(ledPin, HIGH);                 // Turn on LED
//    turnRed();                                  // turn all arduino pizels red *****
    myServo.write(fire);                        // rotate Servo 90 degrees
    delay(servoDelay);                          // wait a second for the servo to load
    delay(fireDelay);
//    CircuitPlayground.playTone(880,fireDelay);  // play a 784 Hz frequency AND DELAY for fireDelay *****
  }
}

/*
 * Instead of having all this code crowd my main function,
 * I just wrote it here. Sort of like a shortcut. The purpose of 
 * turnRed() is to turn all the leds that are built in to the arduino
 * Set pixel color is in RGB.
 */
//void turnRed(void) {                              //***** uncomment all functions below if using Circuit Playground *****
//  CircuitPlayground.setPixelColor(1, 255, 0, 0);
//  CircuitPlayground.setPixelColor(2, 255, 0, 0);
//  CircuitPlayground.setPixelColor(3, 255, 0, 0);                   //red 
//  CircuitPlayground.setPixelColor(4, 255, 0, 0);
//  CircuitPlayground.setPixelColor(5, 255, 0, 0);
//  CircuitPlayground.setPixelColor(6, 255, 0, 0);
//  CircuitPlayground.setPixelColor(7, 255, 0, 0);
//  CircuitPlayground.setPixelColor(8, 255, 0, 0);
//  CircuitPlayground.setPixelColor(9, 255, 0, 0);
//}

/*
 * Again I wrote this section to create a short cut in 
 * my main function. The prupose of turnOff() is 
 * to turn off all the leds that are built in to the 
 * arduino.
 */
//void turnOff(void) {
//  CircuitPlayground.setPixelColor(1, 0, 0, 0);
//  CircuitPlayground.setPixelColor(2, 0, 0, 0);
//  CircuitPlayground.setPixelColor(3, 0, 0, 0);                   //off
//  CircuitPlayground.setPixelColor(4, 0, 0, 0);
//  CircuitPlayground.setPixelColor(5, 0, 0, 0);
//  CircuitPlayground.setPixelColor(6, 0, 0, 0);
//  CircuitPlayground.setPixelColor(7, 0, 0, 0);
//  CircuitPlayground.setPixelColor(8, 0, 0, 0);
//  CircuitPlayground.setPixelColor(9, 0, 0, 0);
//}

//void turnBlue() {
//  CircuitPlayground.setPixelColor(1, 0, 0, 255);
//  CircuitPlayground.setPixelColor(2, 0, 0, 255);
//  CircuitPlayground.setPixelColor(3, 0, 0, 255);
//  CircuitPlayground.setPixelColor(4, 0, 0, 255);                  //blue
//  CircuitPlayground.setPixelColor(5, 0, 0, 255);
//  CircuitPlayground.setPixelColor(6, 0, 0, 255);
//  CircuitPlayground.setPixelColor(7, 0, 0, 255);
//  CircuitPlayground.setPixelColor(8, 0, 0, 255);
//  CircuitPlayground.setPixelColor(9, 0, 0, 255);
//}

