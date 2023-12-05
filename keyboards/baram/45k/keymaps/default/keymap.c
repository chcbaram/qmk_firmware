// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp | 
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Adjust| Ctrl | Alt  | GUI  |Lower |   Space     |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PENT,
        LM(2,MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MO(2),
        KC_LCTL, KC_LGUI, KC_LALT, LT(1,KC_SPC),           KC_SPC,                    MO(4),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_QUOT,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_LSFT,
        _______, _______, _______, _______,          KC_F18,                   MO(1)  , _______, _______, _______
    ),           
    [2] = LAYOUT(
        KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        LM(2,MOD_LSFT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,          KC_F18,                   MO(4), _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_M_B, RGB_M_P, _______, _______, _______, _______,
        KC_NO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
    ),        
    [4] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_M_B, RGB_M_P, KC_NO, KC_NO, KC_NO, KC_DEL,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, MO(5),
        KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,                   KC_NO, KC_HOME, KC_PGDN, KC_END
    ), 
    [5] = LAYOUT(
        QK_BOOTLOADER, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO
    ),   
    [6] = LAYOUT(
        QK_BOOTLOADER, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO
    ),                    
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) 
// {
//   if (record->event.pressed) 
//   {
//     char log_str[32];
//     snprintf(log_str, sizeof(log_str), "row:%d col:%d\n", record->event.key.row, record->event.key.col);
//     SEND_STRING(log_str);
//   }

//   return false;
// }