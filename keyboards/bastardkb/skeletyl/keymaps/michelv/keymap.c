/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION = 1,
    LAYER_NAVIGATION = 2,
    LAYER_POINTER = 3,
    LAYER_NUMERAL = 4,
    LAYER_SYMBOLS = 5,
};

#define SPC_NUM LT(LAYER_NUMERAL, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define BSP_NAV LT(LAYER_NAVIGATION, KC_BSPC)
#define _L_PTR(KC) LT(LAYER_POINTER, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#    define DRG_TOG KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,         \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,         \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,         \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          TAB_FUN, BSP_NAV, KC_GRV,      KC_ESC,  SPC_NUM, ENT_SYM
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
#define ______________HOME_ROW_CAGS_L______________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_CAGS_R______________ XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL

/*
 * Layers used on the Dilemma.
 *
 * These layers started off heavily inspired by the Miryoku layout, but trimmed
 * down and tailored for a stock experience that is meant to be fundation for
 * further personalization.
 *
 * See https://github.com/manna-harbour/miryoku for the original layout.
 */

/**
 * \brief Function layer.
 *
 * Secondary right-hand layer has function keys mirroring the numerals on the
 * primary layer with extras on the pinkie column, plus system keys on the inner
 * column. App is on the tertiary thumb key and other thumb keys are duplicated
 * from the base layer to enable auto-repeat.
 */
#define LAYOUT_LAYER_FUNCTION                                                                 \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        ______________HOME_ROW_CAGS_L______________,     KC_VOLU, RSFT(KC_LEFT), RSFT(KC_UP), RSFT(KC_DOWN), RSFT(KC_RGHT),       \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        _______________DEAD_HALF_ROW_______________,     KC_VOLD, CW_TOGG, RSFT(RGUI(KC_4)), KC_F11,  KC_F12,       \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          XXXXXXX, _______, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/** \brief Mouse emulation and pointer functions. */
#define LAYOUT_LAYER_POINTER                                                                  \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        QK_BOOT, EE_CLR,  XXXXXXX, DPI_MOD, S_D_MOD,     S_D_MOD, DPI_MOD, RGB_TOG, RGB_M_P, RGB_VAI,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        ______________HOME_ROW_CAGS_L______________,     ______________HOME_ROW_CAGS_R______________,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        _______, DRG_TOG, SNIPING, MS_BTN5, MS_BTN4,     MS_BTN4, MS_BTN5, SNIPING, DRG_TOG, _______,      \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          MS_BTN3, MS_BTN2, MS_BTN1,     MS_BTN1, MS_BTN2, MS_BTN3
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/**
 * \brief Navigation layer.
 *
 * Primary right-hand layer (left home thumb) is navigation and editing. Cursor
 * keys are on the home position, line and page movement below, clipboard above,
 * caps lock and insert on the inner column. Thumb keys are duplicated from the
 * base layer to avoid having to layer change mid edit and to enable auto-repeat.
 */
#define LAYOUT_LAYER_NAVIGATION                                                               \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        _______________DEAD_HALF_ROW_______________,     XXXXXXX, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        ______________HOME_ROW_CAGS_L______________,     KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        _______________DEAD_HALF_ROW_______________,     KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,       \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          XXXXXXX, XXXXXXX, _______,     KC_DEL,  KC_SPC,  KC_ENT
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/**
 * \brief Numeral layout.
 *
 * Primary left-hand layer (right home thumb) is numerals and symbols. Numerals
 * are in the standard numpad locations with symbols in the remaining positions.
 * `KC_DOT` is duplicated from the base layer.
 */
#define LAYOUT_LAYER_NUMERAL                                                                  \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,     ______________HOME_ROW_CAGS_R______________,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH,     _______________DEAD_HALF_ROW_______________,      \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          KC_MINS, KC_EQL,  KC_DOT,      XXXXXXX, _______, XXXXXXX
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/**
 * \brief Symbols layer.
 *
 * Secondary left-hand layer has shifted symbols in the same locations to reduce
 * chording when using mods with shifted symbols. `KC_LPRN` is duplicated next to
 * `KC_RPRN`.
 */
#define LAYOUT_LAYER_SYMBOLS                                                                  \
  /** ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮ */ \
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_LCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,     ______________HOME_ROW_CAGS_R______________,      \
  /** ├──────────────────────────────────────────┤ ├──────────────────────────────────────────┤ */ \
        KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES,     _______________DEAD_HALF_ROW_______________,      \
  /** ╰──────────────────────────────────────────┤ ├──────────────────────────────────────────╯ */ \
                          KC_UNDS, KC_PLUS, KC_TILD,     _______, XXXXXXX, XXXXXXX
  /**                 ╰───────────────────────────╯ ╰───────────────────────────╯                          */

/**
 * \brief Combos.
 */

enum combos {
  AQUOT_EXLM,
  OCOMM_AT,
  EDOT_HASH,
  UP_DLR,
  IY_PERC,
  DF_CIRC,
  HG_AMPR,
  TC_ASTR,
  NR_LPRN,
  SL_RPRN,
  UH_CAPSWORD,
  COMMDOT_DOUBLEARROW,
  DOTP_ARROW,
  KX_COMMENT,
};

const uint16_t PROGMEM AQUOT_combo[] = {LCTL_T(KC_A), KC_QUOT, COMBO_END};
const uint16_t PROGMEM OCOMM_combo[] = {LALT_T(KC_O), KC_COMM, COMBO_END};
const uint16_t PROGMEM EDOT_combo[] = {LGUI_T(KC_E), KC_DOT, COMBO_END};
const uint16_t PROGMEM UP_combo[] = {LSFT_T(KC_U), KC_P, COMBO_END};
const uint16_t PROGMEM IY_combo[] = {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM DF_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM HG_combo[] = {RSFT_T(KC_H), KC_G, COMBO_END};
const uint16_t PROGMEM TC_combo[] = {RGUI_T(KC_T), KC_C, COMBO_END};
const uint16_t PROGMEM NR_combo[] = {LALT_T(KC_N), KC_R, COMBO_END};
const uint16_t PROGMEM SL_combo[] = {RCTL_T(KC_S), KC_L, COMBO_END};
const uint16_t PROGMEM UH_combo[] = {LSFT_T(KC_U), RSFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM COMMDOT_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM DOTP_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM KX_combo[]    = {KC_K, KC_X, COMBO_END};

combo_t key_combos[] = {
  [AQUOT_EXLM] = COMBO(AQUOT_combo, KC_EXLM),
  [OCOMM_AT] = COMBO(OCOMM_combo, KC_AT),
  [EDOT_HASH] = COMBO(EDOT_combo, KC_HASH),
  [UP_DLR] = COMBO(UP_combo, KC_DLR),
  [IY_PERC] = COMBO(IY_combo, KC_PERC),
  [DF_CIRC] = COMBO(DF_combo, KC_CIRC),
  [HG_AMPR] = COMBO(HG_combo, KC_AMPR),
  [TC_ASTR] = COMBO(TC_combo, KC_ASTR),
  [NR_LPRN] = COMBO(NR_combo, KC_LPRN),
  [SL_RPRN] = COMBO(SL_combo, KC_RPRN),
  [UH_CAPSWORD] = COMBO(UH_combo, CW_TOGG),
  [COMMDOT_DOUBLEARROW] = COMBO_ACTION(COMMDOT_combo),
  [DOTP_ARROW] = COMBO_ACTION(DOTP_combo),
  [KX_COMMENT] = COMBO(KX_combo, LGUI(KC_SLSH)),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMMDOT_DOUBLEARROW:
      if (pressed) {
        SEND_STRING("=>");
      }
      break;
    case DOTP_ARROW:
      if (pressed) {
        SEND_STRING("->");
      }
      break;
  }
}

/**
 * \brief Add Home Row mod to a layout.
 *
 * Expects a 10-key per row layout.  Adds support for CAGS (Ctl, Alt, Gui, Shift)
 * home row.  The layout passed in parameter must contain at least 20 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     HOME_ROW_MOD_CAGS(LAYER_ALPHAS_QWERTY)
 */
#define _HOME_ROW_MOD_CAGS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      LCTL_T(L10), LALT_T(L11), LGUI_T(L12), LSFT_T(L13),        L14,  \
             R15,  RSFT_T(R16), RGUI_T(R17), LALT_T(R18), RCTL_T(R19), \
      __VA_ARGS__
#define HOME_ROW_MOD_CAGS(...) _HOME_ROW_MOD_CAGS(__VA_ARGS__)

/**
 * \brief Add pointer layer keys to a layout.
 *
 * Expects a 10-key per row layout.  The layout passed in parameter must contain
 * at least 30 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     POINTER_MOD(LAYER_ALPHAS_QWERTY)
 */
#define _POINTER_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
      _L_PTR(L20),        L21,         L22,         L23,         L24,  \
             R25,         R26,         R27,         R28,  _L_PTR(R29), \
      __VA_ARGS__
#define POINTER_MOD(...) _POINTER_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
    POINTER_MOD(HOME_ROW_MOD_CAGS(LAYOUT_LAYER_BASE))
  ),
  [LAYER_FUNCTION] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_NUMERAL] = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
};
// clang-format on
