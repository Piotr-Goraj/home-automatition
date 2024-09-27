#include <Arduino.h>
#include <HCSR04.h>

// UltraSonicDistanceSensor distanceSensor1(trigger, echo);
UltraSonicDistanceSensor distanceSensor1(D0, D5);
UltraSonicDistanceSensor distanceSensor2(D6, D7);
UltraSonicDistanceSensor distanceSensor3(D8, D4);
UltraSonicDistanceSensor distanceSensor4(D3, D2);

#define LED1 3
#define LED2 D1

double distance1 = 0;
double distance2 = 0;
bool detectedBySensor1 = false;
bool detectedBySensor2 = false;

double distance3 = 0;
double distance4 = 0;
bool detectedBySensor3 = false;
bool detectedBySensor4 = false;

unsigned long previousMillis = 0;
unsigned long lastToggleTime = 0; // Czas ostatniego przełączenia

void setup()
{
  Serial.begin(9600);

  pinMode(LED1, FUNCTION_3); // GPIO 3 (RX) swap the pin to a GPIO

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000)
  {
    previousMillis = currentMillis;

    distance1 = distanceSensor1.measureDistanceCm();
    distance2 = distanceSensor2.measureDistanceCm();
    distance3 = distanceSensor3.measureDistanceCm();
    distance4 = distanceSensor4.measureDistanceCm();

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
  }

  // Warunki dla LED1
  if (distance1 > 10 && distance1 < 75)
  {
    // Pierwszy czujnik wykrył osobę
    if (!detectedBySensor1)
    {
      detectedBySensor1 = true;

      // Jeśli taśma LED jest wyłączona, włącz ją
      digitalWrite(LED1, HIGH);
      lastToggleTime = currentMillis;
    }
  }
  else if (distance2 > 10 && distance2 < 75)
  {
    // Drugi czujnik wykrył osobę
    if (!detectedBySensor2)
    {
      detectedBySensor2 = true;

      // Jeśli taśma LED jest wyłączona, włącz ją
      digitalWrite(LED1, HIGH);
      lastToggleTime = currentMillis;
    }
  }

  // Sprawdź, czy minęło 10 sekund od ostatniego włączenia taśmy LED
  if ((detectedBySensor1 && detectedBySensor2) && currentMillis - lastToggleTime >= 5000)
  {
    // Wyłącz taśmę LED po 10 sekundach
    digitalWrite(LED1, LOW);
    detectedBySensor1 = false;
    detectedBySensor2 = false;
  }

  // Sprawdź, czy minęły 3 minuty od ostatniego włączenia taśmy LED
  if ((detectedBySensor1 || detectedBySensor2) && currentMillis - lastToggleTime >= 180000)
  {
    // Wyłącz taśmę LED po 3 minutach
    digitalWrite(LED1, LOW);
    detectedBySensor1 = false;
    detectedBySensor2 = false;
  }

  // Warunki dla LED2
  if (distance3 > 10 && distance3 < 75)
  {
    // Pierwszy czujnik wykrył osobę
    if (!detectedBySensor3)
    {
      detectedBySensor3 = true;

      // Jeśli taśma LED jest wyłączona, włącz ją
      digitalWrite(LED2, HIGH);
      lastToggleTime = currentMillis;
    }
  }
  else if (distance4 > 10 && distance4 < 75)
  {
    // Drugi czujnik wykrył osobę
    if (!detectedBySensor4)
    {
      detectedBySensor4 = true;

      // Jeśli taśma LED jest wyłączona, włącz ją
      digitalWrite(LED2, HIGH);
      lastToggleTime = currentMillis;
    }
  }

  // Sprawdź, czy minęło 10 sekund od ostatniego włączenia taśmy LED
  if ((detectedBySensor3 && detectedBySensor4) && currentMillis - lastToggleTime >= 5000)
  {
    // Wyłącz taśmę LED po 10 sekundach
    digitalWrite(LED2, LOW);
    detectedBySensor3 = false;
    detectedBySensor4 = false;
  }

  // Sprawdź, czy minęły 3 minuty od ostatniego włączenia taśmy LED
  if ((detectedBySensor3 || detectedBySensor4) && currentMillis - lastToggleTime >= 180000)
  {
    // Wyłącz taśmę LED po 3 minutach
    digitalWrite(LED2, LOW);
    detectedBySensor3 = false;
    detectedBySensor4 = false;
  }
}
