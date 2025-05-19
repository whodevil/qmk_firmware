/* Copyright 2022 MechMerlin
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
extern MidiDevice midi_device;

enum custom_keycodes {
    MIDI_PC4 = SAFE_RANGE,
    MIDI_PC5,
    MIDI_PC6,
    MIDI_PC7,
    MIDI_PC8,
    MIDI_PC9,
    MIDI_PC10,
    MIDI_PC11,
    MIDI_PC12,
    MIDI_PC13,
    MIDI_PC14,
    MIDI_PC15,
    MIDI_PC16,
    MIDI_PC17,
    MIDI_PC18,
};


void keyboard_post_init_user(void) {
    // Call the post init code.
}

bool midi_pc_send(keyrecord_t *record, uint8_t num) {
	if (record->event.pressed) {
    	midi_send_programchange(&midi_device, midi_config.channel, num);
    }
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MIDI_PC4:
            return midi_pc_send(record, 4);

        case MIDI_PC5:
            return midi_pc_send(record, 5);

        case MIDI_PC6:
            return midi_pc_send(record, 6);

        case MIDI_PC7:
            return midi_pc_send(record, 7);

        case MIDI_PC8:
            return midi_pc_send(record, 8);

        case MIDI_PC9:
            return midi_pc_send(record, 9);

        case MIDI_PC10:
            return midi_pc_send(record, 10);

        case MIDI_PC11:
            return midi_pc_send(record, 11);

        case MIDI_PC12:
            return midi_pc_send(record, 12);

        case MIDI_PC13:
            return midi_pc_send(record, 13);

        case MIDI_PC14:
            return midi_pc_send(record, 14);

        case MIDI_PC15:
            return midi_pc_send(record, 15);

        case MIDI_PC16:
            return midi_pc_send(record, 16);

        case MIDI_PC17:
            return midi_pc_send(record, 17);

        case MIDI_PC18:
            return midi_pc_send(record, 18);
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x4( /* Base */
    MIDI_PC15,   MIDI_PC16,    MIDI_PC17,    MIDI_PC18,
    MIDI_PC11,   MIDI_PC12,    MIDI_PC13,    MIDI_PC14,
    MIDI_PC7,    MIDI_PC8,     MIDI_PC9,     MIDI_PC10,
    MO(1),       MIDI_PC4,     MIDI_PC5,     MIDI_PC6
  ),

  [1] = LAYOUT_ortho_4x4( /* Fn Layer */
    MI_TOGG,   RM_HUEU,    RM_SATU,    RM_VALU,
    RM_NEXT,   RM_HUED,    RM_SATD,    RM_VALD,
    RM_SPDD,   RM_SPDU,    KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    QK_BOOT
  ),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    RGB_MATRIX_INDICATOR_SET_COLOR(12, 0, 0, 255); // assuming caps lock is at led #5
    RGB_MATRIX_INDICATOR_SET_COLOR(13, 0, 0, 255); // assuming caps lock is at led #5
    RGB_MATRIX_INDICATOR_SET_COLOR(14, 0, 0, 255); // assuming caps lock is at led #5
    RGB_MATRIX_INDICATOR_SET_COLOR(9, 0, 0, 255); // assuming caps lock is at led #5

    RGB_MATRIX_INDICATOR_SET_COLOR(3, 255, 0, 0);
    RGB_MATRIX_INDICATOR_SET_COLOR(2, 255, 0, 0);
    RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 0, 0);

    return false;
}