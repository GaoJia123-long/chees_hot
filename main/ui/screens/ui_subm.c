#include "ui.h"
#include "app.h"

static const char *TAG = "ui_Subm";

lv_obj_t *ui_Subm;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;

//static lv_obj_t *nc_sc_btn = NULL;  //国际棋力
//static lv_obj_t *c_clash_btn = NULL; //国际巅峰


//static lv_obj_t *cc_sc_btn = NULL;  //中国棋力
//static lv_obj_t *cc_clash_btn = NULL; //中国巅峰

//static lv_obj_t *c_sc_btn = NULL;   //黑白棋力
//static lv_obj_t *clashofc_btn = NULL;  //黑白巅峰

static lv_obj_t *clashofc_btn = NULL;  //巅峰
static lv_obj_t *sc_btn = NULL;   //棋力

// 按钮点击事件处理函数
static void button_click_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch(code){
        case LV_EVENT_SHORT_CLICKED:
            if(lv_event_get_target(e) == img_home || lv_event_get_target(e) == img_leftarr) {
                _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Main_screen_init);
            }
            break;
            
        default:
            break;
    }
    
}

static void event_unload_handler(lv_event_t *e)
{
    _ui_screen_delete(&ui_Subm);
}

void ui_Subm_screen_init(void)
{
    ui_Subm = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Subm, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Subm, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Subm);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Subm);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE); 
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Subm);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE); 
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    sc_btn = lv_btn_create(ui_Subm);
    lv_obj_align(sc_btn, LV_ALIGN_TOP_LEFT, 54, 91);
    lv_obj_set_size(sc_btn, 150, 180);
    lv_obj_set_style_radius(sc_btn, 25, LV_PART_MAIN);
    lv_obj_clear_flag(sc_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    //lv_obj_add_event_cb(cchess_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_sc = lv_img_create(sc_btn);
    lv_obj_align(img_sc, LV_ALIGN_CENTER, 0, 0);

    clashofc_btn = lv_btn_create(ui_Subm);
    lv_obj_align(clashofc_btn, LV_ALIGN_TOP_LEFT, 280, 91);
    lv_obj_set_size(clashofc_btn, 150, 180);
    lv_obj_set_style_radius(clashofc_btn, 25, LV_PART_MAIN);
    lv_obj_clear_flag(clashofc_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    //lv_obj_add_event_cb(chess_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_clash = lv_img_create(clashofc_btn);
    lv_obj_align(img_clash, LV_ALIGN_CENTER, 0, 0);

    switch (app.subsele)
    {
    case 0:
        lv_label_set_text(ui_LabelMenu, "中国象棋");
        lv_obj_set_style_bg_color(sc_btn, lv_color_hex(0x359AFF), LV_PART_MAIN);
        lv_img_set_src(img_sc, &cc_sc_image);

        lv_obj_set_style_bg_color(clashofc_btn, lv_color_hex(0x9847FF), LV_PART_MAIN);
        lv_img_set_src(img_clash, &cc_clash_image);
        /* code */
        break;
    case 1:
        lv_label_set_text(ui_LabelMenu, "国际象棋");
        lv_obj_set_style_bg_color(sc_btn, lv_color_hex(0x22B152), LV_PART_MAIN);
        lv_img_set_src(img_sc, &nc_sc_image);

        lv_obj_set_style_bg_color(clashofc_btn, lv_color_hex(0x9847FF), LV_PART_MAIN);
        lv_img_set_src(img_clash, &c_clash_image);
        break;
    case 2:
        lv_label_set_text(ui_LabelMenu, "围棋");
        lv_obj_set_style_bg_color(sc_btn, lv_color_hex(0x22B152), LV_PART_MAIN);
        lv_img_set_src(img_sc, &nc_sc_image);

        lv_obj_set_style_bg_color(clashofc_btn, lv_color_hex(0x9847FF), LV_PART_MAIN);
        lv_img_set_src(img_clash, &c_clash_image);
        break;
    case 3:
        lv_label_set_text(ui_LabelMenu, "五子棋");
        lv_obj_set_style_bg_color(sc_btn, lv_color_hex(0x22B152), LV_PART_MAIN);
        lv_img_set_src(img_sc, &c_sc_image);

        lv_obj_set_style_bg_color(clashofc_btn, lv_color_hex(0x620DCD), LV_PART_MAIN);
        lv_img_set_src(img_clash, &clashofc_image);
        break;
    default:
        break;
    }

    lv_obj_add_event_cb(ui_Subm, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}