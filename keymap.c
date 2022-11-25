#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"
#include "oled.c"
#include "logics.c"
// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	  [_NEO] = LAYOUT(
      KC_ESC,         DE_X,   DE_V,   DE_L,   DE_C,   DE_W,                   /*|*/                  DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_SS,
      LSFT_T(KC_TAB), DE_U,   DE_I,   DE_A,   DE_E,   DE_O,                   /*|*/                  DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTRL,       DE_UE,  DE_OE,  DE_AE,  DE_P,   DE_Z, KC_NO, KC_MUTE, /*|*/ KC_NO, KC_NO,DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                                 KC_LGUI, MO(_SYM),KC_LALT, KC_SPC, MO(_NUM), /*|*/ MO(_SYM), LSFT_T(KC_ENT), KC_LALT, MO(_NUM), KC_NO
    ),

      [_NUM] = LAYOUT(
      _______,    KC_PGUP,  KC_BSPC,   KC_UP,    KC_DEL,   KC_PGDN,                   /*|*/                  KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_PEQL,
      KC_ENT,     KC_HOME,  KC_LEFT,   KC_DOWN,  KC_RIGHT, KC_END,                    /*|*/                  KC_PSLS, KC_4, KC_5, KC_6, KC_PPLS, KC_NO,
      LALT(KC_S), KC_AGAIN, LCA(DE_R), S(KC_F5), KC_F12,   KC_PGUP, _______, _______, /*|*/ _______, _______,KC_0,    KC_1, KC_2, KC_3, KC_NO, KC_NO,
                                           _______, _______,_______,_______, _______, /*|*/ _______, _______, _______, KC_PDOT, KC_PCMM
    ),

      [_SYM] = LAYOUT(
      _______, DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                  /*|*/                  DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
      _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                  /*|*/                  DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_EURO,
      _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV, _______, _______, /*|*/ _______, _______,DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, TG(_GAME),
                                _______, _______, _______, _______, _______, /*|*/ _______, _______, _______, _______, _______
    ),

	  [_GAME] = LAYOUT(
      KC_ESC,  DE_X,    DE_V,   DE_L,    DE_C,   DE_W,                   /*|*/                  DE_K, DE_H, DE_G,    DE_F,   DE_Q, DE_CIRC,
      KC_LSFT, DE_U,    DE_I,   DE_A,    DE_E,   DE_O,                   /*|*/                  DE_S, DE_N, DE_R,    DE_T,   DE_D, DE_Y,
      KC_LCTL, DE_COMM, DE_DOT, DE_SCLN, DE_P,   DE_Z, _______, _______, /*|*/ _______, _______,DE_B, DE_M, DE_COMM, DE_DOT, DE_J, DE_MINS,
                    LSFT(DE_U), LSFT(DE_V), KC_TAB, KC_SPC, MO(_WEAPON), /*|*/ MO(_SYM), KC_ENT, KC_LALT, MO(_NUM), _______
    ),

	  [_WEAPON] = LAYOUT(
      LSFT(DE_K), DE_K, DE_H,    KC_UP,   DE_S,     DE_R,                   /*|*/                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,
      LSFT(DE_Q), DE_Q, KC_LEFT, KC_DOWN, KC_RIGHT, DE_T,                   /*|*/                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
      LSFT(DE_B), DE_B, DE_M,    DE_N,    DE_Y,     DE_J, KC_PGUP, KC_PGDN, /*|*/ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  TG(_GAME),
                         LSFT(DE_M), LSFT(DE_N), KC_MPRV, KC_MPLY, KC_MNXT, /*|*/ _______, _______, _______, _______, _______
    ),

      [_ADJ] = LAYOUT(
      KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,                    /*|*/               KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, HIBER,
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                   /*|*/               KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO, RGB_RMOD, RGB_MOD, /*|*/ KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, EEP_RST,
                              KC_NO, RGB_TOG, _______, KC_NO, KC_NO, /*|*/ KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
