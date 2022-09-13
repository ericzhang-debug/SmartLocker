#define BLINKER_WIFI

#include <Arduino.h>
#include <Servo.h>
#include <Blinker.h>
#include <SoftwareSerial.h>

#define LED D5
#define SERVO D6
#define s_tx D7
#define s_rx D8

#define OPEN_POSITION 0
#define CLOSE_POSITION -90
#define LASTING_TIME_MS 5000

#define SSID ""
#define PSWD ""
#define AUTH ""


char auth[] = AUTH;
char ssid[] = SSID;
char pswd[] = PSWD;

BlinkerButton DOORBUTTON("btn-door");

SoftwareSerial com_servo(s_rx,s_tx);

Servo con_servo;

void setup() {
  Blinker.begin(auth, ssid, pswd);
  DOORBUTTON.attach(DOORBUTTON_callback);

  pinMode(LED,OUTPUT);
  pinMode(SERVO,OUTPUT);
  pinMode(s_tx,OUTPUT);
  pinMode(s_rx,INPUT);
}

void loop() {
  Blinker.run();
}

void DOORBUTTON_callback(const String & state)
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void control_door(){
  digitalWrite(LED,HIGH);
  con_servo.write(OPEN_POSITION);
  delay(LASTING_TIME_MS);
  con_servo.write(CLOSE_POSITION);
  digitalWrite(LED,LOW);
}
