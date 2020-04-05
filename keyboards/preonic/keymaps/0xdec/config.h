#pragma once

#ifdef AUDIO_ENABLE
    #define MARIO_SOUND \
        Q__NOTE(_E6   ), \
        Q__NOTE(_E6   ), \
        Q__NOTE(_REST ), \
        Q__NOTE(_E6   ), \
        Q__NOTE(_REST ), \
        Q__NOTE(_C6   ), \
        Q__NOTE(_E6   ), \
        Q__NOTE(_REST ), \
        Q__NOTE(_G6   ), \
        HD_NOTE(_REST ), \
        Q__NOTE(_G5   ), \
        HD_NOTE(_REST ),

      #define STARTUP_SONG SONG(PREONIC_SOUND)
      // #define STARTUP_SONG SONG(NO_SOUND)

      #define DEFAULT_LAYER_SONGS { SONG(COLEMAK_SOUND), \
                                    SONG(QWERTY_SOUND), \
                                    SONG(MARIO_SOUND) \
                                  }
#endif

#define MUSIC_MASK (keycode != KC_NO)

// Number of backlight levels
#undef  BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
