#include "keymap.h"

#if KEYBOARD_SIDE == RIGHT

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPACE, 
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
     KC_SPC,   KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH,   KC_ENT,
        KC_SPC,  LAYER_2, LAYER_4, LAYER_3
    )};

void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
    KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC,   KC_BSLS,   \
 KC_SPC,    KC_F12,  KC_NUHS, KC_NUBS, _______,  _______,   _______,  \
    KC_SPC,   LAYER_2, LAYER_4, LAYER_3\
);

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   \
KC_SPC,  KC_F12,  KC_NUTL, KC_NUPI,_______, _______, _______,  \
  KC_SPC,  LAYER_2, LAYER_4, LAYER_3 \
);

    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_INS,  \
  _______,  _______,  _______,  _______,  _______,  _______,   \
 KC_SPC,   _______,  _______,  _______,  _______,  _______,  _______,  \
  KC_SPC,   LAYER_2,  LAYER_4, LAYER_3 \
);

    uint32_t layer4[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
         KC_VOLU,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_CALC,  \
  KC_VOLU,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_CALC,  \
  KC_VOLD,  _______,  _______,  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN2,   \
  KC_SPC,  PRINT_INFO,  _______,  _______,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  \
  KC_SPC,   LAYER_2,  LAYER_4 , LAYER_3\
);

    /*
     * add the other layers
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

#endif
