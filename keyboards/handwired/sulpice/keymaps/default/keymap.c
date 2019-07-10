#include QMK_KEYBOARD_H
#include "version.h"

// Layers
#define LAYER_BASE 0
#define LAYER_NUMSYM 1
#define LAYER_FN 2
#define LAYER_MOUSE 3
#define LAYER_ARROWMED 4
#define LAYER_RESET 5

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_sulpice(
// Left hand

KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
ALL_T(KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           LT(LAYER_FN, KC_B),
                KC_LGUI,        KC_SPC,         KC_LCTL,        KC_LALT,        KC_NO, // thumb cluster


// Right hand

KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
LT(LAYER_MOUSE, KC_N), LT(LAYER_ARROWMED, KC_M), KC_COMM, KC_DOT, KC_SLSH,      KC_RSPC,
// TODO: reset should be on left hand (side with teensy), maybe?
MO(LAYER_RESET),KC_NO,          KC_MEH,         LT(LAYER_NUMSYM, KC_ENT), KC_BSPC

),
[LAYER_NUMSYM] = LAYOUT_sulpice(
// Left hand

KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
KC_NO,          KC_P1,          KC_P2,          KC_P3,          KC_P4,          KC_P5,
KC_TRNS,        KC_GRV,         KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRNS,
                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, // thumb cluster


// Right hand

KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LBRC,        KC_RBRC,        KC_BSLS,
KC_P6,          KC_P7,          KC_P8,          KC_P9,          KC_P0,          KC_ENT,
KC_TRNS,        KC_TRNS,        KC_PMNS,        KC_UNDS,        KC_PLUS,        KC_PEQL,
KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_DEL

),
[LAYER_FN] = LAYOUT_sulpice(
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
[LAYER_MOUSE] = LAYOUT_sulpice(
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
[LAYER_ARROWMED] = LAYOUT_sulpice(
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
[LAYER_RESET] = LAYOUT_sulpice(
// Left hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                KC_NO,          KC_NO,          KC_NO,          EEP_RST,        RESET, // thumb cluster


// Right hand

KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO //thumb cluster

)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
