#include "ui.h"
#include "app.h"

static const char *TAG = "ui_tating";

lv_obj_t *ui_Tating;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_yellow1 = NULL;
static lv_obj_t *img_yellow2 = NULL;
static lv_obj_t *img_yellow3 = NULL;
static lv_obj_t *img_black = NULL;

static lv_obj_t *white_btn = NULL;
static lv_obj_t *white_btn2 = NULL;
static lv_obj_t *white_btn3 = NULL;
static lv_obj_t *white_btn4 = NULL;

static void update_button_colors(lv_obj_t *selected_btn)
{
    // // 将所有按钮设置为未选中状态（0xffffff，透明度41）
    // lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn2, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn3, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn4, 41, LV_PART_MAIN);

    // // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    // if (selected_btn != NULL)
    // {
    //     lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    //     lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);
    // }
}

// 按钮点击事件处理函数
static void button_click_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SHORT_CLICKED:
        if (lv_event_get_target(e) == img_home)
        {
            _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                              ui_Main_screen_init);
        }
        else if (lv_event_get_target(e) == img_leftarr)
        {
            _ui_screen_change(&ui_Menu, LV_SCR_LOAD_ANIM_NONE, 0, 0,
                              ui_Menu_screen_init);
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
    _ui_screen_delete(&ui_Tating);
}

void ui_Tating_screen_init(void)
{
    ui_Tating = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Tating, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Tating, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Tating);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "棋力闯关");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Tating);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Tating);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_yellow1 = lv_img_create(ui_Tating);
    lv_img_set_src(img_yellow1, &ratingyellow_image);
    lv_obj_align(img_yellow1, LV_ALIGN_TOP_LEFT, 15, 113);
    lv_obj_add_flag(img_yellow1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_yellow1, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn = lv_btn_create(ui_Tating);
    lv_obj_set_pos(white_btn, 15, 113);
    lv_obj_set_size(white_btn, 105, 142);
    lv_obj_set_style_radius(white_btn, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn, 0, LV_PART_MAIN);  // 41是透明度为16%
    lv_obj_clear_flag(white_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton11 = lv_label_create(white_btn);
    // lv_label_
    lv_obj_align(ui_LabelButton11, LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_set_style_text_font(ui_LabelButton11, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelButton11, "新");
    lv_obj_set_style_text_color(ui_LabelButton11, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton12 = lv_label_create(white_btn);
    // lv_label_
    lv_obj_align(ui_LabelButton12, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_set_style_text_font(ui_LabelButton12, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton12, "新手");
    lv_obj_set_style_text_color(ui_LabelButton12, lv_color_hex(0xFF9E00), 0);

    img_yellow2 = lv_img_create(ui_Tating);
    lv_img_set_src(img_yellow2, &ratingyellow_image);
    lv_obj_align(img_yellow2, LV_ALIGN_TOP_LEFT, 130, 113);
    lv_obj_add_flag(img_yellow2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_yellow2, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn2 = lv_btn_create(ui_Tating);
    lv_obj_set_pos(white_btn2, 130, 113);
    lv_obj_set_size(white_btn2, 105, 142);
    lv_obj_set_style_radius(white_btn2, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn2, 0, LV_PART_MAIN);  // 41是透明度为16%
    lv_obj_clear_flag(white_btn2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn2, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton21 = lv_label_create(white_btn2);
    // lv_label_
    lv_obj_align(ui_LabelButton21, LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_set_style_text_font(ui_LabelButton21, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelButton21, "20");
    lv_obj_set_style_text_color(ui_LabelButton21, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton22 = lv_label_create(white_btn2);
    // lv_label_
    lv_obj_align(ui_LabelButton22, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_set_style_text_font(ui_LabelButton22, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton22, "20级");
    lv_obj_set_style_text_color(ui_LabelButton22, lv_color_hex(0xFF9E00), 0);

    img_yellow3 = lv_img_create(ui_Tating);
    lv_img_set_src(img_yellow3, &ratingyellow_image);
    lv_obj_align(img_yellow3, LV_ALIGN_TOP_LEFT, 245, 113);
    lv_obj_add_flag(img_yellow3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_yellow3, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn3 = lv_btn_create(ui_Tating);
    lv_obj_set_pos(white_btn3, 245, 113);
    lv_obj_set_size(white_btn3, 105, 142);
    lv_obj_set_style_radius(white_btn3, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn3, 0, LV_PART_MAIN);  // 41是透明度为16%
    lv_obj_clear_flag(white_btn3, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn3, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton31 = lv_label_create(white_btn3);
    // lv_label_
    lv_obj_align(ui_LabelButton31, LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_set_style_text_font(ui_LabelButton31, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelButton31, "19");
    lv_obj_set_style_text_color(ui_LabelButton31, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton32 = lv_label_create(white_btn3);
    // lv_label_
    lv_obj_align(ui_LabelButton32, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_set_style_text_font(ui_LabelButton32, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton32, "19级");
    lv_obj_set_style_text_color(ui_LabelButton32, lv_color_hex(0xFF9E00), 0);

    img_black = lv_img_create(ui_Tating);
    lv_img_set_src(img_black, &ratingblack_image);
    lv_obj_align(img_black, LV_ALIGN_TOP_LEFT, 360, 113);
    lv_obj_add_flag(img_black, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_black, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn4 = lv_btn_create(ui_Tating);
    lv_obj_set_pos(white_btn4, 360, 113);
    lv_obj_set_size(white_btn4, 105, 142);
    lv_obj_set_style_radius(white_btn4, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn4, 0, LV_PART_MAIN);  // 41是透明度为16%
    lv_obj_clear_flag(white_btn4, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn4, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton41 = lv_label_create(white_btn4);
    // lv_label_
    lv_obj_align(ui_LabelButton41, LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_set_style_text_font(ui_LabelButton41, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelButton41, "19");
    lv_obj_set_style_text_color(ui_LabelButton41, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *ui_LabelButton42 = lv_label_create(white_btn4);
    // lv_label_
    lv_obj_align(ui_LabelButton42, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_set_style_text_font(ui_LabelButton42, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton42, "19级");
    lv_obj_set_style_text_color(ui_LabelButton42, lv_color_hex(0xFF9E00), 0);


    lv_obj_add_event_cb(ui_Tating, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}