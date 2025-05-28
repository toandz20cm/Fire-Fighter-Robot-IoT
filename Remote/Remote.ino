#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

byte addresses[][6] = {"1Node", "2Node"};

RF24 radio(7, 8);

struct dataStruct {
  unsigned long _micros;
  float value;
} myData;

void setup() {

  Serial.begin(115200);
  
  AFMS.begin();
  
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  myData.value = 0;
  radio.startListening();
}

void loop() {
  if ( radio.available()) {
    while (radio.available()) {
      radio.read( &myData, sizeof(myData) );
    }

    radio.stopListening();
    myData.value;
    radio.write( &myData, sizeof(myData) );
    radio.startListening();
    Serial.print(F("Sent response "));
    Serial.print(myData._micros);
    Serial.print(F(" : "));
    Serial.println(myData.value);
    
    int code = myData.value;
    leftMotor->setSpeed(75);
    rightMotor->setSpeed(75);
    
    switch(code){
      
    case 1: leftMotor->run(FORWARD);
            rightMotor->run(FORWARD);
            Serial.println("Foreward");
            break;
    case 2: rightMotor->run(BACKWARD);
            leftMotor->run(FORWARD);
            Serial.println("Pivot Right");
            break;
    case 3: leftMotor->setSpeed(125);
            rightMotor->setSpeed(50);
            leftMotor->run(FORWARD);
            rightMotor->run(FORWARD);
            Serial.println("Lean Right");
            break;
    case 4: leftMotor->run(BACKWARD);
            rightMotor->run(FORWARD);
            Serial.println("Pivot Left");
            break;
    case 5: leftMotor->setSpeed(50);
            rightMotor->setSpeed(125);
            leftMotor->run(FORWARD);
            rightMotor->run(FORWARD);
            Serial.println("Lean Left");
            break;
    case 8: rightMotor->run(BACKWARD);
            leftMotor->run(BACKWARD);
            Serial.println("Backward");
            break;
    case 10: leftMotor->setSpeed(125);
             rightMotor->setSpeed(50);
             rightMotor->run(BACKWARD);
             leftMotor->run(BACKWARD);
             break;
    case 12: leftMotor->setSpeed(50);
             rightMotor->setSpeed(125);
             rightMotor->run(BACKWARD);
             leftMotor->run(BACKWARD);
             break;
    case 21: leftMotor->setSpeed(225);
             rightMotor->setSpeed(225);
             leftMotor->run(FORWARD);
             rightMotor->run(FORWARD);
             Serial.println("Foreward");
             break;
    case 22: leftMotor->setSpeed(225);
             rightMotor->setSpeed(225);
             rightMotor->run(BACKWARD);
             leftMotor->run(FORWARD);
             Serial.println("Pivot Right");
             break;
    case 23: leftMotor->setSpeed(225);
             rightMotor->setSpeed(150);
             leftMotor->run(FORWARD);
             rightMotor->run(FORWARD);
             Serial.println("Lean Right");
             break;
    case 24: leftMotor->setSpeed(225);
             rightMotor->setSpeed(225);
             leftMotor->run(BACKWARD);
             rightMotor->run(FORWARD);
             Serial.println("Pivot Left");
             break;
    case 25: leftMotor->setSpeed(150);
             rightMotor->setSpeed(225);
             leftMotor->run(FORWARD);
             rightMotor->run(FORWARD);
             Serial.println("Lean Left");
             break;
    case 28: leftMotor->setSpeed(225);
             rightMotor->setSpeed(225);
             rightMotor->run(BACKWARD);
             leftMotor->run(BACKWARD);
             Serial.println("Backward");
             break;
    case 30: leftMotor->setSpeed(225);
             rightMotor->setSpeed(150);
             rightMotor->run(BACKWARD);
             leftMotor->run(BACKWARD);
             break;
    case 32: leftMotor->setSpeed(150);
             rightMotor->setSpeed(225);
             rightMotor->run(BACKWARD);
             leftMotor->run(BACKWARD);
             break;
    default: leftMotor->run(RELEASE);
             rightMotor->run(RELEASE);
             Serial.println("Stop");
             break;
      }
    }
}
