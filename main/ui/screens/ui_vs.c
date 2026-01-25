#include "ui.h"
#include "app.h"

static const char *TAG = "ui_vs";

lv_obj_t *ui_VS;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_yellow = NULL;
static lv_obj_t *img_blue = NULL;
static lv_obj_t *img_white = NULL;
static lv_obj_t *img_black = NULL;
static lv_obj_t *img_vs = NULL;
static lv_obj_t *img_sun = NULL;
static lv_obj_t *img_remorse = NULL;
static lv_obj_t *img_stop = NULL;
static lv_obj_t *img_count = NULL;
static lv_obj_t *img_backdown = NULL;
static lv_obj_t *img_pa = NULL;

static lv_obj_t *white_btn = NULL;
static lv_obj_t *white_btn2 = NULL;
static lv_obj_t *white_btn3 = NULL;
static lv_obj_t *white_btn4 = NULL;
static lv_obj_t *white_btn5 = NULL;
static lv_obj_t *white_btn6 = NULL;

static void update_button_colors(lv_obj_t *selected_btn)
{
    // 将所有按钮设置为未选中状态（0xffffff，透明度41）
    lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn2, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn3, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn4, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(white_btn5, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn5, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(white_btn6, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn6, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);

    // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    if (selected_btn == white_btn)
    {
        _ui_screen_change(&ui_Volume, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_Volume_screen_init);
    }
    else if (selected_btn == white_btn2)
    {
        _ui_screen_change(&ui_Lights, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_Lights_screen_init);
    }
    else if (selected_btn == white_btn3)
    {
        _ui_screen_change(&ui_Language, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_Language_screen_init);
    }
    else if (selected_btn == white_btn4)
    {
        _ui_screen_change(&ui_About, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_About_screen_init);
    }
    else if (selected_btn == white_btn5)
    {
        _ui_screen_change(&ui_Test_newversion, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_Test_newversion_screen_init);
    }
    else if (selected_btn == white_btn6)
    {
        _ui_screen_change(&ui_Factory, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                          ui_Factory_screen_init);
    }
}

// 按钮点击事件处理函数
static void button_click_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SHORT_CLICKED:
        if (lv_event_get_target(e) == img_home || lv_event_get_target(e) == img_leftarr)
        {
            _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                              ui_Main_screen_init);
        }
        break;

    case LV_EVENT_CLICKED:
        lv_obj_t *btn = lv_event_get_target(e);
        update_button_colors(btn);
        break;

    default:
        break;
    }
}

static void event_unload_handler(lv_event_t *e)
{
    _ui_screen_delete(&ui_VS);
}

void ui_VS_screen_init(void)
{
    ui_VS = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_VS, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_VS, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 23);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelMenu, "围棋");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    lv_obj_t *ui_LabelGrade = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelGrade, LV_ALIGN_TOP_MID, 0, 77);
    lv_obj_set_style_text_font(ui_LabelGrade, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelGrade, "18级");
    lv_obj_set_style_text_color(ui_LabelGrade, lv_color_hex(0xFFAA00), 0);

    img_home = lv_img_create(ui_VS);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_VS);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_yellow = lv_img_create(ui_VS);
    lv_img_set_src(img_yellow, &yellow_image);
    lv_obj_align(img_yellow, LV_ALIGN_TOP_LEFT, 9, 67);
    lv_obj_add_flag(img_yellow, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_yellow, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_blue = lv_img_create(ui_VS);
    lv_img_set_src(img_blue, &blue_image);
    lv_obj_align(img_blue, LV_ALIGN_TOP_LEFT, 266, 67);
    lv_obj_add_flag(img_blue, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_blue, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_vs = lv_img_create(ui_VS);
    lv_img_set_src(img_vs, &vs_image);
    lv_obj_align(img_vs, LV_ALIGN_TOP_LEFT, 182, 130);
    lv_obj_add_flag(img_vs, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_vs, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_white = lv_img_create(ui_VS);
    lv_img_set_src(img_white, &checkerwhite_image);
    lv_obj_align(img_white, LV_ALIGN_TOP_LEFT, 120, 124);
    lv_obj_add_flag(img_white, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_white, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_black = lv_img_create(ui_VS);
    lv_img_set_src(img_black, &checkerblack_image);
    lv_obj_align(img_black, LV_ALIGN_TOP_LEFT, 322, 124);
    lv_obj_add_flag(img_black, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_black, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn, 32, 259);
    lv_obj_set_size(white_btn, 40, 40);
    lv_obj_set_style_radius(white_btn, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn, LV_OPA_0, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_sun = lv_img_create(white_btn);
    lv_img_set_src(img_sun, &sun_image);
    lv_obj_align(img_sun, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_sun, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_sun, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn2 = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn2, 78, 256);
    lv_obj_set_size(white_btn2, 69, 48);
    lv_obj_set_style_radius(white_btn2, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn2, LV_OPA_0, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(white_btn2, LV_OBJ_FLAG_SCROLLABLE);       /// Flags
    lv_obj_add_event_cb(white_btn2, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_remorse = lv_img_create(white_btn2);
    lv_img_set_src(img_remorse, &remorse_image);
    lv_obj_align(img_remorse, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_remorse, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_remorse, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn3 = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn3, 157, 256);
    lv_obj_set_size(white_btn3, 85, 46);
    lv_obj_set_style_radius(white_btn3, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn3, LV_OPA_0, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(white_btn3, LV_OBJ_FLAG_SCROLLABLE);       /// Flags
    lv_obj_add_event_cb(white_btn3, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_stop = lv_img_create(white_btn3);
    lv_img_set_src(img_stop, &stop_image);
    lv_obj_align(img_stop, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_stop, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_stop, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn4 = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn4, 252, 256);
    lv_obj_set_size(white_btn4, 69, 46);
    lv_obj_set_style_radius(white_btn4, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn4, LV_OPA_0, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(white_btn4, LV_OBJ_FLAG_SCROLLABLE);       /// Flags
    lv_obj_add_event_cb(white_btn4, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_count = lv_img_create(white_btn4);
    lv_img_set_src(img_count, &count_image);
    lv_obj_align(img_count, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_count, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_count, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn5 = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn5, 332, 256);
    lv_obj_set_size(white_btn5, 69, 46);
    lv_obj_set_style_radius(white_btn5, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn5, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn5, LV_OPA_0, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(white_btn5, LV_OBJ_FLAG_SCROLLABLE);       /// Flags
    lv_obj_add_event_cb(white_btn5, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_backdown = lv_img_create(white_btn5);
    lv_img_set_src(img_backdown, &backdown_image);
    lv_obj_align(img_backdown, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_backdown, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_backdown, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn6 = lv_btn_create(ui_VS);
    lv_obj_set_pos(white_btn6, 407, 259);
    lv_obj_set_size(white_btn6, 40, 40);
    lv_obj_set_style_radius(white_btn6, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn6, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn6, LV_OPA_0, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(white_btn6, LV_OBJ_FLAG_SCROLLABLE);       /// Flags
    lv_obj_add_event_cb(white_btn6, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_pa = lv_img_create(white_btn6);
    lv_img_set_src(img_pa, &pa_image);
    lv_obj_align(img_pa, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(img_pa, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_pa, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton1 = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelButton1, LV_ALIGN_TOP_LEFT, 69, 133);
    lv_obj_set_style_text_font(ui_LabelButton1, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton1, "小联");
    lv_obj_set_style_text_color(ui_LabelButton1, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton2 = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelButton2, LV_ALIGN_TOP_LEFT, 50, 173);
    lv_obj_set_style_text_font(ui_LabelButton2, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton2, "00:28:08");
    lv_obj_set_style_text_color(ui_LabelButton2, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton3 = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelButton3, LV_ALIGN_TOP_LEFT, 368, 133);
    lv_obj_set_style_text_font(ui_LabelButton3, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton3, "棋手");
    lv_obj_set_style_text_color(ui_LabelButton3, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton4 = lv_label_create(ui_VS);
    // lv_label_
    lv_obj_align(ui_LabelButton4, LV_ALIGN_TOP_LEFT, 314, 173);
    lv_obj_set_style_text_font(ui_LabelButton4, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton4, "00:28:08");
    lv_obj_set_style_text_color(ui_LabelButton4, lv_color_hex(0xFFFFFF), 0);

    lv_obj_add_event_cb(ui_VS, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}