/*
Copyright 2018-2020 Jordi Pakey-Rodriguez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum novelpad_keycodes {
  EQL_TOG = SAFE_RANGE,
  COM_TOG
};

typedef union {
  uint32_t raw;
  struct {
    bool keypad_equal : 1;
    bool keypad_comma : 1;
  };
} user_config_t;

user_config_t user_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Navigation (when Num Lock is off)
 *,-------------------------------.
 *| NUMLK |   (   |   )   |   %   |
 *|-------+-------+-------+-------|
 *| HOME  |  UP   | PG UP |   ^   |
 *|-------+-------+-------+-------|
 *| LEFT  | DOWN  | RIGHT | CALC  |
 *|-------+-------+-------+-------|
 *|  END  | DOWN  | PG DN | SPACE |
 *|-------+-------+-------+-------|
 *|  INS  | BKSPC |  DEL  |  ESC  |
 *`-------------------------------'
 */

/* Numeric
 *,-------------------------------.
 *| NUMLK |   /   |   *   |   -   |
 *|-------+-------+-------+-------|
 *|   7   |   8   |   9   |   +   |
 *|-------+-------+-------+-------|
 *|   4   |   5   |   6   |   =   |
 *|-------+-------+-------+-------|
 *|   1   |   2   |   3   |  TAB  |
 *|-------+-------+-------+-------|
 *|   0   |   ,   |   .   | ENTER |
 *`-------------------------------'
 */
[0] = LAYOUT(
  LT(1, KC_NLCK),KC_PSLS,KC_PAST,KC_PMNS,
  KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,
  KC_P4  ,KC_P5  ,KC_P6  ,KC_PEQL,
  KC_P1  ,KC_P2  ,KC_P3  ,KC_TAB ,
  KC_P0  ,KC_PCMM,KC_PDOT,KC_PENT
),

/* Function
 *,-------------------------------.
 *|       |       |       |       |
 *|-------+-------+-------+-------|
 *|RGB TOG|RGB MOD|BL STEP|       |
 *|-------+-------+-------+-------|
 *|  HUE+ |  SAT+ |  VAL+ | =/PEQL|
 *|-------+-------+-------+-------|
 *|  HUE- |  SAT- |  VAL- |       |
 *|-------+-------+-------+-------|
 *| RESET | ,/PCMM|       |       |
 *`-------------------------------'
 */
[1] = LAYOUT(
  _______,XXXXXXX,XXXXXXX,XXXXXXX,
  RGB_TOG,RGB_MOD,BL_STEP,XXXXXXX,
  RGB_HUI,RGB_SAI,RGB_VAI,EQL_TOG,
  RGB_HUD,RGB_SAD,RGB_VAD,XXXXXXX,
  RESET  ,COM_TOG,XXXXXXX,XXXXXXX
)

};

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.keypad_equal = 1; // Enable keypad equal by default
  user_config.keypad_comma = 1; // Enable keypad comma by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user(); // Read the user config from EEPROM
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  led_t led_state = host_keyboard_led_state();
  uint16_t new_keycode = 0;

  switch (keycode) {
  case KC_NLCK:
    clear_keyboard(); // Unregister everything to avoid stuck keys
    break;
  case EQL_TOG:
    // Configure whether the keypad sends KC_PEQL (default) or KC_EQUAL
    if (record->event.pressed) {
      user_config.keypad_equal ^= 1; // Toggle the keypad equal config
      eeconfig_update_user(user_config.raw); // Write the user config to EEPROM
    }
    return false;
  case COM_TOG:
    // Configure whether the keypad sends KC_PCMM (default) or KC_COMMA
    if (record->event.pressed) {
      user_config.keypad_comma ^= 1; // Toggle the keypad comma config
      eeconfig_update_user(user_config.raw); // Write the user config to EEPROM
    }
    return false;
  }

  // Swap keycodes when Num Lock is off
  if (!led_state.num_lock) {
    switch (keycode) {
    case KC_PSLS:             // /
      new_keycode = KC_LPRN;  // (
      break;
    case KC_PAST:             // *
      new_keycode = KC_RPRN;  // )
      break;
    case KC_PMNS:             // -
      new_keycode = KC_PERC;  // %
      break;
    case KC_PPLS:             // +
      new_keycode = KC_CIRC;  // ^
      break;
    case KC_PEQL:             // =
      new_keycode = KC_CALC;  // CALC
      break;
    case KC_TAB:              // TAB
      new_keycode = KC_SPC;   // SPACE
      break;
    case KC_PENT:             // ENTER
      new_keycode = KC_ESC;   // ESC
      break;
    case KC_PCMM:             // ,
      new_keycode = KC_BSPC;  // BKSPC
      break;
    case KC_P5:               // 5
      new_keycode = KC_DOWN;  // DOWN
      break;
    }
  } else if (keycode == KC_PEQL && !user_config.keypad_equal) {
    new_keycode = KC_EQUAL; // Use standard equal instead of keypad equal
  } else if (keycode == KC_PCMM && !user_config.keypad_comma) {
    new_keycode = KC_COMMA; // Use standard comma instead of keypad comma
  }

  // Un/register new keycode if modified
  if (new_keycode) {
    if (record->event.pressed) {
      register_code16(new_keycode);
    } else {
      unregister_code16(new_keycode);
    }
    return false;
  }

  return true;
}

// bool led_update_user(led_t led_state) {
//   if (led_state.num_lock) {}
//   return true;
// }
