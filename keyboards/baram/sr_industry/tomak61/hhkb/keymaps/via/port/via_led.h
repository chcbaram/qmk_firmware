#pragma once

#include "quantum.h"


enum
{
  LED_TYPE_CAPS = 0,
  LED_TYPE_MAX_CH
};

typedef union
{
  uint32_t raw;

  struct PACKED
  {
    uint8_t enable : 2;
    uint8_t mode   : 6;
    hsv_t   hsv;
  };
} led_caps_config_t;

enum 
{
  id_qmk_led_caps_channel = 10
};

void via_led_init(void);
void via_led_get_rgb(uint8_t type, rgb_t *p_rgb);
void via_qmk_led_command(uint8_t led_type, uint8_t *data, uint8_t length);