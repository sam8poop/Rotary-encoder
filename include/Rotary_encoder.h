#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <Arduino.h>

class Rotary_encoder {
private:
  uint8_t clk;
  uint8_t dt;
  uint8_t sw;

  volatile int8_t changes = 0;
  volatile uint8_t ls;
  volatile int32_t pos = 0;

  static void IRAM_ATTR encoderISR(void* arg);

public:

  Rotary_encoder(
    uint8_t clock_pin,
    uint8_t data_pin,
    uint8_t switch_pin
  );

  void begin();
  int32_t get_pos();
};

#endif