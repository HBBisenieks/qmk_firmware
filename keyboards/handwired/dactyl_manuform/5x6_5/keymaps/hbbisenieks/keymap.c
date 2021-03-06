#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PODCAST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  PODCAST,
  GUSR,
  HGRP,
  CHUS,
};

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

#define KC_RGBM RGB_MOD
#define KC_RGBT RGB_TOG

// Left and right shift as mot-tap square braces
#define KC_LSBR MT(MOD_LSFT, KC_LBRC)
#define KC_RSBR MT(MOD_RSFT, KC_RBRC)

// mod-tap shift/minus
#define KC_SMIN MT(MOD_LSFT, KC_MINS)

// Tap-toggle layers
#define KC_TT_L TT(1)
#define KC_TT_R TT(2)

#define KC_POD TG(3)

#define KC_SLOK LGUI(LCTL(KC_Q)) // mojave lock screen
#define KC_GUSR GUSR // "gam info user" macro
#define KC_HGRP HGRP // "history | grep" macro
#define KC_CHUS CHUS // "thisisunsafe" chrome browser macro

// CAGS home-row mods
#define KC_LCTA LCTL_T(KC_A)
#define KC_LOPS LALT_T(KC_S)
#define KC_LGUD LGUI_T(KC_D)
#define KC_LSFF LSFT_T(KC_F)
#define KC_RSFJ RSFT_T(KC_J)
#define KC_RGUK RGUI_T(KC_K)
#define KC_ROPL RALT_T(KC_L)
#define KC_RCTS RCTL_T(KC_SCLN)

// Audacity shortcuts
#define KC_SYNC LALT(KC_S)
#define KC_ZIN LCTL(KC_1)
#define KC_ZOUT LCTL(KC_3)
#define KC_ZNRM LCTL(KC_2) // zoom normal
#define KC_SAVE LCTL(KC_S) // save
#define KC_SLNC LCTL(KC_L) // silence selection

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6_5(
    //,-------+-------+-------+-------+-------+-------.                             ,-------+-------+-------+-------+-------+-------.
       KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                 KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINS,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
       KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                 KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_BSLS,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
       KC_ESC, KC_LCTA,KC_LOPS,KC_LGUD,KC_LSFF, KC_G,                                 KC_H,  KC_RSFJ,KC_RGUK,KC_ROPL,KC_RCTS,KC_QUOT,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
       KC_LSBR, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                 KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,KC_RSBR,
    //`-------+-------+-------+-------+---+---+---+---+---+-------.     ,-------+---+---+---+---+---+-------+-------+-------+-------/
                       KC_LBRC,KC_RBRC,    KC_DEL, KC_SMIN,KC_LGUI,      KC_ENT, KC_SPC, KC_BSPC,    KC_PLUS,KC_EQL,
    //                `-------+-------'   `-------+-------+-------|     |-------+-------+-------'   `-------+-------'
                                                   KC_LCTL,KC_TT_L,      KC_TT_R,KC_LALT
    //                                            `-------+-------'     `-------+-------'
  ),

  [_LOWER] = LAYOUT_5x6_5(
    //,-------+-------+-------+-------+-------+-------.                             ,-------+-------+-------+-------+-------+-------.
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO, KC_SLOK,  KC_NO, KC_UP,  KC_NO, KC_RGBT,                               KC_7,   KC_8,   KC_9,   KC_E,   KC_F,   KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_NO, KC_LEFT,KC_DOWN,KC_RGHT, KC_NO,                                KC_4,   KC_5,   KC_6,   KC_C,   KC_D,   KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_HGRP,KC_CHUS,                               KC_1,   KC_2,   KC_3,   KC_A,   KC_B,   KC_NO,
    //`-------+-------+-------+-------+---+---+---+---+---+-------.     ,-------+---+---+---+---+---+-------+-------+-------+-------/
                        KC_NO,  KC_NO,     KC_BSPC,KC_LGUI,KC_DEL,       KC_DOT, KC_COLN, KC_0,      KC_PLUS,KC_EQL,
    //                `-------+-------'   `-------+-------+-------|     |-------+-------+-------'   `-------+-------'
                                                   KC_LGUI,_______,      _______,KC_LALT
    //                                            `-------+-------'     `-------+-------'
  ),

  [_RAISE] = LAYOUT_5x6_5(
    //,-------+-------+-------+-------+-------+-------.                             ,-------+-------+-------+-------+-------+-------.
       KC_POD,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_F12,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
       KC_ESC, KC_CAPW,KC_CPYW,KC_CAPP,KC_CPYP, KC_G,                                 KC_H,   KC_J,  KC_VOLU,KC_MRWD,KC_MFFD, KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
       KC_LSBR,KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,                                 KC_N,   KC_M,  KC_VOLD,KC_MPLY,KC_MSTP, KC_NO,
    //`-------+-------+-------+-------+---+---+---+---+---+-------.     ,-------+---+---+---+---+---+-------+-------+-------+-------/
                       KC_F4,  KC_LALT,    KC_BSPC,KC_LGUI,KC_DEL,        KC_UP, KC_ENT, KC_SPC,     KC_PLUS,KC_EQL,
    //                `-------+-------'   `-------+-------+-------|     |-------+-------+-------'   `-------+-------'
                                                   KC_LGUI,_______,      _______,KC_LALT
    //                                            `-------+-------'     `-------+-------'
  ),

  [_PODCAST] = LAYOUT_5x6_5(
    //,-------+-------+-------+-------+-------+-------.                             ,-------+-------+-------+-------+-------+-------.
       KC_POD,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_NO, KC_ZOUT,KC_ZNRM,KC_ZIN, KC_COPY,                               KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_F12,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_NO, KC_LEFT,KC_SPC, KC_RGHT,KC_PSTE,                               KC_H,   KC_J,  KC_VOLU,KC_MRWD,KC_MFFD, KC_NO,
    //|-------+-------+-------+-------+-------+-------|                             |-------+-------+-------+-------+-------+-------|
        KC_NO,  KC_Z,   KC_X,   KC_C,   KC_V,  KC_CUT,                                KC_N,   KC_M,  KC_VOLD,KC_MPLY,KC_MSTP, KC_NO,
    //`-------+-------+-------+-------+---+---+---+---+---+-------.     ,-------+---+---+---+---+---+-------+-------+-------+-------/
                       KC_F4,  KC_LALT,    KC_BSPC,KC_SLNC,KC_SPC,        KC_UP, KC_ENT, KC_SPC,     KC_PLUS,KC_EQL,
    //                `-------+-------'   `-------+-------+-------|     |-------+-------+-------'   `-------+-------'
                                                   KC_SYNC,KC_SAVE,      _______,KC_LALT
    //                                            `-------+-------'     `-------+-------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUSR:
      if (record->event.pressed) {
        SEND_STRING("gam info user ");
      }
      break;
    case HGRP:
      if (record->event.pressed) {
        SEND_STRING("history|grep ");
      }
      break;
    case CHUS:
      if (record->event.pressed) {
        SEND_STRING("thisisunsafe");
      }
      break;
  }
  return true;
}
