#pragma once

#include "ui.h"

void _ui_screen_change(lv_obj_t **target, lv_scr_load_anim_t fademode, int spd,
                       int delay, void (*target_init)(void));
                       
void _ui_screen_delete(lv_obj_t **target);