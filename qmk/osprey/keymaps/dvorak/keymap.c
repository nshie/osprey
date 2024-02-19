/*
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    QWERTY = 0,     //Qwerty
    DVORAK = 1,     //Dvorak
    QWCTRL = 2,     //Dvorak keyboard shortcuts layer
    GAME   = 3,     //Qwerty for games
    SYM    = 4,     //Symbols layer
    NUM    = 5,     //Numpad
    STENO  = 6,     //Plover stenography layout for chording
    FN     = 7      //Function layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//modified QWERTY layout

  [QWERTY] = LAYOUT_osprey(
  	KC_ESC,      KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                                KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,
  	DF(DVORAK),  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
  	DF(STENO),   KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,                                KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_BSLS,
          KC_LSFT,        KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_SPACE, MO(SYM),   KC_RCTL, OSL(FN),   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,
  	TG(NUM), KC_LCTL,     KC_LGUI, KC_LALT, KC_BSPC,      KC_LCTL,  MO(FN),    MO(SYM), KC_ENTER,       KC_SPACE,   KC_RALT,    KC_RGUI, KC_RCTL, KC_DEL
  ),

//modified DVORAK layout with QWERTY ctrl key

  [DVORAK] = LAYOUT_osprey(
     KC_ESC,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4, KC_5, KC_6,                                           KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,   KC_LBRC, KC_RBRC,
     DF(QWERTY),  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P, KC_Y, KC_F,                                           KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L,   KC_SLSH, KC_EQL,
     DF(STENO),   KC_CAPS, KC_A,    KC_O,    KC_E,    KC_U, KC_I, KC_D,                                           KC_I, KC_D, KC_H, KC_T, KC_N, KC_S,   KC_MINS, KC_BSLS,
            KC_LSFT,       KC_SCLN, KC_Q,    KC_J,    KC_K, KC_X,   KC_SPACE,             KC_LALT,   KC_RALT, OSL(FN),  KC_B, KC_M, KC_W, KC_V, KC_Z,        KC_RSFT,
     TG(NUM), LM(QWCTRL, MOD_LCTL), KC_LGUI, KC_LSFT, KC_BSPC,      LM(QWCTRL, MOD_LCTL), MO(FN),    KC_RCTL, KC_ENTER,   KC_SPACE,   MO(FN),  KC_RGUI, KC_RCTL, KC_DEL
  ),

//QWERTY keys with ctrl held (for alternate layouts that want to use ctrl)

  [QWCTRL] = LAYOUT_osprey(
  	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,
  	KC_TRNS, KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
  	KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,                                KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_BSLS,
          KC_TRNS,    KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_TRNS,
  	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,          KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
  ),

//game QWERTY layout

  [GAME] = LAYOUT_osprey(
  	KC_ESC,     KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                              KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,
  	KC_PGUP,    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                              KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
  	KC_CAPS,    KC_PGDN, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,                              KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_BSLS,
          KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_M,    KC_LALT,   KC_RALT, OSL(FN), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,
  	KC_PSCR,    KC_LCTL, KC_INS, KC_BSPC, KC_RSFT,       KC_RCTL, KC_RALT,   KC_RCTL, KC_ENTER,       KC_SPACE,   MO(FN),   KC_RGUI,  KC_RCTL, KC_DEL
  ),

//symbol layer

  [SYM] = LAYOUT_osprey(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_LBRC,    KC_TRNS, KC_RBRC,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, S(KC_LBRC), KC_TRNS, S(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS, S(KC_9),    KC_TRNS, S(KC_0),    KC_TRNS,     KC_TRNS,
    KC_TRNS,     KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,             KC_TRNS,   KC_TRNS
  ),

//function layer

  [FN] = LAYOUT_osprey(
    KC_TRNS,    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    DF(QWERTY), KC_TRNS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    DF(GAME),   KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS,        KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,   RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI,     KC_TRNS,
    KC_TRNS,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   RESET
  ),

//numpad layer

  [NUM] = LAYOUT_osprey(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS, KC_TRNS,
          KC_TRNS,    KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT,     KC_TRNS,
    KC_TRNS,   KC_TRNS,        KC_PDOT,    KC_TRNS,    KC_P0,        KC_PENT, KC_TRNS,    KC_TRNS, KC_TRNS,      KC_P0,      KC_TRNS,    KC_PDOT,        KC_TRNS,   KC_TRNS
  ),

//plover stenography layout

  [STENO] = LAYOUT_osprey(
    KC_ESC,      KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                                KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,
    DF(QWERTY),  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
    KC_CAPS,     MO(FN),  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,                                KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENTER,
          KC_LSFT,        KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_SPACE, KC_LALT,   KC_RALT, OSL(FN),   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,
    KC_NO,   KC_LCTL,     KC_LGUI, KC_LSFT, KC_BSPC,      KC_C,     KC_V,      KC_N,    KC_M,             KC_SPACE,   MO(FN),   KC_RGUI, KC_RCTL, KC_DEL
  )
};
