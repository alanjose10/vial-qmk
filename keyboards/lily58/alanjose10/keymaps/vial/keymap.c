 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK(programmer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ;  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |CTL,O |ALT,E |GUI,U |   I  |-------.    ,-------|   D  |GUI,H |ALT,T |CTL,N |   S  |      |
 * |------+------+------+------+------+------| MOUSE |    |  TBD  |------+------+------+------+------+------|
 * |      |   '  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CPS  | TAB  | LOWER| /SFT,Spc/       \SFT,Ent\  |RAISE | BKSP | ESC  |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `-------------------''-------'           '------''---------------------'
 */
[_BASE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,   KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L, _______,
  _______, KC_A, LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I,        KC_D, RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N), KC_S, _______,
  _______, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X, _______,          _______,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, _______,
                      KC_CAPS, KC_TAB, LOWER, RSFT_T(KC_SPC),         RSFT_T(KC_ENT),  RAISE,  KC_BSPC,  KC_ESC
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   $  |   &  |   [  |  {   |  }   |  (   |                    |   =  |   *  |  )   |   +  |   ]  |  !   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   %  |CTL,7 |ALT,5 |GUI,3 |  1   |-------.    ,-------|   9  |GUI,0 |ALT,2 |CTL,4 |   6  |  8   |
 * |------+------+------+------+------+------|   \/  |    |  \/   |------+------+------+------+------+------|
 * |   <  |  |   |  \   |  -   |  _   |  @   |-------|    |-------|  ^   |   #  |  `   |  /   |   ?  |  >   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  KC_DLR, KC_AMPR, KC_LBRC,   KC_LCBR, KC_RCBR,  KC_LPRN,                                           KC_EQL, KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM,
  KC_TILD, KC_PERC, LCTL_T(KC_7), LALT_T(KC_5), LGUI_T(KC_3), KC_1,                                 KC_9, RGUI_T(KC_0), RALT_T(KC_2), RCTL_T(KC_4), KC_6, KC_8,
  KC_LT, KC_PIPE,  KC_BSLS, KC_MINS, KC_UNDS, KC_AT, _______,                             _______, KC_CIRC, KC_HASH, KC_GRV, KC_SLSH, KC_QUES, KC_LT,
                                          _______, _______, _______, _______, _______,  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   \/  |    |  \/   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST 
 * This layer is for debugging and making adjustments.
  * This layer can only be assessed by pressing the MO(1) and MO(2) keys.
  * 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |DT_UP |NKTOGG|      |      |      |      |                    |      | PLPS | MUTE |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |DT_DN |      |      |      |      |      |-------.    ,-------| PREV | VOLD | VOLU | NXT  |      |      |
 * |------+------+------+------+------+------|  Mac  |    |  Win  |------+------+------+------+------+------|
 * |DT_PRT|      |      |      |      |      |-------|    |-------|      |KC_BRD|KC_BRU|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  DT_UP,   NK_TOGG, MS_BTN1, MS_UP, MS_BTN2, XXXXXXX,                     XXXXXXX,  KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
  DT_DOWN, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
  DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

char wpm[4];
char layer_misc[7];


static void render_layer_status(void) {

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR(" BASE "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST"), false);
            break;
        default:
            sprintf(layer_misc, "MO(%01d) ", get_highest_layer(layer_state));
	    oled_write(layer_misc, false);
            break;
    }

    oled_write_P(PSTR("  "), false);
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write(wpm, false);
    oled_write_P(PSTR(" wpm\n"), false);
}



#define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write(keylog_str, false);
}

void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);
}




bool oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_layer_status();
        oled_write_P(PSTR("\n"), false);

        render_keylogger_status();
        oled_write_P(PSTR("\n"), false);

    } else {
        render_qmk_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}

#endif // OLED_ENABLE


