#pragma once

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// RGB effects on keypresses
#define RGB_MATRIX_KEYPRESSES
