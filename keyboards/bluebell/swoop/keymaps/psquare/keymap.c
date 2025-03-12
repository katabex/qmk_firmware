/* Copyright 2022 James White <jamesmnw@gmail.com>
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

enum layer_names {
  _BSE,
  _NAV,
  _SYM,
  _NUM,
  _MED
};

#define NAV  MO(_NAV)
#define SYM  MO(_SYM)
#define NUM  MO(_NUM)
#define MED  MO(_MED)

#define SF_F LSFT_T(KC_F)
#define SF_J RSFT_T(KC_J)
#define CT_D LCTL_T(KC_D)
#define CT_K RCTL_T(KC_K)
#define AL_S LALT_T(KC_S)
#define AL_L RALT_T(KC_L)

#define NAV_SPC LT(NAV, KC_SPC)
#define SYM_ENT LT(SYM, KC_ENT)
#define NUM_BSP LT(NUM, KC_BSPC)
#define MED_TAB LT(MED, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_3(
	KC_Q, KC_W, KC_E, KC_R, KC_T, 							            KC_Y, KC_U, KC_I, KC_O, KC_P,
	KC_A, KC_S, KC_D, KC_F, KC_G,		                                                    KC_H, KC_J, KC_K, KC_L, KC_SCLN,
	MT(MOD_LGUI, KC_Z), MT(MOD_LALT, KC_X), MT(MOD_LCTL, KC_C), MT(MOD_LSFT, KC_V), KC_B, 	    KC_N, MT(MOD_RSFT, KC_M), MT(MOD_RCTL, KC_COMM), MT(MOD_RALT, KC_DOT), MT(MOD_RGUI, KC_SLSH),
	KC_LCTL, LT(1,KC_SPC), LT(4,KC_TAB), 							    LT(2,KC_ENT), LT(3,KC_BSPC), KC_LALT
),


    [1] = LAYOUT_split_3x5_3(
	KC_ESC, KC_DEL, KC_NO, KC_NO, KC_NO, 		KC_CIRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,
	KC_TAB, KC_BSPC, KC_LCTL, KC_LSFT, KC_NO, 	KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DLR,
	KC_NO, KC_NO, KC_LCTL, KC_LSFT, KC_PSCR, 	KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_INS,
	KC_LCTL, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_LALT
),


    [2] = LAYOUT_split_3x5_3(
	KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_HASH, 	KC_CIRC, KC_TILD, KC_NO, KC_NO, KC_NO,
	KC_DLR, KC_PERC, KC_LCBR, KC_RCBR, KC_PSLS, 	KC_BSLS, KC_UNDS, KC_NO, KC_NO, KC_NO,
	KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_QUOT,	KC_DQUO, KC_PIPE, KC_NO, KC_NO, KC_NO,
	KC_LCTL, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_LALT
),


    [3] = LAYOUT_split_3x5_3(
	KC_EQL, KC_7, KC_8, KC_9, KC_0, 		    KC_HASH, KC_F9, KC_F10, KC_F11, KC_F12,
	KC_PAST, KC_4, 	KC_5, KC_6, KC_PPLS, 		    KC_COMM, KC_F5, KC_F6, KC_F7, KC_F8,
	KC_PSLS, KC_1, KC_2, KC_3, KC_PMNS, 		    KC_UNDS, MT(MOD_RSFT, KC_F1), KC_F2, KC_F3, KC_F4,
	KC_LCTL, KC_TRNS, KC_TRNS, 	    		    KC_TRNS, KC_TRNS, KC_LALT
),


    [4] = LAYOUT_split_3x5_3(
	RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, 		KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,
	RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, 	KC_VOLU, KC_MFFD, KC_NO, KC_NO, KC_NO,
	RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, 	KC_VOLD, KC_MRWD, KC_NO, KC_NO, QK_BOOT,
	KC_LCTL, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_LALT
)
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_DOWN, KC_UP)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWE\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("SYM\n"), false);
            break;
	case 3:
            oled_write_P(PSTR("NUM\n"), false);
            break;
	case 4:
            oled_write_P(PSTR("MED\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Querty"), false);
	}
    }	else { 
        render_logo();  // Renders a static logo
        //oled_scroll_left();  // Turns on scrolling

    }
    
    return false;
}
