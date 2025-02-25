// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "sendstring_french.h"

enum layers {
    _COLEMAK_DH = 0,
    _COLEMAK_DH_MAC,
    _QWERTY_MAC,
    _NAV,
    _NAV_MAC,
    _SYM,
    _SYM_MAC,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define COLEMAK      DF(_COLEMAK_DH)
#define COLEMAK_MAC  DF(_COLEMAK_DH_MAC)
#define QWERTY_MAC   DF(_QWERTY_MAC)

#define SYM      MO(_SYM)
#define SYM_MAC  MO(_SYM_MAC)
#define NAV      MO(_NAV)
#define NAV_MAC  MO(_NAV_MAC)
#define FKEYS    OSL(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define SFT_LPRN MT(MOD_LSFT, FR_LPRN)
#define SFT_RPRN MT(MOD_RSFT, FR_RPRN)

#define ALT_DEL  MT(MOD_LALT, KC_DEL)
#define CTL_BSPC MT(MOD_LCTL, KC_BSPC)
#define SFT_ENT  MT(MOD_LSFT, KC_ENT)

#define ALT_ESC  MT(MOD_LALT, KC_ESC)
#define CTL_TAB  MT(MOD_RCTL, KC_TAB)
#define SFT_SPC  MT(MOD_RSFT, KC_SPC)

#define GUI_BSPC MT(MOD_LGUI, KC_BSPC)
#define GUI_TAB  MT(MOD_RGUI, KC_TAB)

#define UDO      LCTL(FR_Z)
#define CUT      LCTL(FR_X)
#define CPY      LCTL(FR_C)
#define PST      LCTL(FR_V)
#define RDO      LCTL(FR_Y)

#define UDO_MAC  LGUI(FR_Z)
#define CUT_MAC  LGUI(FR_X)
#define CPY_MAC  LGUI(FR_C)
#define PST_MAC  LGUI(FR_V)
#define RDO_MAC  LSFT(LGUI(FR_Z))

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                                |   J  |   L  |   U  |   Y  | '  " |  Bksp  |
 * |--------+------+------+------+------+------|                                |------+------+------+------+------+--------|
 * |LShift/(|   A  |   R  |   S  |   T  |   G  |                                |   M  |   N  |   E  |   I  |   O  |RShift/)|
 * |--------+------+------+------+------+------+--------------.  ,--------------+------+------+------+------+------+--------|
 * |  LCtl  |   Z  |   X  |   C  |   D  |   V  | [ {   |Adjust|  |F-keys|  ]  } |   K  |   H  | ,  < | . >  | /  ? |  RCtl  |
 * `----------------------+------+------+------+-------+------|  |------+-------+------+------+------+----------------------'
 *                        | LGUI | LAlt/| LCtl/|LShift/| Sym  |  | Nav  |RShift/| RCtl/| LAlt/| RGUI |
 *                        |      |  Del | Bksp |  Enter|      |  |      | Space |  Tab |  Esc |      |
 *                        `-----------------------------------'  `-----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , FR_Q ,  FR_W   ,  FR_F  ,   FR_P ,   FR_B ,                                        FR_J,   FR_L ,  FR_U ,   FR_Y ,FR_QUOT, KC_BSPC,
     SFT_LPRN, FR_A ,  FR_R   ,  FR_S  ,   FR_T ,   FR_G ,                                        FR_M,   FR_N ,  FR_E ,   FR_I ,  FR_O ,SFT_RPRN,
     KC_LCTL , FR_Z ,  FR_X   ,  FR_C  ,   FR_D ,   FR_V , FR_LBRC, ADJUST,     FKEYS  , FR_RBRC, FR_K,   FR_H ,FR_COMM, FR_DOT ,FR_SLSH, KC_RCTL,
                                KC_LGUI, ALT_DEL,CTL_BSPC, SFT_ENT, SYM   ,     NAV    , SFT_SPC, CTL_TAB, ALT_ESC, KC_RGUI,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Base Layer: Colemak DH MAC
 *
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                                |   J  |   L  |   U  |   Y  | '  " |  Bksp  |
 * |--------+------+------+------+------+------|                                |------+------+------+------+------+--------|
 * |LShift/(|   A  |   R  |   S  |   T  |   G  |                                |   M  |   N  |   E  |   I  |   O  |RShift/)|
 * |--------+------+------+------+------+------+--------------.  ,--------------+------+------+------+------+------+--------|
 * |  LGUI  |   Z  |   X  |   C  |   D  |   V  | [ {   |Adjust|  |F-keys|  ]  } |   K  |   H  | ,  < | . >  | /  ? |  RGUI  |
 * `----------------------+------+------+------+-------+------|  |------+-------+------+------+------+----------------------'
 *                        | LCtl | LAlt/| LGUI/|LShift/| Sym  |  | Nav  |RShift/| RGUI/| LAlt/| RCtl |
 *                        |      |  Del | Bksp |  Enter|      |  |      | Space |  Tab |  Esc |      |
 *                        `-----------------------------------'  `-----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_COLEMAK_DH_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , FR_Q ,  FR_W   ,  FR_F  ,   FR_P ,   FR_B ,                                        FR_J,   FR_L ,  FR_U ,   FR_Y ,FR_QUOT, KC_BSPC,
     SFT_LPRN, FR_A ,  FR_R   ,  FR_S  ,   FR_T ,   FR_G ,                                        FR_M,   FR_N ,  FR_E ,   FR_I ,  FR_O ,SFT_RPRN,
     KC_LGUI , FR_Z ,  FR_X   ,  FR_C  ,   FR_D ,   FR_V , FR_LBRC, ADJUST,     FKEYS  , FR_RBRC, FR_K,   FR_H ,FR_COMM, FR_DOT ,FR_SLSH, KC_RGUI,
                                KC_LCTL, ALT_DEL,GUI_BSPC, SFT_ENT, SYM   ,     NAV    , SFT_SPC, GUI_TAB, ALT_ESC, KC_RCTL,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Base Layer: QWERTY Mac
 *
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                                |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                                |------+------+------+------+------+--------|
 * |LShift/(|   A  |   S  |   D  |   F  |   G  |                                |   H  |   J  |   K  |   L  | ;  : |RShift/)|
 * |--------+------+------+------+------+------+--------------.  ,--------------+------+------+------+------+------+--------|
 * |  LGUI  |   Z  |   X  |   C  |   V  |   B  | [  {  |Adjust|  |F-keys|  ]  } |   N  |   M  | ,  < | . >  | /  ? |  RGUI  |
 * `----------------------+------+------+------+-------+------|  |------+-------+------+------+------+----------------------'
 *                        | LCtl | LAlt/| LGUI/|LShift/| Sym  |  | Nav  |RShift/| RGUI/| LAlt/| RCtl |
 *                        |      |  Del | Bksp |  Enter|      |  |      | Space |  Tab |  Esc |      |
 *                        `-----------------------------------'  `-----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_QWERTY_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , FR_Q ,  FR_W   ,  FR_E  ,   FR_R ,   FR_T ,                                        FR_Y,   FR_U ,  FR_I ,   FR_O ,  FR_P , KC_BSPC,
     SFT_LPRN, FR_A ,  FR_S   ,  FR_D  ,   FR_F ,   FR_G ,                                        FR_H,   FR_J ,  FR_K ,   FR_L ,FR_SCLN,SFT_RPRN,
     KC_LCTL , FR_Z ,  FR_X   ,  FR_C  ,   FR_V ,   FR_B , FR_LBRC, ADJUST,     FKEYS  , FR_RBRC, FR_N,   FR_M ,FR_COMM, FR_DOT ,FR_SLSH, KC_RGUI,
                                KC_LCTL, ALT_DEL,GUI_BSPC, SFT_ENT, SYM   ,     NAV    , SFT_SPC, GUI_TAB, ALT_ESC, KC_RCTL,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | PgUp | Home |   ↑  | End  | PrtSc|                              |      |BrwsBk|BrwsRf|BrwsFw| Calc |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | PgDn |  ←   |   ↓  |   →  |CapsLk|                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Undo |  Cut | Copy | Paste| Redo |NumLck|ScLck |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |LayLck|  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_PSCR,                                     _______, KC_WBAK, KC_WREF, KC_WFWD, KC_CALC, _______,
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,     UDO,     CUT,     CPY,     PST,     RDO,  KC_NUM, KC_SCRL, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,QK_LAYER_LOCK, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Nav Mac Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | PgUp | Home |   ↑  | End  | PrtSc|                              |      |BrwsBk|BrwsRf|BrwsFw| Calc |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | PgDn |  ←   |   ↓  |   →  |CapsLk|                              |      | Shift|  GUI |  Alt | Ctrl |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Undo |  Cut | Copy | Paste| Redo |NumLck|ScLck |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |LayLck|  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV_MAC] = LAYOUT_split_3x6_5_hlc(
      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_PSCR,                                     _______, KC_WBAK, KC_WREF, KC_WFWD, KC_CALC, _______,
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,                                     _______, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
      _______, UDO_MAC, CUT_MAC, CPY_MAC, PST_MAC, RDO_MAC,  KC_NUM, KC_SCRL, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,QK_LAYER_LOCK, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  -   |  _   |  *   |  &   |  €   |                              |   [  |  7   |  8   |  9   |  ]   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    {   |  ;   |  ^   |  %   |  $   |  +   |                              |   =  |  4   |  5   |  6   |  :   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ~  |  #   |  @   |  !   |  |   |      |      |  |      |      |   \  |  1   |  2   |  3   |  `   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |LayLck|  0   |   ,  |  .   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
      _______, FR_MINS, FR_UNDS, FR_ASTR, FR_AMPR, FR_EURO,                                     FR_LBRC,   FR_7 ,   FR_8 ,   FR_9 , FR_RBRC, _______,
     FR_LCBR , FR_SCLN, FR_CIRC, FR_PERC,  FR_DLR, FR_PLUS,                                      FR_EQL,   FR_4 ,   FR_5 ,   FR_6 , FR_COLN, FR_RCBR,
      _______, FR_TILD, FR_HASH,   FR_AT, FR_EXLM, FR_PIPE, _______, _______, _______, _______, FR_BSLS,   FR_1 ,   FR_2 ,   FR_3 , FR_GRV , _______,
                                 _______, _______, _______, _______, _______,QK_LAYER_LOCK,   FR_0 , FR_COMM, FR_DOT , _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Sym Mac Layer: Numbers and symbols for Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  -   |  _   |  *   |  &   |  €   |                              |   [  |  7   |  8   |  9   |  ]   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    {   |  ;   |  ^   |  %   |  $   |  +   |                              |   =  |  4   |  5   |  6   |  :   |   }    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ~  |  #   |  @   |  !   |  |   |      |      |  |      |      |   \  |  1   |  2   |  3   |  `   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |LayLck|  0   |   ,  |  .   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM_MAC] = LAYOUT_split_3x6_5_hlc(
      _______, FR_MINS, FR_UNDS, FR_ASTR, FR_AMPR, FR_EURO,                                     FR_LBRC,   FR_7 ,   FR_8 ,   FR_9 , FR_RBRC, _______,
     FR_LCBR , FR_SCLN, FR_CIRC, FR_PERC,  FR_DLR, FR_PLUS,                                      FR_EQL,   FR_4 ,   FR_5 ,   FR_6 , FR_COLN, FR_RCBR,
      _______, FR_TILD, FR_HASH,   FR_AT, FR_EXLM, FR_PIPE, _______, _______, _______, _______, FR_BSLS,   FR_1 ,   FR_2 ,   FR_3 , FR_GRV , _______,
                                 _______, _______, _______, _______, _______,QK_LAYER_LOCK,   FR_0 , FR_COMM, FR_DOT , _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  F7  |  F8  |  F9  |  F12 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F10 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |LayLck|  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUNCTION] = LAYOUT_split_3x6_5_hlc(
      _______, _______, _______, _______, _______, _______,                                     _______,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F12, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F11, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F10, _______,
                                 _______, _______, _______, _______,QK_LAYER_LOCK, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-----------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  Colemak |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+----------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Colmak Mac|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+----------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |QWERTY Mac|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+----------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |          |      |      |      |      |  |      |      |      |      |      |
 *                        |          |      |      |      |      |  |LayLck|      |      |      |      |
 *                        `--------------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
      _______, _______, _______,     COLEMAK, _______, _______,                                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, COLEMAK_MAC, _______, _______,                                    RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
      _______, _______, _______,  QWERTY_MAC, _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                     _______, _______, _______,_______, _______,QK_LAYER_LOCK, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
};

//////////////
// Encoders
//////////////
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [3] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [4] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [5] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [6] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [7] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_UP, KC_DOWN),  ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [8] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(RM_VALD, RM_VALU),  ENCODER_CCW_CW(RM_VALD, RM_VALU) },
};
#endif

//////////////////
// Macros
//////////////////
enum custom_keycodes {
    C_CED_MAJ = SAFE_RANGE,
    E_ACU_MAJ,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case C_CED_MAJ:
        if (record->event.pressed) {
            // when keycode C_CED_MAJ is pressed
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P8) SS_UP(X_LALT));
        } else {
            // when keycode C_CED_MAJ is released
        }
        break;
    case E_ACU_MAJ:
        if (record->event.pressed) {
            // when keycode E_ACU_MAJ is pressed
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P4) SS_UP(X_LALT));
        } else {
            // when keycode E_ACU_MAJ is released
        }
        break;
    }
    return true;
};

//////////////////
// Combos
//////////////////
const uint16_t PROGMEM a_grave_combo[] = {FR_A, FR_R, COMBO_END};
const uint16_t PROGMEM e_acute_combo[] = {FR_N, FR_E, COMBO_END};
const uint16_t PROGMEM e_acute_maj_combo[] = {FR_H ,FR_COMM, FR_DOT, COMBO_END};
const uint16_t PROGMEM e_grave_combo[] = {FR_E, FR_I, COMBO_END};
const uint16_t PROGMEM u_grave_combo[] = {FR_U, FR_Y, COMBO_END};
const uint16_t PROGMEM c_cedilla_combo[] = {FR_C, FR_D, COMBO_END};
const uint16_t PROGMEM c_cedilla_maj_combo[] = {FR_X, FR_C, FR_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(a_grave_combo, FR_AGRV),
    COMBO(e_acute_combo, FR_EACU),
    COMBO(e_acute_maj_combo, E_ACU_MAJ),
    COMBO(e_grave_combo, FR_EGRV),
    COMBO(u_grave_combo, FR_UGRV),
    COMBO(c_cedilla_combo, FR_CCED),
    COMBO(c_cedilla_maj_combo, C_CED_MAJ),
};

//////////////////
// Key overrides
//////////////////
const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_LABK);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_RABK);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_SLSH, FR_QUES);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&comm_key_override,
	&dot_key_override,
	&quot_key_override,
    &slash_key_override,
};

////////////////
// Quick tap
////////////////
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPC:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
