#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define _SYM 3
#define _MACRO 4

// for TT layer switch
#define TAPPING_TOGGLE 2

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	FN1,
	FN2,
	MACRO,
	SYM,
	WHAT_DID_YOU = SAFE_RANGE
};

#define WHAT_DID_YOU M(11)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------.  .-------------------------------------------.
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y   |   U   |   I  |   O  |   P  |  Esc |
 * |-------+------+------+------+------+------|  |-------+-------+------+------+------+------|
 * |  FN2  |   A  |   S  |   D  |  F   |   G  |  |   H   |   J   |   K  |   L  |    ; |   '  |
 * |-------+------+------+------+------+------|  |-------+------+-------+------+------+------|
 * |  SYM  |   Z  |   X  |   C  |   V  |   B  |  |   N   |   M   |   ,  |   .  |   /  | MACRO|
 * |-------+------+------+------+------+------|  |-------+-------+------+------+------+------|
 * |  Ctrl |  GUI |  Alt |  Del | Bspc | Shft |  | Enter |SpceFN1| Left | Down | Up   | Right|
 * `------------------------------------------'  '-------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
	KC_TAB,    KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,           KC_Y,    KC_U,              KC_I,     KC_O,     KC_P,     KC_ESC, \
	MO(_FN2),  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,           KC_H,    KC_J,              KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
	TT(_SYM),  KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,           KC_N,    KC_M,              KC_COMM,  KC_DOT,   KC_SLSH,  MO(_MACRO), \
	KC_LCTL,   KC_LGUI,  KC_LALT,  KC_DEL,  KC_BSPC,  KC_LSFT,        KC_ENT,  LT(_FN1, KC_SPC),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT \
),

/* FN1
 * ,-----------------------------------------.  .-------------------------------------------.
 * |  GRV |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |    0  |  END  |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |      |   !  |   @  |   #  |   $  |   %  |  |  ^   |  &   |   *  |   (  |   )   |       |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10  |  F11  |
 * |------+------+------+------+------+------|  |------+------+------+------+-------+-------|
 * |      |      |      |      |      |      |  |      |      |      |      |       |       |
 * `-----------------------------------------'  '-------------------------------------------'
 */
[_FN1] =  KEYMAP( \
	KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_END, \
	_______, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,        KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______, \
	KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, \
	_______, _______, _______, _______,  _______, _______,        _______,  _______,  _______,  _______,  _______,  _______ \
),

/* SYM
 * ,-----------------------------------------.  .-----------------------------------------.
 * |   /  |   7  |   8  |   9  |   -  |   (  |  |   )  |  _   |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   *  |   4  |   5  |   6  |   +  |   [  |  |   ]  |  =   |  C1  |  C2  |  C3  |  C4  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |      |   {  |  |   )  |      |      |      |      |  \   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  00  |   0  |   .  |      |ENTER |  |      |      |      |      |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_SYM] = KEYMAP( \
 KC_PAST,  KC_7,    KC_8,  KC_9,    KC_PMNS, KC_LPRN,        KC_RPRN,  KC_UNDS,  _______, _______,   _______,  _______, \
 KC_PSLS,  KC_4,    KC_5,  KC_6,    KC_PPLS, KC_LBRC,        KC_RBRC,  KC_EQL,   M(1),    M(2),      M(3),     M(4),    \
 _______,  KC_1,    KC_2,  KC_3,    _______, KC_LCBR,        KC_RCBR,  _______,  _______, _______,   _______,  _______, \
 _______,  M(0),    KC_0,  KC_DOT,  _______, KC_ENT,         _______,  _______,  _______, _______,   _______,  _______  \
),


/* FN2
 * ,-----------------------------------------.  .-----------------------------------------.
 * |      | Prev | Play | Next |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | Mute |VolDow| VolUp|      |      |  | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      | PgDn | PgUp |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_FN2] = KEYMAP( \
	_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,       _______, _______, _______, _______, _______, _______, \
	_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, KC_PGDN,  KC_PGUP, _______ \
),

/* MACRO
 * ,-----------------------------------------.  .-----------------------------------------.
 * |      |      |  W1  |  W2  |  W3  |      |  |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |  S1  |      |      |  G1  |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  G2  |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      | WHAT |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */
[_MACRO] =  KEYMAP( \
	_______, _______, M(5),    M(6),    M(7),    _______,       _______, _______, _______, _______, _______, RESET,   \
	_______, _______, M(8),    _______, _______, M(9),          _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, M(10),   _______, _______,       _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______,       _______, _______, _______, M(11),   _______, _______  \
)


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
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
			case 4:
				return MACRO( D(LSFT), T(LBRC), U(LSFT), D(LSFT), T(RBRC), U(LSFT), T(LEFT), END );
				break;
			case 3:
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
			case 10:
				return MACRO_NONE;
				break;
		}
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
		case FN2:
			if (record->event.pressed) {
				layer_on(_FN2);
			} else {
				layer_off(_FN2);
			}
			return false;
			break;
		case SYM:
			if (record->event.pressed) {
				layer_on(_SYM);
			} else {
				layer_off(_SYM);
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
		case WHAT_DID_YOU:
			if (record->event.pressed) {
				SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I’ll have you know I graduated top of my class in the Navy Seals, and I’ve been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I’m the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You’re fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that’s just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little “clever” comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn’t, you didn’t, and now you’re paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You’re fucking dead, kiddo.");
			}
			return false;
			break;
	}
	return true;
}
