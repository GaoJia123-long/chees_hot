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

extern void ui_Netpassword_screen_init(void);
extern lv_obj_t *ui_Netpassword;

extern void ui_Defaults_screen_init(void);
extern lv_obj_t *ui_Defaults;

extern void ui_Volume_screen_init(void);
extern lv_obj_t *ui_Volume;

extern void ui_Lights_screen_init(void);
extern lv_obj_t *ui_Lights;

extern void ui_Factory_screen_init(void);
extern lv_obj_t *ui_Factory;

extern void ui_Test_newversion_screen_init(void);
extern lv_obj_t *ui_Test_newversion;

extern void ui_Updateing_screen_init(void);
extern lv_obj_t *ui_Updateing;

extern void ui_Updateok_screen_init(void);
extern lv_obj_t *ui_Updateok;

extern void ui_Newversion_screen_init(void);
extern lv_obj_t *ui_Newversion;

extern void ui_About_screen_init(void);
extern lv_obj_t *ui_About;

extern void ui_Language_screen_init(void);
extern lv_obj_t *ui_Language;

extern void ui_Tating_screen_init(void);
extern lv_obj_t *ui_Tating;

extern void ui_Weiqitating_screen_init(void);
extern lv_obj_t *ui_Weiqitating;

extern void ui_VS_screen_init(void);
extern lv_obj_t *ui_VS;

extern void ui_Unhappy_screen_init(void);
extern lv_obj_t *ui_Unhappy;

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
LV_IMG_DECLARE(closeeye_image);
LV_IMG_DECLARE(openeye_image);
LV_IMG_DECLARE(closeeye_image);
LV_IMG_DECLARE(lights);
LV_IMG_DECLARE(slide_image);
LV_IMG_DECLARE(volum_image);
LV_IMG_DECLARE(notice_image);
LV_IMG_DECLARE(updateing_image);
LV_IMG_DECLARE(updateok_image);
LV_IMG_DECLARE(ratingyellow_image);
LV_IMG_DECLARE(ratingblack_image);
LV_IMG_DECLARE(sun_image);
LV_IMG_DECLARE(vs_image);
LV_IMG_DECLARE(yellow_image);
LV_IMG_DECLARE(but85X46);
LV_IMG_DECLARE(checkerblack_image);
LV_IMG_DECLARE(checkerwhite_image);
LV_IMG_DECLARE(pa_image);
LV_IMG_DECLARE(blue_image);
LV_IMG_DECLARE(but70X46);
LV_IMG_DECLARE(remorse_image);
LV_IMG_DECLARE(stop_image);
LV_IMG_DECLARE(backdown_image);
LV_IMG_DECLARE(count_image);
LV_IMG_DECLARE(unhappy_image);
LV_IMG_DECLARE(redcchess_image);
LV_IMG_DECLARE(whitecchess_image);
LV_IMG_DECLARE(whitechess_image);
LV_IMG_DECLARE(blackchess_image);

LV_FONT_DECLARE(MiSansBold_26);
LV_FONT_DECLARE(MiSansRegular_40);

void ui_init(void);