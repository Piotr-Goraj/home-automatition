#include <Arduino.h>
#include <HCSR04.h>

// UltraSonicDistanceSensor distanceSensor1(trigger, echo);
// UltraSonicDistanceSensor distanceSensor1(D0, D5);
// UltraSonicDistanceSensor distanceSensor2(D6, D7);
// UltraSonicDistanceSensor distanceSensor3(D8, D4);
// UltraSonicDistanceSensor distanceSensor4(D3, D2);

#define LED1 3
#define LED2 D1

void setup()
{
  // Serial.begin(9600);

  pinMode(LED1, FUNCTION_3); // GPIO 3 (RX) swap the pin to a GPIO

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  // double distance1 = distanceSensor1.measureDistanceCm();
  // double distance2 = distanceSensor2.measureDistanceCm();
  // double distance3 = distanceSensor3.measureDistanceCm();
  // double distance4 = distanceSensor4.measureDistanceCm();

  // Serial.print("Module 1:");
  // Serial.print(distance1);
  // Serial.println(F("cm"));

  // Serial.print("Module 2:");
  // Serial.print(distance2);
  // Serial.println(F("cm"));

  // Serial.print("Module 3:");
  // Serial.print(distance3);
  // Serial.println(F("cm"));

  // Serial.print("Module 4:");
  // Serial.print(distance4);
  // Serial.println(F("cm"));
  // Serial.println(F(""));

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

  delay(1000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  delay(1000);
}
