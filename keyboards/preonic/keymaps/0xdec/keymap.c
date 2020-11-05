#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FN
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *,-----------------------------------------------------------------------------------------------.
 *|   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|  TAB  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   =   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| CTRL  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| SHIFT |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | SHIFT |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|  ESC  |  FN   |  GUI  |  ALT  | LOWER | SPACE | SPACE | RAISE | LEFT  | DOWN  |  UP   | RIGHT |
 *`-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS, \
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_EQL , \
  KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT, \
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,RSFT_T(KC_ENT), \
  KC_ESC ,MO(_FN),KC_LGUI,KC_LALT,LOWER  ,KC_SPC ,KC_SPC ,RAISE  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT  \
),

/* Colemak
 *,-----------------------------------------------------------------------------------------------.
 *|   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|  TAB  |   Q   |   W   |   F   |   P   |   G   |   J   |   L   |   U   |   Y   |   ;   |   =   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| CTRL  |   A   |   R   |   S   |   T   |   D   |   H   |   N   |   E   |   I   |   O   |   '   |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| SHIFT |   Z   |   X   |   C   |   V   |   B   |   K   |   M   |   ,   |   .   |   /   | SHIFT |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|  ESC  |  FN   |  GUI  |  ALT  | LOWER | SPACE | SPACE | RAISE | LEFT  | DOWN  |  UP   | RIGHT |
 *`-----------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS, \
  KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_G   ,KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_EQL , \
  KC_LCTL,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_D   ,KC_H   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT, \
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_K   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,RSFT_T(KC_ENT), \
  KC_ESC ,MO(_FN),KC_LGUI,KC_LALT,LOWER  ,KC_SPC ,KC_SPC ,RAISE  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT  \
),

/* Lower
 *,-----------------------------------------------------------------------------------------------.
 *|  ESC  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  | BKSPC |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       | PRTSCR|       |       |   {   |   }   |   |   |       |  DEL  |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       |       |       |       |   [   |   ]   |   \   |       | BKSPC |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       |       | PAUSE |  INS  | MENU  |       |       |       |       |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| POWER |       |       |       |       |       |  DEL  |       | HOME  | PGDN  | PGUP  |  END  |
 *`-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_ESC ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_BSPC, \
  _______,_______,_______,_______,KC_PSCR,_______,_______,KC_LCBR,KC_RCBR,KC_PIPE,_______,KC_DEL , \
  _______,_______,_______,_______,_______,_______,_______,KC_LBRC,KC_RBRC,KC_BSLS,_______,KC_BSPC, \
  _______,_______,_______,_______,_______,KC_PAUS,KC_INS ,KC_MENU,_______,_______,_______,_______, \
  KC_PWR ,_______,_______,_______,_______,_______,KC_DEL ,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END   \
),

/* Raise
 *,-----------------------------------------------------------------------------------------------.
 *|  ESC  |  F11  |  F12  |  F13  |  F14  |  F15  |  F16  |  F17  |  F18  |  F19  |  F20  | BKSPC |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       | PRTSCR|       |       |   {   |   }   |   |   |       |  DEL  |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       |       |       |       |   [   |   ]   |   \   |       | BKSPC |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |       |       | PAUSE |  INS  | MENU  |       |       |       |       |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| POWER |       |       |       |       | BKSPC |       |       | HOME  | PGDN  | PGUP  |  END  |
 *`-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_ESC ,KC_F11 ,KC_F12 ,KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,KC_F18 ,KC_F19 ,KC_F20 ,KC_BSPC, \
  _______,_______,_______,_______,KC_PSCR,_______,_______,KC_LCBR,KC_RCBR,KC_PIPE,_______,KC_DEL , \
  _______,_______,_______,_______,_______,_______,_______,KC_LBRC,KC_RBRC,KC_BSLS,_______,KC_BSPC, \
  _______,_______,_______,_______,_______,KC_PAUS,KC_INS ,KC_MENU,_______,_______,_______,_______, \
  KC_PWR ,_______,_______,_______,_______,KC_BSPC,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END   \
),

/* Function
 *,-----------------------------------------------------------------------------------------------.
 *| SLEEP | MUTE  |VOL DN |VOL UP | PREV  | PLAY  | NEXT  | EXEC  |BL STEP| BR DN | BR UP |       |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       | QWERTY| WAKE  |       |       |       |       |MS BTN1|MS BTN2|MS BTN3|MS BTN4|MS BTN5|
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| CAPS  | AUDIO |SCRLOCK|       |       |       |HIBERN8|MOUSE L|MOUSE D|MOUSE U|MOUSE R|       |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *|       |       |       |COLEMAK|       |BREATHE|       |MS WHLL|MS WHLD|MS WHLU|MS WHLR|       |
 *|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *| RESET |       |       |       |       |       |       |       | BACK  | STOP  |REFRESH|FORWARD|
 *`-----------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid( \
  KC_SLEP,KC_MUTE,KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,KC_EXEC,BL_STEP,KC_BRID,KC_BRIU,_______, \
  _______,QWERTY ,KC_WAKE,_______,_______,_______,_______,KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5, \
  KC_CAPS,AU_TOG ,KC_SLCK,_______,_______,_______,KC_PWR ,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______, \
  _______,_______,_______,COLEMAK,_______,BL_BRTG,_______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______, \
  RESET  ,_______,_______,_______,_______,_______,_______,_______,KC_WBAK,KC_WSTP,KC_WREF,KC_WFWD  \
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        // update_tri_layer(_LOWER, _RAISE, _FN);
      } else {
        layer_off(_LOWER);
        // update_tri_layer(_LOWER, _RAISE, _FN);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        // update_tri_layer(_LOWER, _RAISE, _FN);
      } else {
        layer_off(_RAISE);
        // update_tri_layer(_LOWER, _RAISE, _FN);
      }
      return false;
      break;
  }
  return true;
}
