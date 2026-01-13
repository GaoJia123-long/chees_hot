#pragma once

#include "lv_port.h"
#include "esp_log.h"
#include "ui_helpers.h"
#include "lvgl.h"

void ui_Main_screen_init(void);
extern lv_obj_t *ui_Main;

void ui_Menu_screen_init(void);
extern lv_obj_t *ui_Menu;

void ui_Subm_screen_init(void);
extern lv_obj_t *ui_Subm;

LV_IMG_DECLARE(demo);
LV_IMG_DECLARE(no_visiondemo);
LV_IMG_DECLARE(set_image);
LV_IMG_DECLARE(title_image);
LV_IMG_DECLARE(clashofc_image);
LV_IMG_DECLARE(go_image);
LV_IMG_DECLARE(gomoku_image);
LV_IMG_DECLARE(graybg_image);
LV_IMG_DECLARE(home_image);
LV_IMG_DECLARE(lcbg_image);
LV_IMG_DECLARE(leftarr_image);
LV_IMG_DECLARE(c_sc_image);
LV_IMG_DECLARE(cc_sc_image);
LV_IMG_DECLARE(cchess_image);
LV_IMG_DECLARE(chess_image);
LV_IMG_DECLARE(wifi_image);
LV_IMG_DECLARE(wpoint1_image);
LV_IMG_DECLARE(wpoint2_image);
LV_IMG_DECLARE(c_clash_image);
LV_IMG_DECLARE(cc_clash_image);
LV_IMG_DECLARE(nc_sc_image);

LV_FONT_DECLARE(MiSansBold_26);
LV_FONT_DECLARE(MiSansRegular_40);

void ui_init(void);