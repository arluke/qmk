/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _BASE,
    _FUNCT,
    _EXTRA
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

// #define FN       MO(_FN)
// #define ADJUST   MO(_ADJUST)
#define EXTRA		DF(_EXTRA)
#define FUNCT		DF(_FUNCT)
#define BASE		DF(_BASE)
//#define FN_CAPS	LT(_FN, KC_CAPS)
//#define RGB_ADJ	LT(_ADJUST, RGB_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,           KC_5,     KC_6,                      KC_MUTE, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,     KC_BTN1,                   KC_VOLU, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,           KC_G,     CW_TOGG,                   KC_VOLD, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,     KC_LBRC,                   KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
        KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, LCTL(KC_LSFT),  KC_SPC,   MO(2),   MO(1),   MO(1),   KC_BSLS, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  
    ),

    [_FUNCT] = LAYOUT(
        KC_PSCR, KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,
        KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,          KC_NO,    KC_NO,                     KC_NO,   KC_PGUP, KC_HOME, KC_NO,   KC_END,  KC_NO,   KC_DEL,
        KC_ESC,  KC_F5,   KC_F6,   KC_F7,   KC_F8,          KC_NO,    KC_NO,                     KC_NO,   KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
        KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_NO,    KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   SC_SENT,
        KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, KC_NO,          KC_SPC,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_SPC,  KC_CAPS, KC_NUM,  KC_SCRL, KC_NO,   KC_RCTL,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  
    ),

    [_EXTRA] = LAYOUT(
        KC_NO,   KC_NO,   RGB_VAI, RGB_SAI, RGB_HUI,        RGB_MOD,  RGB_TOG,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
        KC_NO,   KC_NO,   RGB_VAD, RGB_SAD, RGB_HUD,        RGB_RMOD, RGB_M_P,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_NO,                     KC_NO,   KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   
        NK_ON,   NK_OFF,  KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
        GUI_ON,  GUI_OFF, KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  
    ),
/*
    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_PGDN,
        _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, CK_TOGG,   CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT,   _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, GAME,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM,  QWERTY,  COLEMAK,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO  
    ),
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _FUNCT:
            oled_write_ln_P(PSTR("FUNCT"), false);
            break;
        case _EXTRA:
            oled_write_ln_P(PSTR("EXTRA"), false);
            break; /*
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break; */
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}
