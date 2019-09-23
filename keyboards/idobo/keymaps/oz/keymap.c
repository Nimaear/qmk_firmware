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
#define _QWERTY 1
#define _NUMPAD 3
#define _LOWER 4
#define _RAISE 5

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
#define KC_FOLD LCTL(LSFT(KC_LBRC))
#define KC_UFOLD LCTL(LSFT(KC_RBRC))


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

/* COLEMAK http://www.keyboard-layout-editor.com/#/gists/c00a2a7b335f2178148f1e9d0d977d6d
 * ╭────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────╮
 * │ ESC    │ 1      │ 2      │ 3      │ 4      │ 5      │ -      │ =      │ `      │  6     │ 7      │ 8      │ 9      │ 0      │ BACKSP │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ TAB    │ Q      │ W      │ F      │ P      │ G      │ [      │        │ ]      │ J      │ L      │ U      │ Y      │ ;      │ \      │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ BACKSP │ A      │ R      │ S      │ T      │ D      │ PAGEUP │        │ HOME   │ H      │ N      │ E      │ I      │ O      │ '      │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ LSHIFT │ Z      │ X      │ C      │ V      │ B      │ PAGEDN │ UP     │ END    │ K      │ M      │ ,      │ .      │ /      │ ENTER  │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ LCTRL  │ LGUI   │ LALT   │ LOWER  │ DELETE │ {      │ LEFT   │ DOWN   │ RIGHT  │ }      │        │        │        │        │        │
 * ╰────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────╯
 */

 [_COLEMAK] = LAYOUT_ortho_5x15( /* COLEMAK */
   KC_ESC,  KC_1,    KC_2,    KC_3,        KC_4,       KC_5,    KC_HOME, _______, KC_END,  KC_6,    KC_7,   KC_8,        KC_9,    KC_0,    KC_BSPC, \
   KC_TAB,  KC_Q,    KC_W,    KC_F,        KC_P,       KC_G,    KC_LPRN, _______,  KC_RPRN, KC_J,    KC_L,   KC_U,        KC_Y,    KC_SCLN, KC_BSLS, \
   KC_BSPC, KC_A,    KC_R,    KC_S,        KC_T,       KC_D,    KC_LBRC, KC_DEL,   KC_RBRC, KC_H,    KC_N,   KC_E,        KC_I,    KC_O,    KC_QUOT,  \
   KC_LSFT, KC_Z,    KC_X,    KC_C,        KC_V,       KC_B,    KC_MINS, KC_UP,    KC_EQL,  KC_K,    KC_M,   KC_COMM,     KC_DOT,  KC_SLSH, KC_ENT, \
   KC_LCTL, KC_LGUI, KC_LALT, OSL(_LOWER), KC_SPC,     KC_FOLD, KC_LEFT, KC_DOWN,  KC_RGHT, KC_UFOLD,KC_SPC, OSL(_RAISE), _______, _______,KC_GRAVE \
),

/* QWERTY
 * ╭────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────╮
 * │ ESC    │ 1      │ 2      │ 3      │ 4      │ 5      │ -      │ =      │ `      │  6     │ 7      │ 8      │ 9      │ 0      │ BACKSP │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ TAB    │ Q      │ W      │ E      │ R      │ T      │ [      │        │ ]      │ Y      │ U      │ I      │ O      │ P      │ \      │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ BACKSP │ A      │ S      │ D      │ F      │ G      │ PAGEUP │        │ HOME   │ H      │ J      │ K      │ J      │ ;      │ '      │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ LSHIFT │ Z      │ X      │ C      │ V      │ B      │ PAGEDN │ UP     │ END    │ N      │ M      │ ,      │ .      │ /      │ ENTER  │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ LCTRL  │ LGUI   │ LALT   │ LOWER  │ DELETE │ {      │ LEFT   │ DOWN   │ RIGHT  │ }      │        │        │        │        │        │
 * ╰────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────╯
 */

 [_QWERTY] = LAYOUT_ortho_5x15( /* COLEMAK */
   _______, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    _______, _______,  _______, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    _______, \
   _______, KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    _______, _______,  _______, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    _______, \
   _______, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    _______, _______,  _______, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, _______,  \
   _______, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    _______, _______,  _______, KC_N,    KC_M,   _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,    _______, _______, _______,  _______, _______, _______,_______, _______, _______, _______\
),

[_NUMPAD] = LAYOUT_ortho_5x15( /* COLEMAK */
   _______, _______, _______, _______, _______,  _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,  _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,  _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,  _______, KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* LOWER
 * ╭────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────╮
 * │ RESET  │ F1     │ F2     │ F3     │ F4     │ F5     │ F6     │ F7     │ F8     │ F9     │ F10    │ F11    │ F12    │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │        │ CAT_GRN│        │ CAT_LOV│        │        │ CAT_CRY│ CAT_POU│ CAT_HPY│ CAT_O  │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ CTL-BK │ Å      │        │        │ HOME   │ PG_DN  │PG_UP   │ END    │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │ UC_LIN │ UC_WIN │ UC_OSX │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │ CTL-DEL│ (      │ )      │        │        │        │        │ PAGEUP │ PAGEDN │ HOME   │ END    │
 * ╰────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────╯
 */

 [_LOWER] = LAYOUT_ortho_5x15( /* FUNCTION */
    RESET,        _______,     _______, _______, _______,       _______, _______,     _______,     _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, \
    _______,      KC_F11,      KC_F12,  _______, _______,       _______, _______,     _______,     _______, _______, _______, KC__POU, KC__HPY, KC__O,   _______, \
    LCTL(KC_BSPC),KC_A_RN,     _______, _______, _______,       _______, _______,     LCTL(KC_DEL),_______, _______, _______, _______, _______, _______, _______, \
    UC_M_LN,      UC_M_WI,     UC_M_OS, _______, _______,       _______, _______,     KC_PGUP,     _______, _______, _______, _______, _______, _______, _______, \
    TO(_COLEMAK), TO(_QWERTY), _______, _______, _______,       _______, KC_HOME,     KC_PGDN,     KC_END,  _______, _______, _______, _______, _______, _______   \
 ),

/* RAISE
 * ╭────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────╮
 * │ RESET  │RGB_M_P │RGB_M_B │RGB_M_R │RGB_M_SW│RGB_M_SN│RGB_M_K │RGB_M_X │RGB_M_G │ F9     │ F10    │ F11    │ F12    │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │        │        │        │        │ Ü      │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │ CTL-BK │ Ä      │        │        │ LEFT   │ DOWN   │ UP     │ RIGHT  │        │        │ Ö      │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │ CTL-DEL│ [      │ ]      │        │        │ (      │        │        │        │        │        │
 * ╰────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────╯
 */


/* [_RAISE] = LAYOUT_ortho_5x15(
    RESET,        RGB_M_P,     RGB_M_B,   RGB_M_R,  RGB_M_SW,       RGB_M_SN,   RGB_M_K, RGB_M_X, RGB_M_G,  _______, _______,  _______, _______, _______, _______, \
    _______,      _______,     KC_BX_CTL, KC_BX_TT, KC_BX_CTR,      _______,    _______, _______, KC_U_UML, _______, _______,  _______, _______, _______, _______, \
    LCTL(KC_BSPC),KC_A_UML,    KC_BX_TL,  KC_BX_TX, KC_BX_TR,       KC_BX_VERT, _______, _______, _______,  _______, KC_O_UML, _______, _______, _______, _______, \
    _______,      _______,     KC_BX_CBL, KC_BX_TB, KC_BX_CBR,      KC_BX_HR,   _______, _______, _______,  _______, _______,  _______, _______, _______, _______, \
    TO(_COLEMAK), TO(_QWERTY), _______,   _______,  LCTL(KC_DEL),   KC_LBRC,    KC_RBRC, _______, _______,  _______, _______,  _______, _______, _______, _______  \
 ),
*/
 [_RAISE] = LAYOUT_ortho_5x15( /* FUNCTION */
    RESET,        KC_F1,       KC_F2,   KC_F3,   KC_F4,         KC_F5,   _______,     _______,     _______,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    RGB_TOG,      RGB_M_P,     RGB_M_B, RGB_M_R, RGB_M_SW,     RGB_M_SN, RGB_M_K, RGB_M_X,     RGB_M_G,  _______, _______,  KC_U_UML, _______, _______,  _______, \
    LCTL(KC_BSPC),KC_A_UML,    _______, _______, _______,      _______,  _______, LCTL(KC_DEL),_______,  _______, _______,  _______,  _______, KC_O_UML, _______, \
    _______,      _______,     _______, _______, _______,      _______,  _______, _______,     _______,  _______, _______,  _______,  _______, _______,  _______, \
    TG(_COLEMAK), TG(_QWERTY), _______, _______, _______,      _______,  _______, _______,     _______,  _______, _______,  _______,  _______, _______,  TG(_NUMPAD) \
 ),
};