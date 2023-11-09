/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum {
    TD_Q_RUN,
    TD_UML,
};

void dance_uml(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_SCLN);
            break;
        case 2:
           tap_code(KC_QUOT);
            break;
        case 3:
            tap_code(KC_LBRC);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_RUN] = ACTION_TAP_DANCE_DOUBLE(KC_Q, A(KC_F2)),
    [TD_UML] = ACTION_TAP_DANCE_FN(dance_uml),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // BASE
  [0] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TD(TD_Q_RUN),    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUI_T(KC_A),     ALT_T(KC_S),    CTL_T(KC_D),    SFT_T(KC_F),    KC_G,    KC_H,    RSFT_T(KC_J),    CTL_T(KC_K),    ALT_T(KC_L), TD(TD_UML),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LT(1, KC_Z),         RALT_T(KC_X),   KC_C,    KC_V,    KC_B,              KC_N,    KC_M, KC_COMM,  RALT_T(KC_DOT), KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       LT(4, KC_ESC), LT(2, KC_SPC),  LT(3, KC_TAB),  LT(6, KC_ENT), LT(5, KC_BSPC), LT(7, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  // EXTRA
  [1] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_BOOT, QK_RBT, DB_TOGG, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_SPC,  _______,     MO(3), KC_ENT, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  // NAV
  [2] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CAPS, LSFT(KC_INS), LCTL(KC_INS), LSFT(KC_DEL), KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      CW_TOGG,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // MOUSE
  [3] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // MEDIA
  [4] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  XXXXXXX, XXXXXXX,     KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),
  // NUM
  [5] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                                       LGUI(KC_PGUP), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                                        LGUI(KC_PGDN), KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                                        LGUI(KC_LCTL), XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,  KC_0, KC_MINS,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // SYMBOL
  [6] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                              LALT(KC_KP_4), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      UC(0x003C), UC(0x003E), UC(0x007C), KC_CIRC, KC_PLUS,                        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,                                XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN,  KC_RPRN, KC_UNDS,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // FUN
  [7] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_APP,  KC_SPC, KC_TAB,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
