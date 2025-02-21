#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HMRW_A LGUI_T(KC_A)
#define HMRW_R LALT_T(KC_R)
#define HMRW_S LCTL_T(KC_S)
#define HMRW_T LSFT_T(KC_T)

// Right-hand home row mods
#define HMRW_N RSFT_T(KC_N)
#define HMRW_E RCTL_T(KC_E)
#define HMRW_I LALT_T(KC_I)
#define HMRW_O RGUI_T(KC_O)

// Thumb keys
#define L1_TAB LT(1, KC_TAB)
#define L2_SPC LT(2, KC_SPC)
#define L3_ENT LT(3, KC_ENT)
#define L4_BSPC LT(4, KC_BSPC)

// Per-key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMRW_A:
            return TAPPING_TERM + 1000;
        case HMRW_R:
            return TAPPING_TERM + 500;
        case HMRW_S:
            return TAPPING_TERM + 200;
        case HMRW_E:
            return TAPPING_TERM + 200;
        case HMRW_I:
            return TAPPING_TERM + 500;
        case HMRW_O:
            return TAPPING_TERM + 1000;
        case L3_ENT:
            return TAPPING_TERM + 1000;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        // Alphas
        KC_Q       , KC_W       , KC_F       , KC_P       , KC_B       , KC_J       , KC_L       , KC_U       , KC_Y       , KC_QUOT    ,
        HMRW_A     , HMRW_R     , HMRW_S     , HMRW_T     , KC_G       , KC_M       , HMRW_N     , HMRW_E     , HMRW_I     , HMRW_O     ,
        KC_Z       , KC_X       , KC_C       , KC_D       , KC_V       , KC_K       , KC_H       , KC_COMM    , KC_DOT     , KC_SLSH    ,
                                               L1_TAB     , L2_SPC     , L3_ENT     , L4_BSPC
    ),
    [1] = LAYOUT_split_3x5_2(
        // Numbers
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_PAST    , KC_7       , KC_8       , KC_9       , KC_PPLS    ,
        KC_LGUI    , KC_LALT    , KC_LCTL    , KC_LSFT    , XXXXXXX    , KC_PSLS    , KC_4       , KC_5       , KC_6       , KC_PMNS    ,
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_DOT     , KC_1       , KC_2       , KC_3       , KC_PEQL    ,
                                             XXXXXXX    , KC_TRNS    , KC_BSPC    , KC_0
    ),
    [2] = LAYOUT_split_3x5_2(
        // Navigation
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_PGUP    , KC_HOME    , KC_INS     , KC_END     , KC_PSCR    ,
        KC_LGUI    , KC_LALT    , KC_LCTL    , KC_LSFT    , XXXXXXX    , KC_PGDN    , KC_LEFT    , KC_DOWN    , KC_UP      , KC_RGHT    ,
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5),
                                               KC_TRNS    , XXXXXXX    , KC_ESC     , KC_DEL
    ),
    [3] = LAYOUT_split_3x5_2(
        // Function
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_CAPS    , KC_F1      , KC_F2      , KC_F3      , KC_F4      ,
        KC_LGUI    , KC_LALT    , KC_LCTL    , KC_LSFT    , XXXXXXX    , KC_NUM     , KC_F5      , KC_F6      , KC_F7      , KC_F8      ,
        XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_SCRL    , KC_F9      , KC_F10     , KC_F11     , KC_F12     ,
                                               XXXXXXX    , XXXXXXX    , KC_TRNS    , KC_LGUI
    ),
    [4] = LAYOUT_split_3x5_2(
        // Symbols
        //      !   @   #   $   %   ^   &   *
        //      <   [   (   {   /   \   }   )   ]   >
        //      `   ~   :   ;   ?   |   -   _   +   =
        KC_EXLM    , KC_AT      , KC_HASH    , KC_DLR     , XXXXXXX    , XXXXXXX    , KC_PERC    , KC_CIRC    , KC_AMPR    , KC_ASTR    ,
        KC_LABK    , KC_LBRC    , KC_LPRN    , KC_LCBR    , KC_SLSH    , KC_BSLS    , KC_RCBR    , KC_RPRN    , KC_RBRC    , KC_RABK    ,
        KC_GRV     , KC_TILD    , KC_COLN    , KC_SCLN    , KC_QUES    , KC_PIPE    , KC_MINS    , KC_UNDS    , KC_PLUS    , KC_EQL     ,
                                               XXXXXXX    , XXXXXXX    , XXXXXXX    , KC_TRNS
    )
};
