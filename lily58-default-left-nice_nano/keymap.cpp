#include "keymap.h"

// COLEMAK Mod-DH
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
//+---------|---------|---------|---------|---------|---------+
    KC_ESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
//|---------|---------|---------|---------|---------|---------|
    KC_TAB,    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,
//|---------|---------|---------|---------|---------|---------|
    KC_BSPC,   KC_A,     KC_R,     KC_S,     KC_T,     KC_G,
//|---------|---------|---------|---------|---------|---------|---------+
   KC_LSHIFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,    KC_LBRC,
//+---------|---------|---------|---------|---------|---------|---------|
                                  KC_LALT,  KC_LGUI,  LAYER_2,  KC_SPC
//                              +---------|---------|---------|---------+
)};

void setupKeymap() {
    // QWERTY
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//+---------|---------|---------|---------|---------|---------+
    _______,  _______,  _______,  _______,  _______,  _______, \
//|---------|---------|---------|---------|---------|---------|
    _______,  _______,  _______,   KC_E,     KC_R,     KC_T, \
//|---------|---------|---------|---------|---------|---------|
   KC_LSHIFT, _______,   KC_S,     KC_D,     KC_F,    _______, \
//|---------|---------|---------|---------|---------|---------|---------+
   KC_LCTRL,  _______,  _______,  _______,   KC_V,     KC_B,    _______, \
//+---------|---------|---------|---------|---------|---------|---------|
                                  _______,  _______,  _______,  _______ \
//                              +---------|---------|---------|---------+
);
    // Lower
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//+---------|---------|---------|---------|---------|---------+
    KC_GRV,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  VM_QUIT,  VM_SAVE,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
                                  _______,  _______,  _______,  _______ \
//                              +---------|---------|---------|---------+
);
    // Raise
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//+---------|---------|---------|---------|---------|---------+
    KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6, \
//|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|
    KC_LCBR,  KC_LBRC,  KC_LPRN,  KC_RPRN,  KC_RBRC,  KC_RCBR, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
                                  _______,  _______,  LAYER_4,  KC_MINS \
//                              +---------|---------|---------|---------+
);
    // Super
    uint32_t layer4[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
//+---------|---------|---------|---------|---------|---------+
    XXXXXXX,TG(LAYER_1),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//|---------|---------|---------|---------|---------|---------|---------+
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
//+---------|---------|---------|---------|---------|---------|---------|
                                  _______,  _______,  _______,  _______ \
//                              +---------|---------|---------|---------+
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

void process_user_macros(uint16_t macroid)
{
    switch((macroid))
    {
        case VM_QUIT:
            addStringToQueue(":q");
            break;
        case VM_SAVE:
            addStringToQueue(":w");
            break;
    }
}
