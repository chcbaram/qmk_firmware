// Copyright 2025 Andrew Kannan (awkannan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_P1,    KC_P2,    KC_P3,    
  KC_P4,    KC_P5,    KC_P6,  
  KC_P7,    KC_P8,    KC_P9,    
  KC_PDOT,  KC_P0,    KC_PENT,   
  KC_PMNS,  KC_PPLS,  KC_EQL
)
};



void bootmagic_scan(void) {
  matrix_scan();
  wait_ms(DEBOUNCE * 2);
  matrix_scan();

  if (matrix_get_row(BOOTMAGIC_ROW) & (1 << BOOTMAGIC_COLUMN)) {
    // Jump to bootloader.
    bootloader_jump();
  }
}
