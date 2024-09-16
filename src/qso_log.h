/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2024 Georgy Dyuldin aka R2RFE
 */

#pragma once

#include <time.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char local_call[32];
    char remote_call[32];
    time_t time;
    char mode[8];
    int rsts;
    int rstr;
    float freq_mhz;
    char band[8];
    char name[64];
    char qth[64];
    char local_grid[8];
    char remote_grid[8];
} qso_log_record_t;


typedef enum {
    SEARCH_WORKED_NO,
    SEARCH_WORKED_YES,
    SEARCH_WORKED_SAME_MODE,
} qso_log_search_worked_t;


bool qso_log_init();

int qso_log_record_save(qso_log_record_t qso);

void qso_log_import_adif(const char *path);

/**
 * Create qso log recort struct.
 * Required params: `local_call`, `remote_call`, qso_time`, `mode`, `rsts`, `rstr`,  and `freq_mhz`
 */
qso_log_record_t qso_log_record_create(const char *local_call, const char *remote_call,
                                       time_t qso_time, const char *mode, int rsts, int rstr, float freq_mhz,
                                       const char *band, const char *name, const char *qth,
                                       const char *local_grid, const char *remote_grid);

/**
 * Search callsign in log.
 */
qso_log_search_worked_t qso_log_search_worked(const char *callsign, const char * mode, const char * band);