#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Streaming.h>
#include <ESP32Servo.h>

#define TRIG_PIN 18
#define ECHO_PIN 5
#define SERVO_PIN 17

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 0
#define DISTANCE_TRIGGER 20

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  // findI2CAddress();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0), lcd << F("      TOLL      ");
  lcd.setCursor(0, 1), lcd << F("      GATE      ");

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);
  closeBarrier();
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 1), lcd << F(" BARRIER CLOSE  ");
}

void loop() {
  // Serial << "Distance :: " << getDistance() << "cm" << endl;
  // testing();
  normalProcess();
  delay(1000);
}

void normalProcess() {
  float distance = getDistance();
  lcd.setCursor(0, 0), lcd << distance << F("cm AWAY  ");

  if (distance <= DISTANCE_TRIGGER) {
    lcd.setCursor(0, 1), lcd << F("  BARRIER OPEN  ");
    openBarrier();
    delay(3000);
    closeBarrier();
    lcd.setCursor(0, 1), lcd << F(" BARRIER CLOSE  ");
  }
}
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return (duration / 2.0) * 0.0343;
}


void testing() {
  if (Serial.available()) {
    String reading = Serial.readString();
    Serial << reading << endl;
    reading.trim();
    if (reading == "0") {
      Serial << "Open Barrier" << endl;
      openBarrier();
    } else if (reading == "1") {
      Serial << "Close Barrier" << endl;
      closeBarrier();
    }
  }
}

void openBarrier() {
  myServo.write(OPEN_ANGLE);
}

void closeBarrier() {
  myServo.write(CLOSE_ANGLE);
}
