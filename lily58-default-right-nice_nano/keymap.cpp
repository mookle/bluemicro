#include "keymap.h"

#if KEYBOARD_SIDE == RIGHT

// COLEMAK Mod-DH
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
//          +---------|---------|---------|---------|---------|---------+
               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_DEL,
//          |---------|---------|---------|---------|---------|---------|
               KC_J,     KC_L,     KC_U,     KC_Y,    KC_SCLN,  KC_QUOT,
//          |---------|---------|---------|---------|---------|---------|
               KC_M,     KC_N,     KC_E,     KC_I,     KC_O ,   KC_ENT,
//+---------|---------|---------|---------|---------|---------|---------|
    KC_RBRC,   KC_K,     KC_H,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSHIFT,
//|---------|---------|---------|---------|---------|---------|---------+
    KC_SPC,   LAYER_3, KC_RCTRL,  XXXXXXX \
//+---------|---------|---------|---------+
)};

void setupKeymap() {
    // QWERTY
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//          +---------|---------|---------|---------|---------|---------+
              _______,  _______,  _______,  _______,  _______,  KC_BSPC, \
//          |---------|---------|---------|---------|---------|---------|
               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    _______, \
//          |---------|---------|---------|---------|---------|---------|
               KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  _______, \
//+---------|---------|---------|---------|---------|---------|---------|
    _______,   KC_N,     KC_M,    _______,  _______,  _______,  KC_RALT, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  _______,  _______,  _______ \
//+---------|---------|---------|---------+
);
    // Lower
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//          +---------|---------|---------|---------|---------|---------+
               KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  KC_LEFT,  KC_DOWN,   KC_UP,  KC_RIGHT,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_BSLS,  _______, \
//|---------|---------|---------|---------|---------|---------|---------+
    KC_UNDS,  LAYER_4,  _______,  _______ \
//+---------|---------|---------|---------+
);

    // Raise
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//          +---------|---------|---------|---------|---------|---------+
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TILD, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  _______,  _______,  _______ \
//+---------|---------|---------|---------+
);

    // Super
    uint32_t layer4[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//          +---------|---------|---------|---------|---------|---------+
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//          |---------|---------|---------|---------|---------|---------|
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  _______,  _______,  _______ \
//+---------|---------|---------|---------+
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
