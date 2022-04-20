#include "keymap.h"

#if KEYBOARD_SIDE == LEFT

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_SPC,
                          LAYER_3, LAYER_3, LAYER_1, KC_SPC
    )};

void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
  KC_DEL  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
  KC_LSFT ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , KC_SPC,   \
                            LAYER_3,      LAYER_3, LAYER_1, KC_SPC \
);

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_TILD ,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,  \
  KC_TILD ,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,  \
  KC_DEL  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
  KC_LSFT ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11, KC_SPC , \
    LAYER_3,LAYER_3, LAYER_1, KC_SPC \
);

    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
  KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
 _______, _______,_______,_______, _______, _______,    \
  KC_LSFT,_______,_______,_______, _______, _______, _______, \
   LAYER_3, LAYER_3, LAYER_1,KC_SPC \
);

    uint32_t layer4[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
  KC_CALC,KC_F1,   KC_F2,  KC_F3,   KC_F4, KC_VOLU,  \
 PRINT_INFO, _______,_______,_______, _______, KC_VOLD,    \
  KC_LSFT,_______,_______,_______, _______, _______, _______, \
   LAYER_3, LAYER_3, LAYER_1,KC_SPC \
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, layer3[row][col]);
            matrix[row][col].addActivation(_L4, Method::PRESS, layer4[row][col]);
        }
    }
}

#endif  // left
