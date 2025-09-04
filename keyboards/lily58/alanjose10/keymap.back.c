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

enum layers {
    _DVORAK = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
    _TBD
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE MO(_MOUSE)
#define TBD MO(_TBD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK(programmer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   ;  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CPS  |   A  |CTL,O |ALT,E |GUI,U |   I  |-------.    ,-------|   D  |GUI,H |ALT,T |CTL,N |   S  |      |
 * |------+------+------+------+------+------| MOUSE |    |  TBD  |------+------+------+------+------+------|
 * |      |   '  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | LOWER| /SFT,Spc/       \SFT,Ent\  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `-------------------''-------'           '------''---------------------'
 */
[_DVORAK] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  KC_TAB, KC_SCLN, KC_COMM, KC_DOT,  KC_P,   KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  KC_CAPS, KC_A, LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I,        KC_D, RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N), KC_S, XXXXXXX,
  XXXXXXX, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X, MOUSE,          TBD,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
                      _______, KC_ESC, LOWER, RSFT_T(KC_SPC),         RSFT_T(KC_ENT),  RAISE,  KC_BSPC,  _______
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
 * |      |      |      |      |      |      |-------|    |-------|   +  |   =  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
  DT_UP,   NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
  DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
  DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
                            _______, _______, _______,  _______, _______,  _______, _______, _______
  ),


/* MOUSE 
 * Mouse control layer.
  *
  * 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | MSB1 | MSUP | MSB2 |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |MSLFT | MSDN | MSRT |      |      |
 * |------+------+------+------+------+------|   \/  |    |  \/   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, MS_BTN1, MS_UP, MS_BTN2, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            _______, _______, _______,  _______, _______,  _______, _______, _______
  ),


/* TBD 
 * Layer not yet defined
  *
  * 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   \/  |    |  \/   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  \/  |  \/  |  \/  | /  \/   /       \ \/   \  |  \/  |  \/  |  \/  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_TBD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            _______, _______, _______,  _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}


static void render_logo(void) {
	
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

char wpm[4];
// char layer_misc[7];


static void render_status(void) {
    // oled_write_P(PSTR("layer "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("DVORAK"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST"), false);
            break;
        case _MOUSE:
          oled_write_P(PSTR("MOUSE"), false);
          break;
        case _TBD:
            oled_write_P(PSTR("TBD"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }

    oled_write_P(PSTR("  "), false);
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write(wpm, false);
    oled_write_P(PSTR (" wpm"), false);
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
    oled_write_P(PSTR("klg"), false);
    oled_write(keylog_str, false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {

    // Show layer information and current wpm
    render_status();

    // Show modifier status
    render_mod_status(get_mods());

    render_keylogger_status();

  } else {
    render_logo();
  }
    return false;
}

#endif // OLED_ENABLE

