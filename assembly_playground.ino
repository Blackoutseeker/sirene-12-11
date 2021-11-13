#include "asm.h"
#include <DS3231.h> // https://github.com/NorthernWidget/DS3231 (v1.0.7)
#include <Wire.h>
#define clock_vcc 17
#define clock_gnd 16

bool century = false;
bool h12Flag;
bool pmFlag;
byte hour;
byte minute;
byte second;

DS3231 clock;

void activate_siren_with_delay() {
  activate_siren();
  delay(6000);
  deactivate_siren();
}

void setup() {
  asm_setup();
  pinMode(clock_vcc, OUTPUT);
  pinMode(clock_gnd, OUTPUT);
  digitalWrite(clock_vcc, HIGH);
  digitalWrite(clock_gnd, LOW);
  Wire.begin();
  // clock.setClockMode(false);  // set to 24h format
  // clock.setYear(21);
  // clock.setMonth(10);
  // clock.setDate(30);
  // clock.setDoW(6);
  // clock.setHour(22);
  // clock.setMinute(46);
  // clock.setSecond(0);
}

void loop() {
  if (digitalRead(4)) {
    deactivate_siren();
    delay(1000);
    hour = clock.getHour(h12Flag, pmFlag); // 24h format
    minute = clock.getMinute();
    second = clock.getSecond();
    if (hour == 7 and minute == 10 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 9 and minute == 20 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 12 and minute == 30 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 15 and minute == 20 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 17 and minute == 0 and second == 0) {
      activate_siren_with_delay();
    }
  }
  else {
    activate_siren();
  }
}
