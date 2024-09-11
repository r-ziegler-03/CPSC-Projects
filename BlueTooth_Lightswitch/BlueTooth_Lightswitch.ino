#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>
Servo myservo;

void setup() 
{
  Serial.begin(9600);    //Sets the baud rate
  Dabble.begin(9600);    //Sets the baud rate
  myservo.attach(9);     //Sets the pin the servo is attached to
  myservo.write(100);     //The deault angle of the servo is 60 degrees
  delay(1000);
}

void loop() {
  Dabble.processInput();   //Grabs input from the dabble app
  Serial.print("Key Pressed: ");
  if (GamePad.isUpPressed())      //Turns on the lightswitch 
  {
    Serial.println("On Switch");
    myservo.write(150);
    delay(1000);
  }
  else if (GamePad.isDownPressed()) //Turns off the lightswitch
  {
    Serial.println("Off Switch");
    myservo.write(50);
    delay(1000);
  }
  else if (GamePad.isSquarePressed())  //Sets a 6 hour alarm, the light will turn on in 6 hours
  {
    Serial.println("6 Hour Alarm");
    delay(5000);
    myservo.write(50);
    delay(10000);
    myservo.write(150);
  }
  else if (GamePad.isCirclePressed())  //Sets an 8 hour alarm, the light will turn on in 8 hours
  {
    Serial.println("8 Hour Alarm");
    myservo.write(20);
    delay(28800000);
    myservo.write(100);
  }
  else if (GamePad.isCrossPressed())  //Sets a 10 hour alarm, the light will turn on in 10 hours
  {
    Serial.println("10 Hour Alarm");
    myservo.write(20);
    delay(36000000);
    myservo.write(100);
  }
  else if (GamePad.isTrianglePressed())  //Sets a 12 hour alarm, the light will turn on in 12 hours
  {
    Serial.println("12 Hour Alarm");
    myservo.write(20);
    delay(43200000);
    myservo.write(100);
  }
  else //No input given by the app, the lightswitch has been given no command
  {
    Serial.println("Stopped");
  }
}