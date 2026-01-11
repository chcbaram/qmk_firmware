
#include "via_led.h"
#include "color.h"
#include "eeconfig.h"




_Static_assert(sizeof(led_caps_config_t) == sizeof(uint32_t), "EECONFIG out of spec.");

enum via_qmk_led_value {
    id_qmk_led_enable       = 1,
    id_qmk_led_brightness   = 2,
    id_qmk_led_color        = 3,
};


static led_t leds = {0};
static led_caps_config_t led_caps_config[LED_TYPE_MAX_CH];


static void via_qmk_led_get_value(uint8_t led_type, uint8_t *data);
static void via_qmk_led_set_value(uint8_t led_type, uint8_t *data);
static void via_qmk_led_save(uint8_t led_type);
static void eeconfig_read_led_caps(led_caps_config_t *p_config);
static void eeconfig_update_led_caps(led_caps_config_t *p_config);




EECONFIG_DEBOUNCE_HELPER(led_caps, led_caps_config[LED_TYPE_CAPS]);




void via_led_init(void)
{
  eeconfig_init_led_caps();
  if (led_caps_config[LED_TYPE_CAPS].mode != 1)
  {
    led_caps_config[LED_TYPE_CAPS].mode   = 1;
    led_caps_config[LED_TYPE_CAPS].enable = true;
    led_caps_config[LED_TYPE_CAPS].hsv    = (hsv_t){HSV_GREEN};
    eeconfig_flush_led_caps(true);
  }
}

void via_led_get_rgb(uint8_t type, rgb_t *p_rgb)
{  
  eeconfig_read_led_caps(&led_caps_config[type]);

  *p_rgb = hsv_to_rgb(led_caps_config[type].hsv);
}

void eeconfig_read_led_caps(led_caps_config_t *p_config)
{
  eeconfig_read_user_datablock(p_config, EECONFIG_OFFSET_LED_CAPS, sizeof(led_caps_config_t));
}

void eeconfig_update_led_caps(led_caps_config_t *p_config)
{
  eeconfig_update_user_datablock(p_config, EECONFIG_OFFSET_LED_CAPS, sizeof(led_caps_config_t));
}

void via_qmk_led_command(uint8_t led_type, uint8_t *data, uint8_t length)
{
  // data = [ command_id, channel_id, value_id, value_data ]
  uint8_t *command_id        = &(data[0]);
  uint8_t *value_id_and_data = &(data[2]);

  switch (*command_id)
  {
    case id_custom_set_value:
      {
        via_qmk_led_set_value(led_type, value_id_and_data);
        break;
      }
    case id_custom_get_value:
      {
        via_qmk_led_get_value(led_type, value_id_and_data);
        break;
      }
    case id_custom_save:
      {
        via_qmk_led_save(led_type);
        break;
      }
    default:
      {
        *command_id = id_unhandled;
        break;
      }
  }
}

void via_qmk_led_get_value(uint8_t led_type, uint8_t *data)
{
  // data = [ value_id, value_data ]
  uint8_t *value_id   = &(data[0]);
  uint8_t *value_data = &(data[1]);
  switch (*value_id)
  {
    case id_qmk_led_enable:
      {
        value_data[0] = led_caps_config[led_type].enable;
        break;
      }    
    case id_qmk_led_brightness:
      {
        value_data[0] = led_caps_config[led_type].hsv.v;
        break;
      }
    case id_qmk_led_color:
      {
        value_data[0] = led_caps_config[led_type].hsv.h;
        value_data[1] = led_caps_config[led_type].hsv.s;
        break;
      }
  }
}

void via_qmk_led_set_value(uint8_t led_type, uint8_t *data)
{
  // data = [ value_id, value_data ]
  uint8_t *value_id   = &(data[0]);
  uint8_t *value_data = &(data[1]);
  switch (*value_id)
  {
    case id_qmk_led_enable:
      {
        led_caps_config[led_type].enable = value_data[0];
        break;
      }
    case id_qmk_led_brightness:
      {
        led_caps_config[led_type].hsv.v = value_data[0];
        break;
      }
    case id_qmk_led_color:
      {
        led_caps_config[led_type].hsv.h = value_data[0];
        led_caps_config[led_type].hsv.s = value_data[1];
        break;
      }
  }
  eeconfig_flush_led_caps(true);
  led_update_kb(leds);
}

void via_qmk_led_save(uint8_t led_type)
{
  if (led_type == LED_TYPE_CAPS)
  {
    eeconfig_flush_led_caps(true);
  }  
}