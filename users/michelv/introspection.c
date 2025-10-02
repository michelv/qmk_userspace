#include QMK_KEYBOARD_H

/**
 * \brief Combos.
 */

enum combos {
    /** Single characters. */
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
    /** Functions. */
    UH_CAPSWORD,
    /** Bigrams/trigrams. */
    COMMDOT_DOUBLEARROW,
    DOTP_ARROW,
    BM_HOME_DIR,
    /** Shortcuts. */
    KX_COMMENT,
};

const uint16_t PROGMEM AQUOT_combo[]   = {LCTL_T(KC_A), KC_QUOT, COMBO_END};
const uint16_t PROGMEM OCOMM_combo[]   = {LALT_T(KC_O), KC_COMM, COMBO_END};
const uint16_t PROGMEM EDOT_combo[]    = {LGUI_T(KC_E), KC_DOT, COMBO_END};
const uint16_t PROGMEM UP_combo[]      = {LSFT_T(KC_U), KC_P, COMBO_END};
const uint16_t PROGMEM IY_combo[]      = {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM DF_combo[]      = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM HG_combo[]      = {RSFT_T(KC_H), KC_G, COMBO_END};
const uint16_t PROGMEM TC_combo[]      = {RGUI_T(KC_T), KC_C, COMBO_END};
const uint16_t PROGMEM NR_combo[]      = {LALT_T(KC_N), KC_R, COMBO_END};
const uint16_t PROGMEM SL_combo[]      = {RCTL_T(KC_S), KC_L, COMBO_END};
const uint16_t PROGMEM UH_combo[]      = {LSFT_T(KC_U), RSFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM COMMDOT_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM DOTP_combo[]    = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM BM_combo[]      = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM KX_combo[]      = {KC_K, KC_X, COMBO_END};

// clang-format off

combo_t key_combos[] = {
    [AQUOT_EXLM]          = COMBO(AQUOT_combo, KC_EXLM),
    [OCOMM_AT]            = COMBO(OCOMM_combo, KC_AT),
    [EDOT_HASH]           = COMBO(EDOT_combo, KC_HASH),
    [UP_DLR]              = COMBO(UP_combo, KC_DLR),
    [IY_PERC]             = COMBO(IY_combo, KC_PERC),
    [DF_CIRC]             = COMBO(DF_combo, KC_CIRC),
    [HG_AMPR]             = COMBO(HG_combo, KC_AMPR),
    [TC_ASTR]             = COMBO(TC_combo, KC_ASTR),
    [NR_LPRN]             = COMBO(NR_combo, KC_LPRN),
    [SL_RPRN]             = COMBO(SL_combo, KC_RPRN),
    [UH_CAPSWORD]         = COMBO(UH_combo, CW_TOGG),
    [COMMDOT_DOUBLEARROW] = COMBO_ACTION(COMMDOT_combo),
    [DOTP_ARROW]          = COMBO_ACTION(DOTP_combo),
    [BM_HOME_DIR]         = COMBO_ACTION(BM_combo),
    [KX_COMMENT]          = COMBO(KX_combo, LGUI(KC_SLSH)),
};

// clang-format on

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
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
        case BM_HOME_DIR:
            if (pressed) {
                SEND_STRING("~/");
            }
            break;
    }
}
