#include <Arduino.h>

#define tlacitkoA1 A1

// Define the LED pins
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

unsigned long previousMillis = 0;

int ledOn = 0;
bool sviti = false;

int mode = 0;
bool switchState = false;
bool buttonState1;

void setup()
{
  pinMode(tlacitkoA1, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void zleva()
{
  if (millis() - previousMillis > 200)
  {
    previousMillis = millis();
    switch (ledOn)
    {
    case 0:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      break;
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      break;
    case 2:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, HIGH);
      break;
    case 3:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
      break;
    }
    ledOn++;
    if (ledOn >= 4)
    {
      ledOn = 0;
    }
  }
}

void zprava()
{
  if (millis() - previousMillis > 200)
  {
    previousMillis = millis();
    switch (ledOn)
    {
    case 0:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      break;
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      break;
    case 2:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, HIGH);
      break;
    case 3:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
      break;
    }
    if (ledOn <= 0)
    {
      ledOn = 4;
    }
    ledOn--;
  }
}

void onoff()
{
  if (millis() - previousMillis > 200)
  {
    previousMillis = millis();
    if (sviti == false)
    {
      sviti = true;
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }
    else
    {
      sviti = false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
    }
  }
}

void zhasni()
{

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
}

void loop()
{

  // Read the button states
  buttonState1 = digitalRead(tlacitkoA1);

  // Change mode based on button presses

  if (buttonState1 == LOW)
  {
    if (switchState == false)
    {
      mode++;
      Serial.println();
      Serial.print("Mode: ");
      Serial.print(mode);
      switchState = true;
    }
  }
  else
  {
    switchState = false;
  }
  if (mode > 2)
  {
    mode = 0;
  }

  switch (mode)
  {
  case 0:
    zleva();
    // digitalWrite(ledPin1, LOW);
    // digitalWrite(ledPin2, HIGH);
    // digitalWrite(ledPin3, HIGH);
    break;
  case 1:
    zprava();
    // digitalWrite(ledPin1, HIGH);
    // digitalWrite(ledPin2, LOW);
    // digitalWrite(ledPin3, HIGH);
    break;
  case 2:
    onoff();
    // digitalWrite(ledPin1, HIGH);
    // digitalWrite(ledPin2, HIGH);
    // digitalWrite(ledPin3, LOW);
    break;
  }
}
