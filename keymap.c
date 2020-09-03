/*
 * chandanand's Ergodox EZ layout
 */

#include <stdarg.h>
#include QMK_KEYBOARD_H
#include "led.h"
#include "version.h"
#include "action_layer.h"
#include "action_util.h"
#include "print.h"
#include "wait.h"

enum layers {
    BASE = 0,
    ARRW,
    FMDIA,
    WIN,
};

enum custom_keycodes {
    CT_TA,
    CT_LBP,
    CT_RBP,
    CT_SR,
};

#define KC_WIN_FULLSCREEN C(G(KC_F))
#define KC_WIN_MAXIMIZE A(G(KC_F))
#define KC_WIN_ALMOST_MAXIMIZE C(A(G(KC_F)))
#define KC_WIN_CENTER A(G(KC_C))
#define KC_WIN_SMALLER C(A(S(KC_LEFT)))
#define KC_WIN_LARGER C(A(S(KC_RGHT)))
#define KC_WIN_NEXT_DISPLAY C(A(G(KC_RGHT)))
#define KC_WIN_PREV_DISPLAY C(A(G(KC_LEFT)))
#define KC_WIN_TOP_LEFT C(G(KC_LEFT))
#define KC_WIN_TOP_RIGHT C(G(KC_RGHT))
#define KC_WIN_BOTTOM_LEFT C(S(G(KC_LEFT)))
#define KC_WIN_BOTTOM_RIGHT C(S(G(KC_RGHT)))
#define KC_WIN_LEFT_HALF A(G(KC_LEFT))
#define KC_WIN_RIGHT_HALF A(G(KC_RGHT))
#define KC_WIN_TOP_HALF A(G(KC_UP))
#define KC_WIN_BOTTOM_HALF A(G(KC_DOWN))

/* States & timers */

bool skip_leds = false;

/* The Keymap */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------------------.           ,----------------------------------------------------.
 * |           |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |          |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+----------|
 * |         ~ |   Q  |   W  |   F  |   P  |   B  |  (   |           |   )  |   J  |   L  |   U  |   Y  |   ;  | \        |
 * |-----------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+----------|
 * | Tab/ARROW |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  | '        |
 * |-----------+------+------+------+------+------| tmux |           | tmux |------+------+------+------+------+----------|
 * | Play/Pause|   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  |Stop/Reset|
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+----------'
 *   |         |      |      |      |   =  |                                       |   -  |      |      |      |        |
 *   `-------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | Del  |       | FMDIA| WIN    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Ctrl |       | LEAD |              |
 *                                 |Backsp|LShift|------|       |------|  Enter |Space |
 *                                 |      |      | Esc  |       | LGUI |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,       KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_NO,            KC_NO,        KC_6,      KC_7,    KC_8,      KC_9,     KC_0,      KC_NO,
  KC_GRV,      KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,   TD(CT_LBP),       TD(CT_RBP),   KC_J,      KC_L,    KC_U,      KC_Y,     KC_SCLN,   KC_BSLS,
  TD(CT_TA),   KC_A,    KC_R,    KC_S,    KC_T,     KC_G,                                   KC_M,      KC_N,    KC_E,      KC_I,     KC_O,      KC_QUOT,
  KC_MPLY,     KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,   LCTL(KC_SPC),     LCTL(KC_SPC), KC_K,      KC_H,    KC_COMM,   KC_DOT,   KC_SLSH,   TD(CT_SR),
  KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_EQL,                                           KC_MINS,   KC_NO,   KC_NO,     KC_NO,    KC_NO,
                                                OSM(MOD_LALT),  KC_DEL,       OSL(FMDIA),   OSL(WIN),
                                                         OSM(MOD_LCTL),       KC_LEAD,
                                        KC_BSPC, OSM(MOD_LSFT), KC_ESC,       KC_LGUI,        KC_ENT,    KC_SPC
),

/* Keymap 1: Arrow layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      | Down |Right |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |  Up  | Left |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |             |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[ARRW] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_UP,   KC_LEFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Function and Media layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  | F11       |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      | F12       |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      |      |LtDec |LtInc |LtTog |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |LtPrev|LtNext|      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------|VolDn |VolUp |
 *                                  |      |      |      |           | Mute |      |      |
 *                                  `--------------------'           `--------------------'
 */
[FMDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,      KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, RGB_TOG, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_MOD, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                        KC_TRNS,      KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_MUTE, KC_VOLD, KC_VOLU
),

/* Keymap 3: Windows layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |FulScn|      |      |PrvDis|           |NxtDis|   Up | Rght |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |AstMax|      |      |      |      |------|           |------|Maxim |      |      |      |      |           |
 * |-----------+------+------+------+------+------|Smalr |           |Largr |------+------+------+------+------+-----------|
 * |           |      |      | Cntr |      |      |      |           |      | Down | Left |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      | LUC  |           | RUC  |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | LDC  |           | RDC  |      |      |
 *                                  |      |      |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[WIN] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_WIN_FULLSCREEN, KC_TRNS, KC_TRNS, KC_WIN_PREV_DISPLAY,      KC_WIN_NEXT_DISPLAY, KC_WIN_BOTTOM_HALF, KC_WIN_RIGHT_HALF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_WIN_ALMOST_MAXIMIZE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_WIN_MAXIMIZE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_WIN_CENTER, KC_TRNS, KC_TRNS, KC_WIN_SMALLER,      KC_WIN_LARGER, KC_WIN_TOP_HALF, KC_WIN_LEFT_HALF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_WIN_TOP_LEFT,      KC_WIN_TOP_RIGHT, KC_TRNS,
                                                        KC_WIN_BOTTOM_LEFT,      KC_WIN_BOTTOM_RIGHT,
                                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  wait_ms(1000);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i);
    wait_ms (10);
  }
  ergodox_led_all_off();
};

LEADER_EXTERNS();

typedef struct {
  bool layer_toggle;
  bool sticky;
} td_ta_state_t;

static void _td_ta_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_ta_state_t *td_ta = (td_ta_state_t *) user_data;

  if (td_ta->sticky) {
    td_ta->sticky = false;
    td_ta->layer_toggle = false;
    layer_off (ARRW);
    return;
  }

  if (state->count == 1 && !state->pressed) {
    register_code (KC_TAB);
    td_ta->sticky = false;
    td_ta->layer_toggle = false;
  } else {
    td_ta->layer_toggle = true;
    layer_on (ARRW);
    td_ta->sticky = (state->count == 2);
  }
}

static void _td_ta_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_ta_state_t *td_ta = (td_ta_state_t *) user_data;

  if (!td_ta->layer_toggle)
    unregister_code (KC_TAB);
  if (!td_ta->sticky)
    layer_off (ARRW);
}

static void
_td_sr_each (qk_tap_dance_state_t *state, void *user_data) {
  skip_leds = true;

  switch (state->count) {
  case 1:
    ergodox_right_led_3_on ();
    break;
  case 2:
    ergodox_right_led_2_on ();
    break;
  case 3:
    ergodox_right_led_1_on ();
    break;
  case 4:
    ergodox_right_led_3_off ();
    wait_ms (50);
    ergodox_right_led_2_off ();
    wait_ms (50);
    ergodox_right_led_1_off ();
    break;
  }
}

static void
_td_sr_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    wait_ms (1000);
    reset_keyboard ();
    reset_tap_dance (state);
  }
}

static void
_td_sr_reset (qk_tap_dance_state_t *state, void *user_data) {
  ergodox_right_led_1_off ();
  wait_ms (50);
  ergodox_right_led_2_off ();
  wait_ms (50);
  ergodox_right_led_3_off ();
  skip_leds = false;
}

static void
_td_brackets_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(CT_LBP))
      register_code16 (KC_LBRC);
    else
      register_code16 (KC_RBRC);
  } else if (state->count == 2) {
    if (state->keycode == TD(CT_LBP))
      register_code16 (KC_LPRN);
    else
      register_code16 (KC_RPRN);
  }
}

static void
_td_brackets_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(CT_LBP))
      unregister_code16 (KC_LBRC);
    else
      unregister_code16 (KC_RBRC);
  } else if (state->count == 2) {
    if (state->keycode == TD(CT_LBP))
      unregister_code16 (KC_LPRN);
    else
      unregister_code16 (KC_RPRN);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_TA]  = {
        .fn = { NULL, _td_ta_finished, _td_ta_reset },
        .user_data = (void *)&((td_ta_state_t) { false, false })
    },
    [CT_LBP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_RBP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, _td_brackets_finished, _td_brackets_reset),
    [CT_SR]  = ACTION_TAP_DANCE_FN_ADVANCED (_td_sr_each, _td_sr_finished, _td_sr_reset)
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  bool is_arrow = false;

  if (!skip_leds) {
    if (layer == FMDIA) {
      ergodox_right_led_2_on ();
      ergodox_right_led_3_on ();
    } else if (layer == WIN) {
      ergodox_right_led_1_on ();
      ergodox_right_led_2_on ();
    }
  }

  if (layer_state & (1UL << ARRW)) {
    if (!skip_leds) {
      ergodox_right_led_1_on ();
      ergodox_right_led_3_on ();
    }
    is_arrow = true;
  }


  if (!skip_leds) {
    if (keyboard_report->mods & MOD_BIT(KC_LSFT) ||
        ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
      ergodox_right_led_1_set (LED_BRIGHTNESS_HI);
      ergodox_right_led_1_on ();
    } else {
      ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
      if (layer != WIN && !is_arrow)
        ergodox_right_led_1_off ();
    }

    if (keyboard_report->mods & MOD_BIT(KC_LALT) ||
        ((get_oneshot_mods() & MOD_BIT(KC_LALT)) && !has_oneshot_mods_timed_out())) {
      ergodox_right_led_2_set (LED_BRIGHTNESS_HI);
      ergodox_right_led_2_on ();
    } else {
      ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
      if (layer != FMDIA && layer != WIN)
        ergodox_right_led_2_off ();
    }

    if (keyboard_report->mods & MOD_BIT(KC_LCTRL) ||
        ((get_oneshot_mods() & MOD_BIT(KC_LCTRL)) && !has_oneshot_mods_timed_out())) {
      ergodox_right_led_3_set (LED_BRIGHTNESS_HI);
      ergodox_right_led_3_on ();
    } else {
      ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
      if (layer != FMDIA && !is_arrow)
        ergodox_right_led_3_off ();
    }
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end ();

    SEQ_ONE_KEY (KC_V) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ (" QMK_VERSION ")");
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_ESC && record->event.pressed) {
    bool queue = true;

    if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
      clear_oneshot_mods ();
      queue = false;
    }
    return queue;
  }

  return true;
}
