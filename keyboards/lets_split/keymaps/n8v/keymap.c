#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN1 1
#define _NAV 2
#define _SYMBOL 3
#define _SYM 3
#define _MACRO 4

// for TT layer switch
#define TAPPING_TOGGLE 2

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	FN1,
	NAV,
	MACRO,
	SYMBOL
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------.  .------------------------------------------.
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y   |   U  |   I  |   O  |   P  |  Esc |
 * |-------+------+------+------+------+------|  |-------+------+------+------+------+------|
 * |TT(Nav)|   A  |   S  |   D  |  F   |   G  |  |   H   |   J  |   K  |   L  |    ; |   '  |
 * |-------+------+------+------+------+------|  |-------+------+------+------+------+------|
 * | Micro |   Z  |   X  |   C  |   V  |   B  |  |   N   |   M  |   ,  |   .  |   /  | Del  |
 * |-------+------+------+------+------+------|  |-------+------+------+------+------+------|
 * |  Ctrl |  GUI |  Alt |Symbol| Bspc | Shft |  |SpaceN1| Enter| Left | Down | Up   | Right|
 * `------------------------------------------'  '------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
	KC_TAB,       KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,           KC_Y,             KC_U,      KC_I,     KC_O,     KC_P,     KC_ESC, \
	TT(_NAV),     KC_A,     KC_S,     KC_D,       KC_F,     KC_G,           KC_H,             KC_J,      KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
	TG(_MACRO),   KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,           KC_N,             KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_DEL, \
	KC_LCTL,      KC_LGUI,  KC_LALT,  MO(_SYM),   KC_BSPC,  KC_LSFT,        LT(_FN1, KC_SPC),  KC_ENT,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT \
),

/* N1
 * ,-----------------------------------------.  .-------------------------------------------.
 * |  GRV |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |    0  |  END  |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10  |  F12  |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |      |      |      |      |      |      |  | Play | Mute | Prev | Next |VolDown| VolUp |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |      |      |      |      |      |      |  |      |      |      | PgDn |  PgUp |       |
 * `-----------------------------------------'  '-------------------------------------------'
 */
[_FN1] =  KEYMAP( \
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_END, \
	KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, \
	_______, _______, _______, _______, _______, _______,        KC_MPLY,  KC_MUTE,  KC_MPRV,  KC_MNXT,  KC_VOLD,  KC_VOLU, \
	_______, _______, _______, _______, _______, _______,        _______,  _______,  _______,  KC_PGDN,  KC_PGUP,  _______ \
),

/* NAV
 * ,-----------------------------------------.  .-----------------------------------------.
 * |      |   *  |   7  |   8  |   9  |   -  |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   /  |   4  |   5  |   6  |   +  |  | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |  00  |   0  |   .  | Enter|  |      |      |      |      |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_NAV] = KEYMAP( \
	_______, KC_PAST,  KC_7,    KC_8,  KC_9,    KC_PMNS,        _______,  _______,  _______, _______,   _______,  _______, \
	_______, KC_PSLS,  KC_4,    KC_5,  KC_F6,   KC_PPLS,        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,  _______,  _______, \
	_______, _______,  KC_1,    KC_2,  KC_3,    _______,        _______,  _______,  _______, _______,   _______,  _______, \
	_______, _______,  M(0),    KC_0,  KC_DOT,  KC_ENT,         _______,  _______,  _______, _______,   _______,  _______ \
),


/* SYMBOL
 * ,-----------------------------------------.  .-----------------------------------------.
 * |      |      |      |      |      |      |  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |  C1  |  C2  |  C3  |  C4  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_SYMBOL] = KEYMAP( \
	_______, _______, _______, _______, _______, _______,       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
	_______, _______, _______, _______, _______, _______,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
	_______, _______, _______, _______, _______, _______,       _______, M(1),    M(2),    M(3),    M(4),    _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
),

/* MACRO
 * ,-----------------------------------------.  .-----------------------------------------.
 * |      |      |  W1  |  W2  |  W3  |      |  |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |  S1  |      |      |   G  |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_MACRO] =  KEYMAP( \
	_______, _______, M(5),    M(6),    M(7),    _______,       _______, _______, _______, _______, _______, RESET, \
	_______, _______, M(8),    _______, _______, M(9),          _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
)


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
	switch(id) {
		case 0:
			return MACRO( T(0), T(0), END );
			break;
		case 1:
			return MACRO( D(LSFT), T(QUOT), U(LSFT), D(LSFT), T(QUOT), U(LSFT), T(LEFT), END );
			break;
		case 2:
			return MACRO( D(LSFT), T(9), U(LSFT), D(LSFT), T(0), U(LSFT), T(LEFT), END );
			break;
		case 3:
			return MACRO( D(LSFT), T(LBRC), U(LSFT), D(LSFT), T(RBRC), U(LSFT), T(LEFT), END );
			break;
		case 4:
			return MACRO( T(LBRC), T(RBRC), T(LEFT), END);
			break;
		case 5:
			return MACRO_NONE;
			break;
		case 6:
			return MACRO_NONE;
			break;
		case 7:
			return MACRO_NONE;
			break;
		case 8:
			return MACRO_NONE;
			break;
		case 9:
			return MACRO_NONE;
			break;
	}
	return MACRO_NONE;
};

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				persistent_default_layer_set(1UL<<_QWERTY);
			}
			return false;
			break;
		case FN1:
			if (record->event.pressed) {
				layer_on(_FN1);
			} else {
				layer_off(_FN1);
			}
			return false;
			break;
		case NAV:
			if (record->event.pressed) {
				layer_on(_NAV);
			} else {
				layer_off(_NAV);
			}
			return false;
			break;
		case SYMBOL:
			if (record->event.pressed) {
				layer_on(_SYMBOL);
			} else {
				layer_off(_SYMBOL);
			}
			return false;
			break;
		case MACRO:
			if (record->event.pressed) {
				layer_on(_MACRO);
			} else {
				layer_off(_MACRO);
			}
			return false;
			break;
	}
	return true;
}
