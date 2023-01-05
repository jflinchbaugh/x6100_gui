/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <aether_radio/x6100_control/control.h>

typedef struct {
    uint8_t         vfo;
    
    uint64_t        vfoa_freq;
    x6100_att_t     vfoa_att;
    x6100_pre_t     vfoa_pre;
    x6100_mode_t    vfoa_mode;
    x6100_agc_t     vfoa_agc;

    uint64_t        vfob_freq;
    x6100_att_t     vfob_att;
    x6100_pre_t     vfob_pre;
    x6100_mode_t    vfob_mode;
    x6100_agc_t     vfob_agc;

    int16_t         grid_min;
    int16_t         grid_max;

    /* durty flags */
    
    struct {
        bool    vfo;
    
        bool    vfoa_freq;
        bool    vfoa_att;
        bool    vfoa_pre;
        bool    vfoa_mode;
        bool    vfoa_agc;

        bool    vfob_freq;
        bool    vfob_att;
        bool    vfob_pre;
        bool    vfob_mode;
        bool    vfob_agc;

        bool    grid_min;
        bool    grid_max;
    } durty;
} params_band_t;

typedef struct {
    /* radio */
    
    uint8_t     band;
    int16_t     vol;
    int16_t     rfg;
    int16_t     pre;
    
    /* main screen */
    
    int16_t     spectrum_factor;
    int16_t     spectrum_beta;
    uint16_t    freq_step;
    
    /* durty flags */
    
    struct {
        bool    band;
        bool    vol;
        bool    rfg;
        bool    pre;
        
        bool    spectrum_factor;
        bool    spectrum_beta;
        bool    freq_step;
    } durty;
} params_t;

extern params_t params;
extern params_band_t params_band;

void params_init();
void params_lock();
void params_unlock(bool *durty);

bool params_band_save();
void params_band_load();