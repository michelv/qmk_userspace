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

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI
#define ______________HOME_ROW_CAGS_L______________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_CAGS_R______________ XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL
