#include "ui.h"
#include "app.h"

static const char *TAG = "ui_about";

lv_obj_t *ui_About;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_white = NULL;

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

    lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);

    // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    // if (selected_btn == white_btn)
    // {
    //     _ui_screen_change(&ui_Username, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                       ui_Username_screen_init);
    // }
    // else if (selected_btn == white_btn2)
    // {
    //     _ui_screen_change(&ui_About, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                       ui_About_screen_init);
    // }
    // if(selected_btn != NULL) {
    //
    // }
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
    _ui_screen_delete(&ui_About);
}

void ui_About_screen_init(void)
{
    ui_About = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_About, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_About, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "关于本机");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_About);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_About);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_white = lv_img_create(ui_About);
    lv_img_set_src(img_white, &white_image);
    lv_obj_align(img_white, LV_ALIGN_TOP_LEFT, 32, 87);
    lv_obj_add_flag(img_white, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_white, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton, LV_ALIGN_TOP_LEFT, 58, 109);
    lv_obj_set_style_text_font(ui_LabelButton, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton, "本机名称：");
    lv_obj_set_style_text_color(ui_LabelButton, lv_color_hex(0x666666), 0);

    lv_obj_t *ui_LabelButton2 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton2, LV_ALIGN_TOP_LEFT, 168, 109);
    lv_obj_set_style_text_font(ui_LabelButton2, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton2, "小联猫下棋机器人");
    lv_obj_set_style_text_color(ui_LabelButton2, lv_color_hex(0x000000), 0);

    lv_obj_t *ui_LabelButton3 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton3, LV_ALIGN_TOP_LEFT, 58, 152);
    lv_obj_set_style_text_font(ui_LabelButton3, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton3, "设备型号：");
    lv_obj_set_style_text_color(ui_LabelButton3, lv_color_hex(0x666666), 0);

    lv_obj_t *ui_LabelButton4 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton4, LV_ALIGN_TOP_LEFT, 168, 152);
    lv_obj_set_style_text_font(ui_LabelButton4, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton4, "XLM-60R0BOT-AI");
    lv_obj_set_style_text_color(ui_LabelButton4, lv_color_hex(0x000000), 0);

    lv_obj_t *ui_LabelButton5 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton5, LV_ALIGN_TOP_LEFT, 58, 195);
    lv_obj_set_style_text_font(ui_LabelButton5, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton5, "设备编号：");
    lv_obj_set_style_text_color(ui_LabelButton5, lv_color_hex(0x666666), 0);

    lv_obj_t *ui_LabelButton6 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton6, LV_ALIGN_TOP_LEFT, 168, 195);
    lv_obj_set_style_text_font(ui_LabelButton6, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton6, "XLM20260120001");
    lv_obj_set_style_text_color(ui_LabelButton6, lv_color_hex(0x000000), 0);

    lv_obj_t *ui_LabelButton7 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton7, LV_ALIGN_TOP_LEFT, 58, 238);
    lv_obj_set_style_text_font(ui_LabelButton7, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton7, "软件版本：");
    lv_obj_set_style_text_color(ui_LabelButton7, lv_color_hex(0x666666), 0);

    lv_obj_t *ui_LabelButton8 = lv_label_create(ui_About);
    // lv_label_
    lv_obj_align(ui_LabelButton8, LV_ALIGN_TOP_LEFT, 168, 238);
    lv_obj_set_style_text_font(ui_LabelButton8, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton8, "1.4.52");
    lv_obj_set_style_text_color(ui_LabelButton8, lv_color_hex(0x000000), 0);

    lv_obj_add_event_cb(ui_About, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}