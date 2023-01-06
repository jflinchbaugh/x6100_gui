/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 */

#pragma once

#include <stdint.h>
#include "lvgl/lvgl.h"

lv_obj_t * info_init(lv_obj_t * parent);
void info_params_set();