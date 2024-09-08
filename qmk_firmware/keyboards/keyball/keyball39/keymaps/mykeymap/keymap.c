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

const uint16_t PROGMEM qwe_combo[] = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM iop_combo[] = {KC_I, KC_O, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO(qwe_combo, QK_BOOT),
    COMBO(iop_combo, QK_BOOT),
};

// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP, // Send two single taps
//     TD_TRIPLE_TAP,
//     TD_TRIPLE_HOLD
// } td_state_t;
//
// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_t;
//
// // Tap dance enums
// enum {
//   TD_KANA_HAEN,
//   TD_TAB,
// };
//
// td_state_t cur_dance(tap_dance_state_t *state);
//
// // For the x tap dance. Put it here so it can be used in any keymap
// void kana_finished(tap_dance_state_t *state, void *user_data);
// void kana_reset(tap_dance_state_t *state, void *user_data);
// void tab_finished(tap_dance_state_t *state, void *user_data);
// void tab_reset(tap_dance_state_t *state, void *user_data);
//
// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         // Prefer to send a 'HOLD' over a 'SINGLE_TAP' if the key has been interrupted.
//         // This is the same as HOLD_ON_OTHER_KEY_PRESSED.
//         if (state->interrupted) return TD_SINGLE_HOLD;
//         if (!state->pressed) return TD_SINGLE_TAP;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }
//
//     // Assumes no one is trying to type the same letter three times (at least not quickly).
//     // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//     // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
//         else return TD_TRIPLE_HOLD;
//     } else return TD_UNKNOWN;
// }
//
// // Create an instance of 'td_tap_t' for the 'x' tap dance.
// static td_tap_t kana_tap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
//
// void kana_finished(tap_dance_state_t *state, void *user_data) {
//     kana_tap_state.state = cur_dance(state);
//     switch (kana_tap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_LNG1); break;
//         case TD_SINGLE_HOLD: layer_on(3); break;
//         case TD_DOUBLE_TAP: register_code(KC_LNG2); break;
//         case TD_DOUBLE_HOLD: register_code(KC_LSFT); break;
//         // Last case is for fast typing. Assuming your key is `f`:
//         // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//         // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//         // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
//         default: break;
//     }
// }
//
// void kana_reset(tap_dance_state_t *state, void *user_data) {
//     switch (kana_tap_state.state) {
//         case TD_SINGLE_TAP: unregister_code(KC_LNG1); break;
//         case TD_SINGLE_HOLD: layer_off(3); break;
//         case TD_DOUBLE_TAP: unregister_code(KC_LNG2); break;
//         case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); break;
//         // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
//         default: break;
//     }
//     kana_tap_state.state = TD_NONE;
// }
//
// static td_tap_t tab_tap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
//
// void tab_finished(tap_dance_state_t *state, void *user_data) {
//     tab_tap_state.state = cur_dance(state);
//     switch (tab_tap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_TAB); break;
//         case TD_SINGLE_HOLD: layer_on(1); break;
//         case TD_DOUBLE_TAP: register_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: register_code(KC_LCTL); break;
//         // Last case is for fast typing. Assuming your key is `f`:
//         // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//         // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//         // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
//         default: break;
//     }
// }
//
// void tab_reset(tap_dance_state_t *state, void *user_data) {
//     switch (tab_tap_state.state) {
//         case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
//         case TD_SINGLE_HOLD: layer_off(1); break;
//         case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); break;
//         // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
//         default: break;
//     }
//     tab_tap_state.state = TD_NONE;
// }
//
// tap_dance_action_t tap_dance_actions[] = {
//     [TD_KANA_HAEN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kana_finished, kana_reset),
//     [TD_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_finished, tab_reset)
// };

// clang-format off
//
// See https://docs.qmk.fm/#/keycodes_basic
// See https://github.com/Yowkees/keyball/blob/main/qmk_firmware/keyboards/keyball/lib/keyball/keycodes.md#japanese
// KC_NO          XXXXXXX          Ignore this key (NOOP)
// KC_TRANSPARENT KC_TRNS, _______ Use the next lowest non-transparent key
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , MT(MOD_LCTL,KC_MINS),
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , MT(MOD_LSFT,KC_SLSH),
    KC_LCTL  , KC_LALT  , MT(MOD_LGUI,KC_TAB)  , MO(1), LT(2,KC_SPC),LT(3,KC_LNG2),MT(MOD_LSFT,KC_LNG1),LT(1,KC_ENT), _______ , _______  , _______ , TG(1)
    //KC_LCTL  , KC_LALT  , KC_LGUI  ,TD(TD_TAB),LT(2,KC_SPC),TD(TD_KANA_HAEN),MT(MOD_LSFT,KC_BSPC),LT(1,KC_ENT), _______ , _______  , _______ , TG(1)
  ),

  [1] = LAYOUT_universal(
    KC_ESC    , KC_Q    , KC_W     , KC_E     , KC_F3    ,                            G(KC_LEFT),G(KC_RIGHT),LSG(KC_T), S(C(KC_TAB)), C(KC_TAB) ,
    KC_LCTL   , KC_A    , KC_S     , KC_D     , KC_F     ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  ,
    KC_LSFT   , XXXXXXX , XXXXXXX  , XXXXXXX  , KC_SPC   ,                            KC_TAB   , KC_BTN1  , KC_BTN3  , KC_BTN2  , QK_KB_6  ,
    _______   , _______ , _______  , _______  , _______  , XXXXXXX  ,      KC_RGUI  , _______  , _______  , _______  , _______  , TG(1)
  ),

  [2] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_ESC   , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_MINS  , KC_EQL   , KC_INT3  , KC_SCLN  , KC_QUOT  ,
    KC_TAB   , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_LBRC  , KC_RBRC  , KC_BSLS  , KC_SLSH  , S(KC_INT1),
    _______  , _______  , _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,      KC_BSPC  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [3] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    ,  KC_F5    ,                           KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX  ,                           KC_F14   , KC_F15   , QK_KB_1  , C(KC_UP) , RGB_MOD ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX  ,                           KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, G(KC_L)  , RGB_TOG ,
    _______  , _______  , _______  , _______  ,  _______  , _______  ,     KC_DEL   , _______  , _______  , _______  , _______  , _______
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
