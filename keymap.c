/*
 * chandanand's Ergodox EZ layout
 */

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,
    NAVR,
    FMDIA,
    NMBR,
    SYMB,
    FULL
};

#define XXXX KC_NO
#define ____ KC_TRNS

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

/* The Keymap */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------------------.           ,----------------------------------------------------.
 * |           |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |          |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+----------|
 * |           |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |          |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+----------|
 * |           |   A  |   R  |   S  |   T  |   D  |      |           |      |   H  |   N  |   E  |   I  |   O  |          |
 * |           |  CMD |  OPT |  CTL |  SFT |      |------|           |------|      |  SFT |  CTL |  OPT |  CMD |          |
 * |-----------+------+------+------+------+------| tmux |           | tmux |------+------+------+------+------+----------|
 * |           |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |          |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+----------'
 *   |         |      |      |      | Esc  |                                       |  Del |      |      |      |        |
 *   `-------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Backsp| Tab  |------|       |------|  Enter |Space |
 *                                 | NAVR | FMDIA|      |       |      |   SYMB | NMBR |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  XXXX,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,      TG(FULL),                      TG(FULL),            KC_6,           KC_7,           KC_8,           KC_9,      KC_0,       XXXX,
  XXXX,    KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,      XXXX,                      XXXX,            KC_J,           KC_L,           KC_U,           KC_Y,      KC_SCLN,    XXXX,
  XXXX,    CMD_T(KC_A),    OPT_T(KC_R),    CTL_T(KC_S),    SFT_T(KC_T),    KC_D,      				 		  KC_H,    SFT_T(KC_N),    CTL_T(KC_E),    OPT_T(KC_I),  CMD_T(KC_O),    XXXX,
  XXXX,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,      LCTL(KC_SPC),              LCTL(KC_SPC),    KC_K,           KC_M,           KC_COMM,        KC_DOT,    KC_SLSH,    XXXX,
  XXXX,    XXXX,           XXXX,           XXXX,           KC_ESC,                                                                                KC_DEL,         XXXX,           XXXX,      XXXX,       XXXX,
                                                                           XXXX,      XXXX,                      XXXX,            XXXX,
                                                                                      XXXX,                      XXXX,
                                           LT(NAVR, KC_BSPC), LT(FMDIA, KC_TAB),      XXXX,                      XXXX,            LT(SYMB, KC_ENT),   LT(NMBR, KC_SPC)
),

/* Keymap 1: Navigation layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |Reset |      |      |      |      |      |           |      |      | Undo | Cut  | Copy | Paste|           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  CMD | OPT  | CTRL | SFT  |      |------|           |------| Caps | Left | Down |  Up  | Left |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      | Ins  | Home | PgDn | PgUp | End  |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       | Del  |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------| Enter| Bksp |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[NAVR] = LAYOUT_ergodox_pretty(
  // left hand
  XXXX,    XXXX,        XXXX,        XXXX,        XXXX,        XXXX,    XXXX,                    XXXX,        XXXX,        XXXX,           XXXX,          XXXX,           XXXX,           XXXX,
  XXXX,    RESET,       XXXX,        XXXX,        XXXX,        XXXX,    XXXX,                    XXXX,        XXXX,        KC_MAC_UNDO,    KC_MAC_CUT,    KC_MAC_COPY,    KC_MAC_PASTE,   XXXX,
  XXXX,    KC_LCMD,     KC_LOPT,     KC_LCTL,     KC_LSFT,     XXXX,                                          KC_CAPS,     KC_LEFT,        KC_DOWN,       KC_UP,          KC_RGHT,        XXXX,
  XXXX,    XXXX,        XXXX,        XXXX,        XXXX,        XXXX,    XXXX,                    XXXX,        KC_INS,      KC_HOME,        KC_PGDN,       KC_PGUP,        KC_END,         XXXX,
  XXXX,    XXXX,        XXXX,        XXXX,        XXXX,                                                                    KC_DEL,         XXXX,           XXXX,          XXXX,           XXXX,
                                                               XXXX,    XXXX,                    XXXX,        XXXX,
                                                                        XXXX,                    XXXX,
                                                  ____,        XXXX,    XXXX,                    XXXX,        KC_ENT,      KC_BSPC
),

/* Keymap 2: Function and Media layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |Reset |      |      |      |      |      |           |      | LTog | LMod | LHue | LSpd | LVal |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  CMD | OPT  | CTRL | SFT  |      |------|           |------|      | Prvs |VolDwn| VolUp| Next |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       | Mute |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------|      | Play |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[FMDIA] = LAYOUT_ergodox_pretty(
  // left hand
  XXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,  XXXX,                    XXXX,        KC_F6,      KC_F7,         KC_F8,        KC_F9,         KC_F10,         XXXX,
  XXXX,    RESET,      XXXX,       XXXX,       XXXX,       XXXX,   XXXX,                    XXXX,        RGB_TOG,    RGB_MOD,       RGB_HUI,      RGB_SPI,       RGB_VAI,        XXXX,
  XXXX,    KC_LCMD,    KC_LOPT,    KC_LCTL,    KC_LSFT,    XXXX,                                         XXXX,       KC_MPRV,       KC_VOLD,      KC_VOLU,       KC_MNXT,        XXXX,
  XXXX,    XXXX,       XXXX,       XXXX,       XXXX,       XXXX,   XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
  XXXX,    XXXX,       XXXX,       XXXX,       XXXX,                                                                 KC_MUTE,       XXXX,         XXXX,          XXXX,           XXXX,
                                                           XXXX,   XXXX,                    XXXX,        XXXX,
                                                                   XXXX,                    XXXX,
                                               XXXX,       ____,   XXXX,                    XXXX,        XXXX,       KC_MPLY
),


/* Keymap 3: Numbers Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |  [   |  7   |  8   |  9   |  ]   |      |           |      |      |      |      |      | Reset|           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  '   |  4   |  5   |  6   |  =   |------|           |------|      | SFT  | CTRL |  OPT | CMD  |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  `   |  1   |  2   |  3   |  \   |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |  .   |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |  0   |  -   |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[NMBR] = LAYOUT_ergodox_pretty(
  // left hand
  XXXX,    XXXX,       XXXX,       XXXX,       XXXX,       XXXX,   XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
  XXXX,    KC_LBRC,    KC_7,       KC_8,       KC_9,       KC_RBRC,XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          RESET,          XXXX,
  XXXX,    KC_QUOT,    KC_4,       KC_5,       KC_6,       KC_EQL,                                       XXXX,       KC_LSFT,       KC_LCTL,      KC_LOPT,       KC_LCMD,        XXXX,
  XXXX,    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_BSLS,XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
  XXXX,    XXXX,       XXXX,       XXXX,       KC_DOT,                                                               XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
                                                           XXXX,   XXXX,                    XXXX,        XXXX,
                                                                   XXXX,                    XXXX,
                                               KC_0,       KC_MINS,XXXX,                    XXXX,        XXXX,       ____
),

/* Keymap 4: Symbols Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |  {   |  &   |  *   |  (   |  }   |      |           |      |      |      |      |      | Reset|           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  "   |  $   |  %   |  ^   |  +   |------|           |------|      | SFT  | CTRL |  OPT | CMD  |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  ~   |  !   |  @   |  #   |  |   |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |  (   |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |  )   |  _   |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  XXXX,    XXXX,       XXXX,       XXXX,       XXXX,       XXXX,   XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
  XXXX,    KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          RESET,          XXXX,
  XXXX,    KC_DQUO,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_PLUS,                                      XXXX,       KC_LSFT,       KC_LCTL,      KC_LOPT,       KC_LCMD,        XXXX,
  XXXX,    KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_PIPE,XXXX,                    XXXX,        XXXX,       XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
  XXXX,    XXXX,       XXXX,       XXXX,       KC_LPRN,                                                              XXXX,          XXXX,         XXXX,          XXXX,           XXXX,
                                                           XXXX,   XXXX,                    XXXX,        XXXX,
                                                                   XXXX,                    XXXX,
                                               KC_RPRN,    KC_UNDS,XXXX,                    XXXX,        ____,       XXXX
),
/* Keymap 5: Full layer
 *
 * ,-----------------------------------------------------.           ,----------------------------------------------------.
 * | `         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  -       |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+----------|
 * | =         |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |  \       |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+----------|
 * |           |   A  |   R  |   S  |   T  |   D  |      |           |      |   H  |   N  |   E  |   I  |   O  |  '       |
 * |           |      |      |      |      |      |------|           |------|      |      |      |      |      |          |
 * |-----------+------+------+------+------+------| tmux |           | tmux |------+------+------+------+------+----------|
 * | SFT       |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |     SFT  |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+----------'
 *   | CTL     | OPT  | CMD  |      | Esc  |                                       |  Del |      |  CMD |  OPT | CTL |
 *   `-------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Backsp| Tab  |------|       |------|  Enter |Space |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[FULL] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,      TG(FULL),                      TG(FULL),            KC_6,           KC_7,           KC_8,           KC_9,      KC_0,       KC_MINS,
  KC_EQL,      KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,      XXXX,                      XXXX,            KC_J,           KC_L,           KC_U,           KC_Y,      KC_SCLN,    KC_BSLS,
  KC_ESC,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,                                                  KC_H,           KC_N,           KC_E,           KC_I,      KC_O,       KC_QUOT,
  KC_LSFT,     KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,      LCTL(KC_SPC),              LCTL(KC_SPC),    KC_K,           KC_M,           KC_COMM,        KC_DOT,    KC_SLSH,    KC_RSFT,
  KC_LCTL,     KC_LOPT,        KC_LCMD,        XXXX,           KC_ESC,                                                                                KC_DEL,         XXXX,           KC_RCMD,   KC_ROPT,    KC_RCTL,
                                                                           XXXX,      XXXX,                      XXXX,            XXXX,
                                                                                      XXXX,                      XXXX,
                                           KC_BSPC, KC_TAB,      XXXX,                      XXXX,            KC_ENT,   KC_SPC
),

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  ergodox_led_all_off();
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case BASE:
        break;
      case NMBR:
        ergodox_right_led_1_on();
        break;
      case SYMB:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case NAVR:
        ergodox_right_led_3_on();
        break;
      case FMDIA:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case FULL:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
