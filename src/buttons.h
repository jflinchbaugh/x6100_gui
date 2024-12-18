/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2022-2023 Belousov Oleg aka R1CBU
 */

#pragma once

#include "lvgl/lvgl.h"

typedef enum {
    PAGE_VOL_1 = 0,
    PAGE_VOL_2,
    PAGE_VOL_3,
    PAGE_VOL_4,

    PAGE_MFK_1,
    PAGE_MFK_2,
    PAGE_MFK_3,
    PAGE_MFK_4,

    PAGE_MEM_1,
    PAGE_MEM_2,

    PAGE_KEY_1,
    PAGE_KEY_2,

    PAGE_CW_DECODER_1,
    PAGE_CW_DECODER_2,

    PAGE_DFN_1,
    PAGE_DFN_2,
    PAGE_DFN_3,

    PAGE_APP_1,
    PAGE_APP_2,
    PAGE_APP_3,

    PAGE_RTTY,
    PAGE_SETTINGS,
    PAGE_SWRSCAN,
    PAGE_FT8,
    PAGE_GPS,
    PAGE_MSG_CW_1,
    PAGE_MSG_CW_2,
    PAGE_MSG_VOICE_1,
    PAGE_MSG_VOICE_2,
    PAGE_RECORDER,
    PAGE_WIFI,
} button_page_t;

typedef enum {
    GROUP_GEN,
    GROUP_APP,
    GROUP_KEY,
    GROUP_MSG_CW,
    GROUP_MSG_VOICE,
    GROUP_DFN

} button_group_t;

typedef enum {
    LABEL_TEXT,
    LABEL_FN,

} label_type_t;

typedef void (*hold_cb_t)(void *);

typedef char * (*label_cb_fn)();

typedef struct {
    union {
        char        *label;
        label_cb_fn label_fn;
    };
    label_type_t    label_type;
    char            *voice;
    lv_event_cb_t   press;
    hold_cb_t       hold;
    uint16_t        data;
    uint16_t        next;
    uint16_t        prev;
} button_item_t;

void buttons_init(lv_obj_t *parent);
lv_obj_t * buttons_load(uint8_t n, button_item_t *item);
void buttons_load_page(button_page_t page);
void buttons_unload_page();
void buttons_press(uint8_t n, bool hold);
void buttons_load_page_group(button_group_t group);
