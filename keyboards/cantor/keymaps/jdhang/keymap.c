// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

/* Layer defines (for readability) */
#define _BASE 0
#define _COLE 1
#define _SYM 2
#define _NAV 3
#define _NUM 4

enum custom_keycodes {
    /* Mod defines */
    // M_ARROW_REQL = SAFE_RANGE, /* => */
    M_LLOCK = SAFE_RANGE,
    M_EQ_GT, /* => */
    M_EQ3X,  /* === */
    M_UPDIR, /* ../ */
    M_LPRN_LT,
    M_RPRN_GT,
    M_MINS_UNDS,
    M_BSLS_SLSH,
    M_SLSH_BSLS,

    /* Tap dance defines */
    TD_EQL_REQL = 0,
    TD_GUI_CTL  = 1,
    TD_C_COPY   = 2,
    TD_V_PASTE  = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │ESC│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Gui├───┐           ┌───┤Ctl│
     *               └───┤Bsp├───┐   ┌───┤Sft├───┘
     *                   └───┤   │   │Ent├───┘
     *                       └───┘   └───┘
     */
    [_BASE] = LAYOUT_split_3x6_3(
        //-------------------------------------------------------------------------------      ----------------------------------------------------------------------------------
        KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_NO,
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        KC_ESC, LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LSFT_T(KC_SLSH), KC_NO,
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        OSM(MOD_LGUI), LT(_NUM, KC_BSPC), LT(_SYM, KC_SPC), LT(_NAV, KC_ENT), LSFT_T(KC_ESC), OSM(MOD_LCTL)
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ - │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │ESC│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │GUI├───┐           ┌───┤   │
     *               └───┤Bsp├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │Ent├───┘
     *                       └───┘   └───┘
     */
    [_COLE] = LAYOUT_split_3x6_3(
        //-------------------------------------------------------------------------------      ----------------------------------------------------------------------------------
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, TO(_BASE),
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        TD(TD_GUI_CTL), LT(_NUM, KC_BSPC), LT(_SYM, KC_SPC), LT(_NAV, KC_ENT), QK_AREP, KC_NO
        //-------------------------------------------------------------------------------      ---------------------------------------------------------------------------------
        ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │   │ @ │ # │ ` │ % │       │ & │ [ │ ] │ * │ - │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ! │ @ │ ^ │ = │=> │       │ | │ ( │ ) │ : │ ' │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ? │   │ $ │ ~ │ _ │       │ - │ { │ } │ * │ \ │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤Ctl│
     *               └───┤Alt├───┐   ┌───┤Sft├───┘
     *                   └───┤   │   │Gui├───┘
     *                       └───┘   └───┘
     */
    [_SYM] = LAYOUT_split_3x6_3(
        //-------------------------------------------------------------------        ---------------------------------------------------------------------------------
        KC_NO, KC_GRV, KC_LBRC, KC_LCBR, M_LPRN_LT, KC_PERC, KC_AMPR, M_RPRN_GT, KC_RCBR, KC_RBRC, KC_NO, KC_NO,
        //-------------------------------------------------------------------        ---------------------------------------------------------------------------------
        KC_NO, KC_EXLM, KC_QUES, KC_CIRC, KC_EQL, KC_SCLN, KC_PIPE, KC_COLN, KC_NO, KC_NO, KC_SCLN, KC_NO,
        //-------------------------------------------------------------------        ---------------------------------------------------------------------------------
        KC_NO, KC_NO, KC_AT, KC_DLR, M_EQ_GT, KC_UNDS, M_MINS_UNDS, KC_ASTR, M_SLSH_BSLS, KC_NO, KC_NO, KC_NO,
        //--------------------------------------------------------------------       ---------------------------------------------------------------------------------
        KC_NO, KC_LALT, KC_NO, KC_LGUI, KC_LSFT, KC_LCTL
        //-------------------------------------------------------------------        ---------------------------------------------------------------------------------
        ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │Tab│   │CHm│CEd│   │       │G[ │G] │CST│CT │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │Ctl│Alt│Gui│Sft│Tab│       │ L │ D │ U │ R │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │Hom│End│PDn│PUp│       │   │   │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Ctl├───┐           ┌───┤   │
     *               └───┤Del├───┐   ┌───┤   ├───┘
     *                   └───┤Tab│   │   ├───┘
     *                       └───┘   └───┘
     */
    [_NAV] = LAYOUT_split_3x6_3(
        //------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, G(KC_LBRC), G(KC_RBRC), C(S(KC_TAB)), C(KC_TAB), KC_NO, KC_UNDS, KC_RCBR, KC_LCBR, KC_DLR, KC_NO, KC_NO,
        //------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_PERC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,
        //------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, KC_PGDN, KC_PGUP, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_LCTL, KC_DEL, MT(MOD_LCTL, KC_TAB), KC_NO, KC_NO, KC_NO
        //------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │ % │       │ * │ 7 │ 8 │ 9 │ + │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │Ctl│Gui│Sft│Alt│       │ , │ 4 │ 5 │ 6 │ - │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │TO3│   │   │   │   │       │ . │ 1 │ 2 │ 3 │ / │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤ 0 │
     *               └───┤   ├───┐   ┌───┤ 0 ├───┘
     *                   └───┤   │   │Ent├───┘
     *                       └───┘   └───┘
     */
    [_NUM] = LAYOUT_split_3x6_3(
        //-------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PERC, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_NO,
        //-------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_NO, KC_SLSH, KC_4, KC_5, KC_6, KC_MINS, KC_NO,
        //-------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, TO(_BASE), KC_NO, KC_NO, KC_NO, KC_COMM, KC_DOT, KC_1, KC_2, KC_3, KC_NO, KC_NO,
        //-------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, KC_NO, KC_NO, KC_ENT, KC_0, KC_0
        //-------------------------------------------------------------------         ---------------------------------------------------------------------------------
        )};

/* Tap dance function definitions */
void dance_c_copy(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("c");
            break;
        case 2:
            SEND_STRING(SS_LGUI("c"));
            break;
    }
}
void dance_v_paste(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("v");
            break;
        case 2:
            SEND_STRING(SS_LGUI("v"));
            break;
    }
}
void dance_eql_arrow(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("=");
            break;
        case 2:
            SEND_STRING("=>");
            break;
    }
}

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // tap: =, double-tap: =>
    [TD_EQL_REQL] = ACTION_TAP_DANCE_FN(dance_eql_arrow),
    [TD_GUI_CTL]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LCTL),
    [TD_C_COPY]   = ACTION_TAP_DANCE_FN(dance_c_copy),
    [TD_V_PASTE]  = ACTION_TAP_DANCE_FN(dance_v_paste),
};

/* Macro definitions */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, M_LLOCK)) {
        return false;
    }
    // Your macros ...
    switch (keycode) {
        case M_EQ_GT:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;

        case M_EQ3X:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            return false;

        case M_UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case M_LPRN_LT:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    SEND_STRING("<");
                } else {
                    SEND_STRING("(");
                }
            }
            return false;

        case M_RPRN_GT:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    SEND_STRING(">");
                } else {
                    SEND_STRING(")");
                }
            }
            return false;

        case M_MINS_UNDS:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    SEND_STRING("_");
                } else {
                    SEND_STRING("-");
                }
            }
            return false;

        case M_BSLS_SLSH:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    SEND_STRING("/");
                } else {
                    SEND_STRING("\\");
                }
            }
            return false;

        case M_SLSH_BSLS:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    SEND_STRING("\\");
                } else {
                    SEND_STRING("/");
                }
            }
            return false;
    }

    return true;
}
