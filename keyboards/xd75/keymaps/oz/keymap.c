/* Copyright 2018 Milton Griffin
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

// Keyboard Layers
#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _FNLYR 3

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FNLYR MO(_FNLYR)
#define DEL_WRD _______

enum unicode_names {
    O_UML,
    O_UML_CAP,
    U_UML,
    U_UML_CAP,
    A_UML,
    A_UML_CAP,
    A_RING,
    A_RING_CAP,
    BX_CBL, // ╰ 0x2570
    BX_CBR, // ╯ 0x256F
    BX_CTL, // ╭ 0x256D
    BX_CTR, // ╮ 0x256E
    BX_HR, // ─ 0x2500
    BX_VERT, // │ 0x2502
    BX_TL,  // ├ 0x251C
    BX_TR,  // ┤ 0x2524
    BX_TT,  // ┬ 0x252C
    BX_TB,  // ┴ 0x2534
    BX_TX,  // ┼ 0x253C
    CAT_HPY,  // 0x1F638 😸
    CAT_JOY, // U+1F639
    CAT_GRN, // U+1F63A
    CAT_LOV, // U+1F63B
    CAT_CRY, // U+1F63F
    CAT_O, // U+1F640
    CAT_POU, // U+1F63E
};

const uint32_t PROGMEM unicode_map[] = {
    [U_UML]      = 0x00FC,
    [U_UML_CAP]  = 0x00DC,
    [O_UML]      = 0x00F6,
    [O_UML_CAP]  = 0x00D6,
    [A_UML]      = 0x00E4,
    [A_UML_CAP]  = 0x00C4,
    [A_RING]     = 0x00E5,
    [A_RING_CAP] = 0x00C5,
    [BX_CBL]     = 0x2570,
    [BX_CBR]     = 0x256F,
    [BX_CTL]     = 0x256D,
    [BX_CTR]     = 0x256E,
    [BX_HR]      = 0x2500,
    [BX_VERT]    = 0x2502,
    [BX_TL]      = 0x251C,
    [BX_TR]      = 0x2524,
    [BX_TT]      = 0x252C,
    [BX_TB]      = 0x2534,
    [BX_TX]      = 0x253C,
    [CAT_HPY]    = 0x1F638,
    [CAT_JOY]    = 0x1F639,
    [CAT_GRN]    = 0x1F63A,
    [CAT_LOV]    = 0x1F63B,
    [CAT_CRY]    = 0x1F63F,
    [CAT_O]      = 0x1F640,
    [CAT_POU]    = 0x1F63E,
};

enum custom_keycodes {
  K_CMT = SAFE_RANGE,
//   SM_SAD ,
//   SM_HPY,
//   SM_GRN,
//   SM_TNG,
};


#define KC_A_RN XP(A_RING, A_RING_CAP)
#define KC_A_UML XP(A_UML, A_UML_CAP)
#define KC_U_UML XP(U_UML, U_UML_CAP)
#define KC_O_UML XP(O_UML, O_UML_CAP)
#define KC_BX_CBL X(BX_CBL)
#define KC_BX_CBR X(BX_CBR)
#define KC_BX_CTL X(BX_CTL)
#define KC_BX_CTR X(BX_CTR)
#define KC_BX_HR X(BX_HR)
#define KC_BX_VERT X(BX_VERT)
#define KC_BX_TL X(BX_TL)
#define KC_BX_TR X(BX_TR)
#define KC_BX_TT X(BX_TT)
#define KC_BX_TB X(BX_TB)
#define KC_BX_TX X(BX_TX)
#define KC__HPY X(CAT_HPY)
#define KC__JOY X(CAT_JOY)
#define KC__GRN X(CAT_GRN)
#define KC__LOV X(CAT_LOV)
#define KC__CRY X(CAT_CRY)
#define KC__O X(CAT_O)
#define KC__POU X(CAT_POU)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case SM_SAD:
    //   if (record->event.pressed) {
    //     SEND_STRING(":-(");
    //   } else {}
    //   break;
    // case SM_HPY:
    //   if (record->event.pressed) {
    //     SEND_STRING(":-)");
    //   } else {}
    //   break;
    // case SM_GRN:
    //   if (record->event.pressed) {
    //     SEND_STRING(":-D");
    //   } else {}
    //   break;
    // case SM_TNG:
    //   if (record->event.pressed) {
    //     SEND_STRING(":-P");
    //   } else {}
    //   break;
    case K_CMT:
      if (record->event.pressed) {
        SEND_STRING("/**\n*/");
      } else {}
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



[_COLEMAK] = LAYOUT_ortho_5x15(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, FNLYR,   LOWER,   KC_SPC,  _______, _______, _______, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


[_LOWER] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, _______, _______, _______, KC_EQL,  KC_RPRN,  KC_RCBR, KC_RBRC, _______, KC_PIPE,
    _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, KC_PLUS, _______,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_RAISE] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_U_UML,_______, _______, _______,
    _______, KC_A_UML,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_O_UML, KC_BSLS,
    _______, KC_A_RN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UC_M_WI,  UC_M_LN
),

[_FNLYR] = LAYOUT_ortho_5x15(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, _______, _______, KC_F16,  KC_F17,  KC_F18,   KC_F19,  KC_F20,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY
)

};
