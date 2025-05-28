#include <SPI.h>
#include <RF24.h>

byte addresses[][6] = {"1Node", "2Node"};

RF24 radio(9, 10);

#define Px A0
#define Py A1

const int buttonAp = 2;
const int buttonBp = 3;
const int buttonCp = 4;
const int buttonDp = 5;
const int buttonKp = 8;

int buttonAs = 0;
int buttonBs = 0;
int buttonCs = 0;
int buttonDs = 0;
int buttonKs = 0;
int A, B, C, D, K;

struct dataStruct {
  unsigned long _micros;
  float value;
} myData;

void setup() {

  Serial.begin(115200);

  pinMode(buttonAp, INPUT);
  pinMode(buttonBp, INPUT);
  pinMode(buttonCp, INPUT);
  pinMode(buttonDp, INPUT);
  pinMode(buttonKp, INPUT);

  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);
  myData.value = 0;
  radio.startListening();
}

void loop() {
  
  buttonAs = digitalRead(buttonAp);
  buttonBs = digitalRead(buttonBp);
  buttonCs = digitalRead(buttonCp);
  buttonDs = digitalRead(buttonDp);
  buttonKs = digitalRead(buttonKp);
  
  if (buttonAs == LOW) {
    A = 1;
  } else {
    A = 0;
  }
  if (buttonBs == LOW) {
    B = 2;
  } else {
    B = 0;
  }
  if (buttonDs == LOW) {
    D = 4;
  } else {
    D = 0;
  }
  if (buttonCs == LOW) {
    C = 8;
  } else {
    C = 0;
  }
  if (buttonKs == LOW) {
    K = 20;
  } else {
    K = 0;
  }

  myData.value = A + B + C + D + K;
  
  radio.stopListening();

  Serial.println(F("Now sending"));

  myData._micros = micros();
  if (!radio.write( &myData, sizeof(myData) )) {
    Serial.println(F("failed"));
  }

  radio.startListening();

  unsigned long started_waiting_at = micros();
  boolean timeout = false;

  while ( ! radio.available() ) {
    if (micros() - started_waiting_at > 200000 ) {
      timeout = true;
      break;
    }
  }

  if ( timeout ) {
    Serial.println(F("Failed, response timed out."));
  } else {
    radio.read( &myData, sizeof(myData) );
    unsigned long time = micros();

    Serial.print(F("Sent "));
    Serial.print(time);
    Serial.print(F(", Response "));
    Serial.print(myData._micros);
    Serial.print(F(", Round-trip "));
    Serial.print(time - myData._micros);
    Serial.print(F(" microseconds Value "));
    Serial.println(myData.value);
  }
}

