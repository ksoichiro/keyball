/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , MT(MOD_LCTL,KC_MINS),
    MT(MOD_LSFT,KC_Z), KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , MT(MOD_LSFT,KC_SLSH),
    KC_LCTL  , KC_LALT  , KC_LGUI  ,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),MT(MOD_LSFT,KC_BSPC),LT(1,KC_ENT), _______ , _______  , _______ , TG(1)
  ),

  [1] = LAYOUT_universal(
    KC_ESC    , KC_Q    , KC_W     , KC_E     , XXXXXXX  ,                            G(KC_LEFT),G(KC_RIGHT),LSG(KC_T), S(C(KC_TAB)), C(KC_TAB) ,
    KC_LCTL   , KC_A    , KC_S     , KC_D     , KC_F     ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  ,
    KC_LSFT   , XXXXXXX , XXXXXXX  , XXXXXXX  , KC_V     ,                            KC_TAB   , KC_BTN1  , KC_BTN3  , KC_BTN2  , QK_KB_6  ,
    _______   , _______ , _______  , XXXXXXX  , _______  , XXXXXXX  ,      KC_RGUI  , _______  , _______  , _______  , _______  , TG(1)
  ),

  [2] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_ESC   , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_MINS  , KC_EQL   , KC_INT3  , KC_SCLN  , KC_QUOT  ,
    KC_TAB   , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_LBRC  , KC_RBRC  , KC_BSLS	 , KC_SLSH  , S(KC_INT1),
    _______  , _______  , _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,      MT(MOD_LSFT,KC_BSPC), XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [3] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    ,  KC_F5    ,                           KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    QK_KB_5  , QK_KB_3  , QK_KB_2  , QK_KB_4  ,  QK_KB_1  ,                           KC_F14   , KC_F15   , QK_KB_1  , C(KC_UP) , RGB_MOD ,
    QK_KB_8  , QK_KB_9  , XXXXXXX  , XXXXXXX  ,  XXXXXXX  ,                           KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, G(KC_L)  , RGB_TOG ,
    _______  , _______  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , _______  , XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
