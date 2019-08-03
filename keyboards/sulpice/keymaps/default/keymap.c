/* Copyright 2019 Andrew Suzuki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layers
#define LAYER_BASE_QWERTY 0
#define LAYER_BASE_WORKMAN 1
#define LAYER_NUMSYM 2
#define LAYER_FN 3
#define LAYER_MOUSE 4
#define LAYER_ARROWMED 5
#define LAYER_RESET 6

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE_QWERTY] = LAYOUT(
// Left hand

KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
ALL_T(KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           LT(LAYER_FN, KC_B),
                KC_LGUI,        KC_SPC,         KC_LCTL,        KC_LALT,        KC_NO, // thumb cluster


// Right hand

KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
LT(LAYER_MOUSE, KC_N), LT(LAYER_ARROWMED, KC_M), KC_COMM, KC_DOT, KC_SLSH,      KC_RSPC,
MO(LAYER_RESET),KC_NO,          KC_MEH,         LT(LAYER_NUMSYM, KC_ENT), KC_BSPC
),
[LAYER_BASE_WORKMAN] = LAYOUT(
// TODO make workman
// Left hand

KC_TAB,         KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,
ALL_T(KC_ESC),  KC_A,           KC_S,           KC_H,           KC_T,           KC_G,
KC_LSPO,        KC_Z,           KC_X,           KC_M,           KC_C,           LT(LAYER_FN, KC_V),
                KC_LGUI,        KC_SPC,         KC_LCTL,        KC_LALT,        KC_NO, // thumb cluster


// Right hand

KC_J,           KC_F,           KC_U,           KC_P,           KC_SCLN,        KC_NO,
KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_QUOT,
LT(LAYER_MOUSE, KC_K), LT(LAYER_ARROWMED, KC_L), KC_COMM, KC_DOT, KC_SLSH,      KC_RSPC,
MO(LAYER_RESET),KC_NO,          KC_MEH,         LT(LAYER_NUMSYM, KC_ENT), KC_BSPC
),
[LAYER_NUMSYM] = LAYOUT(
// Left hand

KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
KC_TRNS,        KC_GRV,         KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRNS,
                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, // thumb cluster


// Right hand

KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LBRC,        KC_RBRC,        KC_BSLS,
KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_ENT,
KC_TRNS,        KC_TRNS,        KC_PMNS,        KC_UNDS,        KC_PLUS,        KC_PEQL,
KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_DEL

),
[LAYER_FN] = LAYOUT(
// Left hand

KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, // thumb cluster


// Right hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO //thumb cluster

),
[LAYER_MOUSE] = LAYOUT(
// Left hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, // thumb cluster


// Right hand

KC_NO,          KC_BTN1,        KC_BTN2,        KC_BTN3,        KC_WH_U,        KC_NO,
KC_MS_L,        KC_MS_D,        KC_MS_U,        KC_MS_R,        KC_WH_D,        KC_NO,
KC_TRNS,        KC_TRNS,        KC_ACL0,        KC_ACL1,        KC_ACL2,        KC_NO,
KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO //thumb cluster

),
[LAYER_ARROWMED] = LAYOUT(
// Left hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, // thumb cluster


// Right hand

KC_MPRV,        KC_MPLY,        KC_MUTE,        KC_MNXT,        KC_NO,          KC_PWR,
KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_NO,          KC_NO,
KC_NO,          KC_TRNS,        KC_VOLD,        KC_VOLU,        KC_NO,          KC_NO,
KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO //thumb cluster

),
[LAYER_RESET] = LAYOUT(
// Left hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                KC_NO,          DF(LAYER_BASE_QWERTY), DF(LAYER_BASE_WORKMAN), EEP_RST, RESET, // thumb cluster


// Right hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO //thumb cluster

)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
