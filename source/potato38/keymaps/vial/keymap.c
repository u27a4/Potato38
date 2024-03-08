// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST TG(_ADJUST)
#define LMGUI LM(_QWERTY,MOD_LGUI|MOD_RGUI)
#define OSMGUI OSM(MOD_LGUI|MOD_RGUI)
#define ALTENT RALT(KC_ENT)
#define SPC_FN1 LT(_LOWER,KC_SPC)
#define MTCTLE MT(MOD_LCTL|MOD_RCTL,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    MTCTLE,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_RSFT,
                                   KC_LALT,          SPC_FN1,          LOWER,            RAISE
    ),

    [_LOWER] = LAYOUT(
        KC_TAB,  _______, _______, _______, _______, _______, KC_F7,   KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV,  KC_BSPC, 
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_F5,   KC_LPRN, KC_RPRN, KC_SCLN, MTCTLE, 
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_UNDS, KC_EQL,  KC_QUOT, KC_SLSH, _______, 
                                   _______,          _______,          _______,          OSMGUI
    ),

    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_PSCR, _______, KC_PGUP, KC_PGDN, _______, KC_DEL, 
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_HOME, _______, KC_UP,   _______, ALTENT, 
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,_______, 
                                   _______,          _______,          ADJUST,           _______
    ),

    [_ADJUST] = LAYOUT(
        _______, RGB_TOG, RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, 
        KC_CAPS, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______,          KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, 
                                   _______,          _______,          _______,          _______
    )
};
