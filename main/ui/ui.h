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

void ui_Username_screen_init(void);
extern lv_obj_t *ui_Username;

extern void ui_Userswitch_screen_init(void);
extern lv_obj_t *ui_Userswitch;

extern void ui_Menustrap_screen_init(void);
extern lv_obj_t *ui_Menustrap;

extern void ui_Netset_screen_init(void);
extern lv_obj_t *ui_Netset;

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
LV_IMG_DECLARE(uncheck);
LV_IMG_DECLARE(check);
LV_IMG_DECLARE(QR_code_image);
LV_IMG_DECLARE(link_image);
LV_IMG_DECLARE(lock_imaeg);
LV_IMG_DECLARE(white_image);
LV_IMG_DECLARE(wifi0_image);
LV_IMG_DECLARE(wifi1_image);
LV_IMG_DECLARE(wifi2_image);
LV_IMG_DECLARE(wifi3_image);

LV_FONT_DECLARE(MiSansBold_26);
LV_FONT_DECLARE(MiSansRegular_40);

void ui_init(void);