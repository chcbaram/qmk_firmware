// Copyright 2025 Andrew Kannan (awkannan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_6,               KC_7,    KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC, KC_BSPC, KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,                     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENTER,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,                     KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_RSFT, KC_RSFT,
           KC_LGUI, KC_LALT, KC_SPC,  MO(1),                           MO(2),   KC_SPC, KC_RALT, KC_RGUI
)
};


static void indicator_update(void);

static bool  is_rgb_enable = false;




void keyboard_pre_init_user(void) {
}

void bootmagic_scan(void) {
  uint8_t row = BOOTMAGIC_ROW;
  uint8_t col = BOOTMAGIC_COLUMN;

  matrix_scan();
  wait_ms(DEBOUNCE * 2);
  matrix_scan();


  if (!is_keyboard_left()) {
      row = BOOTMAGIC_ROW_RIGHT;
      col = BOOTMAGIC_COLUMN_RIGHT;
  }    
  
  if (matrix_get_row(row) & (1 << col)) {
    // Jump to bootloader.
    bootloader_jump();
  }

  if (matrix_get_row(row) & (1 << (col+1))) {
    eeconfig_disable();
    // Jump to bootloader.
    bootloader_jump();
  }
}

void keyboard_post_init_user(void) {  
  is_rgb_enable = rgb_matrix_is_enabled();
}

void housekeeping_task_user(void) {
  static uint8_t state = 0;
  static uint32_t pre_time;

  switch(state)
  {  
    case 0:      
      if (rgb_matrix_is_enabled() != is_rgb_enable) {
        is_rgb_enable = rgb_matrix_is_enabled();
        pre_time = timer_read32();
        state = 1;
      }
      break;

    case 1:
      indicator_update();
      if (timer_read32()-pre_time >= 10)
      {        
        state = 0;
      }
      break;
  }
}

bool rgb_matrix_indicators_kb(void) {
  if (!rgb_matrix_indicators_user()) {
      return false;
  }
  if (is_keyboard_left()) 
  {     
    if (host_keyboard_led_state().caps_lock) {
      rgb_matrix_set_color(0, 0, rgb_matrix_get_val(), 0);
    }
    else {
      rgb_matrix_set_color(0, 0, 0, 0);
    } 
  }
  return true;
}

void indicator_update(void)
{
  if (is_keyboard_left()) 
  {    
    if (host_keyboard_led_state().caps_lock) {
      rgb_matrix_set_color(0, 0, rgb_matrix_get_val(), 0);
    }
    else {
      rgb_matrix_set_color(0, 0, 0, 0);
    }
    if (!rgb_matrix_is_enabled()) {
      rgb_matrix_driver.flush();
    }
  }
}

bool led_update_kb(led_t led_state) {
  indicator_update();
  return true;
}