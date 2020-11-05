#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(PREONIC_SOUND)
  // #define STARTUP_SONG SONG(NO_SOUND)

  #define DEFAULT_LAYER_SONGS { SONG(COLEMAK_SOUND), \
                                SONG(QWERTY_SOUND) \
                              }
#endif

// Configure backlight
#undef  BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
