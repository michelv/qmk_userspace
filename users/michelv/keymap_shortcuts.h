#pragma once

enum my_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
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

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
#define ______________HOME_ROW_CAGS_L______________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_CAGS_R______________ XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL

/** Base layer */
#define _____________TOP_ALPHAS_ROW_L______________ KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y
#define _____________TOP_ALPHAS_ROW_R______________ KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _____________MID_ALPHAS_ROW_L______________ KC_A,    KC_O,    KC_E,    KC_U,    KC_I
#define _____________MID_ALPHAS_ROW_R______________ KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _____________BOT_ALPHAS_ROW_L______________ KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X
#define _____________BOT_ALPHAS_ROW_R______________ KC_B,    KC_M,    KC_W,    KC_V,    KC_Z
#ifdef TUCKY_THUMBS_L
#    define ____ALPHAS_THUMBS_L______ KC_GRV, TAB_FUN, BSP_NAV
#else
#    define ____ALPHAS_THUMBS_L______ TAB_FUN, BSP_NAV, KC_GRV
#endif // TUCKY_THUMBS_L
#ifdef TUCKY_THUMBS_R
#    define ____ALPHAS_THUMBS_R______ SPC_NUM, ENT_SYM, KC_ESC
#else
#    define ____ALPHAS_THUMBS_R______ KC_ESC,  SPC_NUM, ENT_SYM
#endif // TUCKY_THUMBS_R

/** Function layer */
#define _____________TOP_FUNCTION_ROW_L____________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _____________TOP_FUNCTION_ROW_R____________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _____________MID_FUNCTION_ROW_L____________ ______________HOME_ROW_CAGS_L______________
#define _____________MID_FUNCTION_ROW_R____________ KC_VOLU, RSFT(KC_LEFT), RSFT(KC_UP), RSFT(KC_DOWN), RSFT(KC_RGHT)
#define _____________BOT_FUNCTION_ROW_L____________ _______________DEAD_HALF_ROW_______________
#define _____________BOT_FUNCTION_ROW_R____________ KC_VOLD, CW_TOGG, RSFT(RGUI(KC_4)), KC_F11,  KC_F12
#ifdef TUCKY_THUMBS_L
#    define ____FUNCTION_THUMBS_L____ XXXXXXX, _______, XXXXXXX
#else
#    define ____FUNCTION_THUMBS_L____ _______, XXXXXXX, XXXXXXX
#endif // TUCKY_THUMBS_L
#define ____FUNCTION_THUMBS_R____ XXXXXXX, XXXXXXX, XXXXXXX

/** Pointer layer */
#define _____________TOP_POINTER_ROW_L_____________ QK_BOOT, EE_CLR,  XXXXXXX, DPI_MOD, S_D_MOD
#define _____________TOP_POINTER_ROW_R_____________ S_D_MOD, DPI_MOD, RGB_TOG, RGB_M_P, RGB_VAI
#define _____________MID_POINTER_ROW_L_____________ ______________HOME_ROW_CAGS_L______________
#define _____________MID_POINTER_ROW_R_____________ ______________HOME_ROW_CAGS_R______________
#define _____________BOT_POINTER_ROW_L_____________ _______, DRG_TOG, SNIPING, MS_BTN5, MS_BTN4
#define _____________BOT_POINTER_ROW_R_____________ MS_BTN4, MS_BTN5, SNIPING, DRG_TOG, _______
#define ____POINTER_THUMBS_L_____ MS_BTN3, MS_BTN2, MS_BTN1
#define ____POINTER_THUMBS_R_____ MS_BTN1, MS_BTN2, MS_BTN3

/** Navigation layer */
#define ___________TOP_NAVIGATION_ROW_L____________ _______________DEAD_HALF_ROW_______________
#define ___________TOP_NAVIGATION_ROW_R____________ XXXXXXX, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR
#define ___________MID_NAVIGATION_ROW_L____________ ______________HOME_ROW_CAGS_L______________
#define ___________MID_NAVIGATION_ROW_R____________ KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
#define ___________BOT_NAVIGATION_ROW_L____________ _______________DEAD_HALF_ROW_______________
#define ___________BOT_NAVIGATION_ROW_R____________ KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END
#ifdef TUCKY_THUMBS_L
#    define ___NAVIGATION_THUMBS_L___ XXXXXXX, XXXXXXX, _______
#else
#    define ___NAVIGATION_THUMBS_L___ XXXXXXX, _______, XXXXXXX
#endif // TUCKY_THUMBS_L
#ifdef TUCKY_THUMBS_R
#    define ___NAVIGATION_THUMBS_R___ KC_SPC,  KC_ENT,  KC_DEL
#else
#    define ___NAVIGATION_THUMBS_R___ KC_DEL,  KC_SPC,  KC_ENT,
#endif // TUCKY_THUMBS_R

/** Numeral layer */
#define _____________TOP_NUMERAL_ROW_L_____________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _____________TOP_NUMERAL_ROW_R_____________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _____________MID_NUMERAL_ROW_L_____________ KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS
#define _____________MID_NUMERAL_ROW_R_____________ ______________HOME_ROW_CAGS_R______________
#define _____________BOT_NUMERAL_ROW_L_____________ KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH
#define _____________BOT_NUMERAL_ROW_R_____________ _______________DEAD_HALF_ROW_______________
#if defined(TUCKY_THUMBS_L) || defined(TUCKY_NUMERAL_THUMBS_L)
#    define ____NUMERAL_THUMBS_L_____ KC_DOT, KC_MINS, KC_EQL
#else
#    define ____NUMERAL_THUMBS_L_____ KC_MINS, KC_EQL,  KC_DOT
#endif // TUCKY_THUMBS_L
#ifdef TUCKY_THUMBS_R
#    define ____NUMERAL_THUMBS_R_____ _______, XXXXXXX, XXXXXXX
#else
#    define ____NUMERAL_THUMBS_R_____ XXXXXXX, _______, XXXXXXX
#endif // TUCKY_THUMBS_R

/** Symbols layer */
#define _____________TOP_SYMBOLS_ROW_L_____________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _____________TOP_SYMBOLS_ROW_R_____________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _____________MID_SYMBOLS_ROW_L_____________ KC_LCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE
#define _____________MID_SYMBOLS_ROW_R_____________ ______________HOME_ROW_CAGS_R______________
#define _____________BOT_SYMBOLS_ROW_L_____________ KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES
#define _____________BOT_SYMBOLS_ROW_R_____________ _______________DEAD_HALF_ROW_______________
#if defined(TUCKY_THUMBS_L) || defined(TUCKY_SYMBOLS_THUMBS_L)
#    define ____SYMBOLS_THUMBS_L_____ KC_TILD, KC_UNDS, KC_PLUS
#else
#    define ____SYMBOLS_THUMBS_L_____ KC_UNDS, KC_PLUS, KC_TILD
#endif // TUCKY_THUMBS_L
#ifdef TUCKY_THUMBS_R
#    define ____SYMBOLS_THUMBS_R_____ XXXXXXX, _______, XXXXXXX
#else
#    define ____SYMBOLS_THUMBS_R_____ XXXXXXX, XXXXXXX, _______
#endif // TUCKY_THUMBS_R

// clang-format on
