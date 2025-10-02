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

#include "keymap_shortcuts.h"
#include "keymap_home_row_mods.h"
#include "keymap_pointer_mod.h"
#include "keymap_layers.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// clang-format off

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

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FUNCTION]   = {ENCODER_CCW_CW(KC_DOWN, KC_UP),    ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_NAVIGATION] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI),  ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [LAYER_NUMERAL]    = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [LAYER_SYMBOLS]    = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER);
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}


// source: brom keymap.c

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

#ifdef RGB_MATRIX_ENABLE
enum colors {
    hOFF = 0,
    hPURPLE,
    hPINK,
    hCYAN,
    hTORQ,
    hLRED,
    hBLUE,
    hORANGE,
    hRED
};

// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                    hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
  [LAYER_FUNCTION] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                    hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,      hCYAN,      hCYAN,      hCYAN,      hCYAN,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                    hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
  [LAYER_POINTER] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                 hORANGE,      hLRED,       hRED,                    hRED,      hLRED,    hORANGE
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
  [LAYER_NUMERAL] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
            hOFF,      hCYAN,      hCYAN,      hCYAN,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,      hCYAN,      hCYAN,      hCYAN,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,      hCYAN,      hCYAN,      hCYAN,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                    hOFF,       hOFF,      hCYAN,                    hOFF,       hOFF,       hOFF
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
           hLRED,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
           hLRED,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
            hOFF,       hOFF,       hOFF,       hOFF,       hOFF,                    hOFF,       hOFF,       hOFF,       hOFF,       hOFF,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                 hORANGE,       hOFF,    hORANGE,                    hOFF,       hOFF,       hOFF
  //                          ╰───────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),
};
// clang-format on

const HSV hsv_colors[] = {
    [hOFF]      = {  0,   0,   0},
    [hPURPLE]   = {205, 255, 255},
    [hPINK]     = {251, 223, 255},
    [hCYAN]     = {128, 255, 255},
    [hTORQ]     = {120, 255, 204},
    [hLRED]     = {255, 239, 255},
    [hBLUE]     = {170, 215, 221},
    [hORANGE]   = { 20, 208, 255},
    [hRED]      = {  0, 255, 255}
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        int layer = get_highest_layer(layer_state|default_layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if(led_min <= index && index <= led_max) {
                    uint8_t color = pgm_read_byte(&ledmaps[layer][row][col]);
                    HSV hsv = hsv_colors[color];
                    if(hsv.s > 0)
                        hsv.v = rgb_matrix_config.hsv.v;
                    RGB rgb = hsv_to_rgb(hsv);
                    rgb_matrix_set_color( index, rgb.r, rgb.g, rgb.b );
                };
            };
        };
    return false;
}
#endif
