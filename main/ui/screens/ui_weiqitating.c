#include "ui.h"
#include "app.h"

static const char *TAG = "ui_weiqitating";

lv_obj_t *ui_Weiqitating;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;

static lv_obj_t *white_btn11 = NULL;
static lv_obj_t *white_btn12 = NULL;
static lv_obj_t *white_btn21 = NULL;
static lv_obj_t *white_btn22 = NULL;
static lv_obj_t *white_btn23 = NULL;
static lv_obj_t *white_btn31 = NULL;

static void update_button_colors(lv_obj_t *selected_btn)
{
    // 将所有按钮设置为未选中状态（0xffffff，透明度41）
    // lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn2, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn3, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn4, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn5, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn5, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn6, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn6, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);

    // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    //  if (selected_btn == white_btn)
    //  {
    //      _ui_screen_change(&ui_Volume, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_Volume_screen_init);
    //  }
    //  else if (selected_btn == white_btn2)
    //  {
    //      _ui_screen_change(&ui_Lights, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_Lights_screen_init);
    //  }else if (selected_btn == white_btn3)
    //  {
    //      _ui_screen_change(&ui_Language, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_Language_screen_init);
    //  }else if (selected_btn == white_btn4)
    //  {
    //      _ui_screen_change(&ui_About, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_About_screen_init);
    //  }else if (selected_btn == white_btn5)
    //  {
    //      _ui_screen_change(&ui_Test_newversion, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_Test_newversion_screen_init);
    //  }else if (selected_btn == white_btn6)
    //  {
    //      _ui_screen_change(&ui_Factory, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                        ui_Factory_screen_init);
    //  }
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
    _ui_screen_delete(&ui_Weiqitating);
}

void ui_Weiqitating_screen_init(void)
{
    ui_Weiqitating = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Weiqitating, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Weiqitating, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Weiqitating);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "围棋18级");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Weiqitating);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Weiqitating);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn11 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn11, 107, 90);
    lv_obj_set_size(white_btn11, 120, 50);
    lv_obj_set_style_radius(white_btn11, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn11, lv_color_hex(0xFF851A), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn11, LV_OPA_100, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn11, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn11, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton11 = lv_label_create(white_btn11);
    // lv_label_
    lv_obj_align(ui_LabelButton11, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton11, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton11, "13路");
    lv_obj_set_style_text_color(ui_LabelButton11, lv_color_hex(0xFFFFFF), 0);

    white_btn12 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn12, 252, 90);
    lv_obj_set_size(white_btn12, 120, 50);
    lv_obj_set_style_radius(white_btn12, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn12, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn12, 41, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn12, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn12, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton12 = lv_label_create(white_btn12);
    // lv_label_
    lv_obj_align(ui_LabelButton12, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton12, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton12, "9路");
    lv_obj_set_style_text_color(ui_LabelButton12, lv_color_hex(0xFFFFFF), 0);

    white_btn21 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn21, 35, 158);
    lv_obj_set_size(white_btn21, 120, 50);
    lv_obj_set_style_radius(white_btn21, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn21, lv_color_hex(0xFF851A), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn21, LV_OPA_100, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn21, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn21, button_click_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t *ui_LabelButton21 = lv_label_create(white_btn21);
    // lv_label_
    lv_obj_align(ui_LabelButton21, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton21, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton21, "执黑");
    lv_obj_set_style_text_color(ui_LabelButton21, lv_color_hex(0xFFFFFF), 0);

    white_btn22 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn22, 180, 158);
    lv_obj_set_size(white_btn22, 120, 50);
    lv_obj_set_style_radius(white_btn22, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn22, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn22, 41, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn22, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn22, button_click_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t *ui_LabelButton22 = lv_label_create(white_btn22);
    // lv_label_
    lv_obj_align(ui_LabelButton22, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton22, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton22, "猜先");
    lv_obj_set_style_text_color(ui_LabelButton22, lv_color_hex(0xFFFFFF), 0);

     white_btn23 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn23, 325, 158);
    lv_obj_set_size(white_btn23, 120, 50);
    lv_obj_set_style_radius(white_btn23, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn23, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn23, 41, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn23, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn23, button_click_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t *ui_LabelButton23 = lv_label_create(white_btn23);
    // lv_label_
    lv_obj_align(ui_LabelButton23, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton23, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton23, "执白");
    lv_obj_set_style_text_color(ui_LabelButton23, lv_color_hex(0xFFFFFF), 0);

    white_btn31 = lv_btn_create(ui_Weiqitating);
    lv_obj_set_pos(white_btn31, 180, 236);
    lv_obj_set_size(white_btn31, 120, 50);
    lv_obj_set_style_radius(white_btn31, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn31, lv_color_hex(0xFF851A), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn31, LV_OPA_100, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn31, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn31, button_click_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t *ui_LabelButton31 = lv_label_create(white_btn31);
    // lv_label_
    lv_obj_align(ui_LabelButton31, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton31, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton31, "确认");
    lv_obj_set_style_text_color(ui_LabelButton31, lv_color_hex(0xFFFFFF), 0);

    // white_btn2 = lv_btn_create(ui_Weiqitating);
    // lv_obj_set_pos(white_btn2, 177, 105);
    // lv_obj_set_size(white_btn2, 125, 60);
    // lv_obj_set_style_radius(white_btn2, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn2, 41, LV_PART_MAIN); // 41是透明度为16%
    // lv_obj_clear_flag(white_btn2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(white_btn2, button_click_handler, LV_EVENT_CLICKED, NULL);

    // lv_obj_t *ui_LabelButton2 = lv_label_create(white_btn2);
    // // lv_label_
    // lv_obj_align(ui_LabelButton2, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_font(ui_LabelButton2, &MiSansBold_26, 0);
    // lv_label_set_text(ui_LabelButton2, "屏幕亮度");
    // lv_obj_set_style_text_color(ui_LabelButton2, lv_color_hex(0xFF8519), 0);

    // white_btn3 = lv_btn_create(ui_Weiqitating);
    // lv_obj_set_pos(white_btn3, 322, 105);
    // lv_obj_set_size(white_btn3, 125, 60);
    // lv_obj_set_style_radius(white_btn3, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(white_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn3, 41, LV_PART_MAIN); // 41是透明度为16%
    // lv_obj_clear_flag(white_btn3, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(white_btn3, button_click_handler, LV_EVENT_CLICKED, NULL);

    // lv_obj_t *ui_LabelButton3 = lv_label_create(white_btn3);
    // // lv_label_
    // lv_obj_align(ui_LabelButton3, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_font(ui_LabelButton3, &MiSansBold_26, 0);
    // lv_label_set_text(ui_LabelButton3, "语言设置");
    // lv_obj_set_style_text_color(ui_LabelButton3, lv_color_hex(0xFF8519), 0);

    // white_btn4 = lv_btn_create(ui_Weiqitating);
    // lv_obj_set_pos(white_btn4, 32, 197);
    // lv_obj_set_size(white_btn4, 125, 60);
    // lv_obj_set_style_radius(white_btn4, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(white_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn4, 41, LV_PART_MAIN); // 41是透明度为16%
    // lv_obj_clear_flag(white_btn4, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(white_btn4, button_click_handler, LV_EVENT_CLICKED, NULL);

    // lv_obj_t *ui_LabelButton4 = lv_label_create(white_btn4);
    // // lv_label_
    // lv_obj_align(ui_LabelButton4, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_font(ui_LabelButton4, &MiSansBold_26, 0);
    // lv_label_set_text(ui_LabelButton4, "关于本机");
    // lv_obj_set_style_text_color(ui_LabelButton4, lv_color_hex(0xFF8519), 0);

    // white_btn5 = lv_btn_create(ui_Weiqitating);
    // lv_obj_set_pos(white_btn5, 177, 197);
    // lv_obj_set_size(white_btn5, 125, 60);
    // lv_obj_set_style_radius(white_btn5, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(white_btn5, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn5, 41, LV_PART_MAIN); // 41是透明度为16%
    // lv_obj_clear_flag(white_btn5, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(white_btn5, button_click_handler, LV_EVENT_CLICKED, NULL);

    // lv_obj_t *ui_LabelButton5 = lv_label_create(white_btn5);
    // // lv_label_
    // lv_obj_align(ui_LabelButton5, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_font(ui_LabelButton5, &MiSansBold_26, 0);
    // lv_label_set_text(ui_LabelButton5, "系统更新");
    // lv_obj_set_style_text_color(ui_LabelButton5, lv_color_hex(0xFF8519), 0);

    // white_btn6 = lv_btn_create(ui_Weiqitating);
    // lv_obj_set_pos(white_btn6, 322, 197);
    // lv_obj_set_size(white_btn6, 125, 60);
    // lv_obj_set_style_radius(white_btn6, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(white_btn6, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn6, 41, LV_PART_MAIN); // 41是透明度为16%
    // lv_obj_clear_flag(white_btn6, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(white_btn6, button_click_handler, LV_EVENT_CLICKED, NULL);

    // lv_obj_t *ui_LabelButton6 = lv_label_create(white_btn6);
    // // lv_label_
    // lv_obj_align(ui_LabelButton6, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_font(ui_LabelButton6, &MiSansBold_26, 0);
    // lv_label_set_text(ui_LabelButton6, "恢复出厂");
    // lv_obj_set_style_text_color(ui_LabelButton6, lv_color_hex(0xFF8519), 0);

    lv_obj_add_event_cb(ui_Weiqitating, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}