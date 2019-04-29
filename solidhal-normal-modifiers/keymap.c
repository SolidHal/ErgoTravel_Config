#include QMK_KEYBOARD_H
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1, KC_3, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_5, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_2, KC_4, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TG(3), MO(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LALT, KC_LGUI, KC_LEFT, KC_RGHT, LT(1,KC_SPC), RSFT_T(KC_BSPC), KC_DOWN, KC_UP, KC_VOLD, KC_VOLU, KC_RCTL),
	[1] = LAYOUT(KC_ESC, KC_NO, KC_GRV, KC_MINS, KC_EQL, LGUI(KC_1), LGUI(KC_4), RGB_VAI, RGB_HUI, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_TAB, KC_NO, KC_LBRC, KC_RBRC, KC_BSLS, LGUI(KC_2), LGUI(KC_5), RGB_VAD, RGB_HUD, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_SCLN, KC_QUOT, KC_SLSH, LGUI(KC_3), KC_NO, RGB_TOG, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_TRNS, RSFT_T(KC_BSPC), KC_0, KC_DOT, KC_MPRV, KC_MPLY, KC_MNXT),
	[2] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_1, KC_3, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_2, KC_4, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_SPC, KC_SPC, RSFT_T(KC_BSPC), KC_NO, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT)
};

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case 0:
        rgblight_setrgb(102, 0, 102);
	//rgblight_setrgb(102, 0, 204);        
	break;
      case 1:
        rgblight_setrgb(0x00, 0xA0, 0xFF);
        break;
      case 2:
        rgblight_setrgb(0xFF, 0x00, 0x00);
        break;
      case 3:
        rgblight_setrgb(0xFF, 0x20, 0x00);
        break;
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
}
