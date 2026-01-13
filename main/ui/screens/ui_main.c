#include "ui.h"
#include "app.h"

static const char *TAG = "ui_main";

lv_obj_t *ui_Main;

static lv_obj_t *img_obj = NULL;
static lv_obj_t *img_title = NULL;
static lv_obj_t *img_set = NULL;
static lv_obj_t *img_wifi = NULL;
static lv_obj_t *img_wpoint1 = NULL;
static lv_obj_t *img_wpoint2 = NULL;

static lv_obj_t *cchess_btn = NULL;
static lv_obj_t *chess_btn = NULL;
static lv_obj_t *go_btn = NULL;
static lv_obj_t *gomoku_btn = NULL;

static lv_obj_t *ui_LabelMain;

static int icon_group_state = 0;

static void button_click_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch(code) {
        case LV_EVENT_GESTURE:
            // 处理手势事件
            {
                lv_indev_wait_release(lv_indev_get_act());
                lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
                if(dir == LV_DIR_LEFT) {
                    // 左滑处理
                    if(icon_group_state == 0) {
                        lv_obj_add_flag(cchess_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(chess_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(img_wpoint1, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(go_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(gomoku_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(img_wpoint2, LV_OBJ_FLAG_HIDDEN);
                        icon_group_state = 1;
                    }
                }
                else if(dir == LV_DIR_RIGHT) {
                    // 右滑处理
                    if(icon_group_state == 1) {
                        lv_obj_add_flag(go_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(gomoku_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(img_wpoint2, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(cchess_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(chess_btn, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(img_wpoint1, LV_OBJ_FLAG_HIDDEN);
                        icon_group_state = 0;
                    }
                }
            }
            break;

        case LV_EVENT_CLICKED:
            // 处理点击事件
            lv_obj_t * btn = lv_event_get_target(e);
            if(btn == img_set)
            {    
                _ui_screen_change(&ui_Menu, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Menu_screen_init);
            }else if(btn == cchess_btn){
                app.subsele = 0;
                _ui_screen_change(&ui_Subm, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Subm_screen_init);
            }else if(btn == chess_btn){
                app.subsele = 1;
                _ui_screen_change(&ui_Subm, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Subm_screen_init);
            }else if(btn == go_btn){
                app.subsele = 2;
                _ui_screen_change(&ui_Subm, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Subm_screen_init);
            }else if(btn == gomoku_btn){
                app.subsele = 3;
                _ui_screen_change(&ui_Subm, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                                      ui_Subm_screen_init);
            }
                
             
           
            break;
            
        default:
            break;
    }
}

static void event_unload_handler(lv_event_t *e)
{
    _ui_screen_delete(&ui_Main);
}

void ui_Main_screen_init(void)
{
    ui_Main = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Main, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Main, lv_color_hex(0x171726), 0);

    img_title = lv_img_create(ui_Main);
    lv_img_set_src(img_title, &title_image);
    lv_obj_align(img_title, LV_ALIGN_TOP_LEFT, 27, 0);

    ui_LabelMain = lv_label_create(ui_Main);
    lv_obj_align(ui_LabelMain, LV_ALIGN_TOP_LEFT, 112, 9);
    lv_obj_set_style_text_font(ui_LabelMain, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelMain, "机器人");
    lv_obj_set_style_text_color(ui_LabelMain, lv_color_hex(0xffffff), 0);

    img_set = lv_img_create(ui_Main);
    lv_img_set_src(img_set, &set_image);
    lv_obj_align(img_set, LV_ALIGN_TOP_LEFT, 292, 14);
    lv_obj_add_flag(img_set, LV_OBJ_FLAG_CLICKABLE); 
    lv_obj_add_event_cb(img_set, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_wifi = lv_img_create(ui_Main);
    lv_img_set_src(img_wifi, &wifi_image);
    lv_obj_align(img_wifi, LV_ALIGN_TOP_LEFT, 352, 19);

    cchess_btn = lv_btn_create(ui_Main);
    lv_obj_align(cchess_btn, LV_ALIGN_TOP_LEFT, 55, 92);
    lv_obj_set_size(cchess_btn, 150, 180);
    lv_obj_set_style_radius(cchess_btn, 25, LV_PART_MAIN);
    lv_obj_set_style_bg_color(cchess_btn, lv_color_hex(0xFF5C4D), LV_PART_MAIN);
    lv_obj_clear_flag(cchess_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_flag(cchess_btn, LV_OBJ_FLAG_GESTURE_BUBBLE);
   // lv_obj_add_event_cb(cchess_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_cchess = lv_img_create(cchess_btn);
    lv_img_set_src(img_cchess, &cchess_image);
    lv_obj_align(img_cchess, LV_ALIGN_CENTER, 0, 0);

    chess_btn = lv_btn_create(ui_Main);
    lv_obj_align(chess_btn, LV_ALIGN_TOP_LEFT, 280, 92);
    lv_obj_set_size(chess_btn, 150, 180);
    lv_obj_set_style_radius(chess_btn, 25, LV_PART_MAIN);
    lv_obj_set_style_bg_color(chess_btn, lv_color_hex(0xFF8C4A), LV_PART_MAIN);
    lv_obj_clear_flag(chess_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_flag(chess_btn, LV_OBJ_FLAG_GESTURE_BUBBLE);
   // lv_obj_add_event_cb(chess_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_chess = lv_img_create(chess_btn);
    lv_img_set_src(img_chess, &chess_image);
    lv_obj_align(img_chess, LV_ALIGN_CENTER, 0, 0);

    img_wpoint1 = lv_img_create(ui_Main);
    lv_img_set_src(img_wpoint1, &wpoint1_image);
    lv_obj_align(img_wpoint1, LV_ALIGN_TOP_LEFT, 225, 283);

    go_btn = lv_btn_create(ui_Main);
    lv_obj_align(go_btn, LV_ALIGN_TOP_LEFT, 55, 92);
    lv_obj_set_size(go_btn, 150, 180);
    lv_obj_set_style_radius(go_btn, 25, LV_PART_MAIN);
    lv_obj_set_style_bg_color(go_btn, lv_color_hex(0xFF9730), LV_PART_MAIN);
    lv_obj_clear_flag(go_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_flag(go_btn, LV_OBJ_FLAG_HIDDEN);  // 初始隐藏
    lv_obj_add_flag(go_btn, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_event_cb(go_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_go = lv_img_create(go_btn);
    lv_img_set_src(img_go, &go_image);
    lv_obj_align(img_go, LV_ALIGN_CENTER, 0, 0);

    gomoku_btn = lv_btn_create(ui_Main);
    lv_obj_align(gomoku_btn, LV_ALIGN_TOP_LEFT, 280, 92);
    lv_obj_set_size(gomoku_btn, 150, 180);
    lv_obj_set_style_radius(gomoku_btn, 25, LV_PART_MAIN);
    lv_obj_set_style_bg_color(gomoku_btn, lv_color_hex(0x2592FF), LV_PART_MAIN);
    lv_obj_clear_flag(gomoku_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_flag(gomoku_btn, LV_OBJ_FLAG_HIDDEN);  // 初始隐藏
    lv_obj_add_flag(gomoku_btn, LV_OBJ_FLAG_GESTURE_BUBBLE);  // 等价关闭 click_focus
    lv_obj_add_event_cb(gomoku_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *img_gomoku = lv_img_create(gomoku_btn);
    lv_img_set_src(img_gomoku, &gomoku_image);
    lv_obj_align(img_gomoku, LV_ALIGN_CENTER, 0, 0);
    
    img_wpoint2 = lv_img_create(ui_Main);
    lv_img_set_src(img_wpoint2, &wpoint2_image);
    lv_obj_align(img_wpoint2, LV_ALIGN_TOP_LEFT, 225, 283);
    lv_obj_add_flag(img_wpoint2, LV_OBJ_FLAG_HIDDEN);  // 初始隐藏

    lv_obj_add_event_cb(ui_Main, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);

    lv_obj_add_event_cb(ui_Main, button_click_handler, LV_EVENT_GESTURE, NULL);

}