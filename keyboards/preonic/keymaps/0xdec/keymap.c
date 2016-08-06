#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Layer names
#define _COLEMAK  0
#define _QWERTY   1
#define _GAME     2
#define _FN       3

#define SPC_SFT MT(MOD_LSFT, KC_SPC)

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAME,
  FN
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   =  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   -  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | TAB  | ALT  | GUI  | CTRL | BKSP |SPCSFT| FN   | LEFT | DOWN |  UP  | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSLS},
  {KC_EQL ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_G   ,KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_LBRC,KC_RBRC},
  {KC_MINS,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_D   ,KC_H   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT},
  {KC_SCLN,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_K   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_ENT },
  {KC_ESC ,KC_TAB ,KC_LALT,KC_LGUI,KC_LCTL,KC_BSPC,SPC_SFT,FN     ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT}
},

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   =  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   -  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | TAB  | ALT  | GUI  | CTRL | BKSP |SPCSFT| FN   | LEFT | DOWN |  UP  | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSLS},
  {KC_EQL ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_QUOT},
  {KC_MINS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_LBRC,KC_RBRC},
  {KC_SCLN,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_ENT },
  {KC_ESC ,KC_TAB ,KC_LALT,KC_LGUI,KC_LCTL,KC_BSPC,SPC_SFT,FN     ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT}
},

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |NUM LK|   ÷  |   ×  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   1  |   2  |   3  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | CTRL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   4  |   5  |   6  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | SHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   7  |   8  |   9  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      | GUI  | ALT  | SPACE| CTRL | BKSP | SPACE| FN   |   ,  |   0  |   .  | TAB  |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS},
  {KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_P1  ,KC_P2  ,KC_P3  ,KC_PPLS},
  {KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_P4  ,KC_P5  ,KC_P6  ,KC_PEQL},
  {KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PENT},
  {XXXXXXX,KC_LGUI,KC_LALT,KC_SPC ,KC_LCTL,KC_BSPC,KC_SPC ,FN     ,KC_PCMM,KC_P0  ,KC_PDOT,KC_TAB }
},

/* FN
 * ,-----------------------------------------------------------------------------------.
 * | SLEEP|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |PRTSCR|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SYM  |  F11 |  F12 |      |AU TOG|BL INC| VOL+ |COLMAK|QWERTY| GAME | MUSIC| PAUSE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |BL DEC| VOL- | PREV | STOP | PLAY | NEXT |SCRLCK|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |BL TOG| MUTE | BACK | STOP | RFRSH| FRWRD|INSERT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      | DEL  |      |      | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = {
  {KC_SLEP,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_PSCR},
  {XXXXXXX,KC_F11 ,KC_F12 ,_______,AU_TOG ,BL_INC ,KC_VOLU,COLEMAK,QWERTY ,GAME   ,MU_TOG ,KC_PAUS},
  {KC_CAPS,_______,_______,_______,_______,BL_DEC ,KC_VOLD,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT,KC_SLCK},
  {_______,_______,_______,_______,_______,BL_TOGG,KC_MUTE,KC_WBAK,KC_WSTP,KC_WREF,KC_WFWD,KC_INS },
  {RESET  ,_______,_______,_______,_______,KC_DEL ,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END }
}

};



#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_game[][2]    = {
  {NOTE_E6, 10}   ,{NOTE_E6, 10}  ,{NOTE_REST, 10} ,{NOTE_E6, 10}   ,
  {NOTE_REST, 10} ,{NOTE_C6, 10}  ,{NOTE_E6, 10}   ,{NOTE_REST, 10} ,
  {NOTE_G6, 10}   ,{NOTE_REST, 30},
  {NOTE_G5, 10}   ,{NOTE_REST, 30}
};
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void startup_user() {
  _delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}
void shutdown_user() {
  PLAY_SONG(tone_goodbye);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void) {
  music_scale_user();
}
void music_scale_user(void) {
  PLAY_SONG(music_scale);
}

#endif



void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
  startup_user();
  #endif
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_game);
        #endif
        persistent_default_layer_set(1UL<<_GAME);
      }
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      break;
    default:
      return true;
      break;
  }

  return false;
};
