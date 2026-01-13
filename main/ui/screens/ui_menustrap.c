#include "ui.h"
#include "app.h"

static const char *TAG = "ui_menustrap";

lv_obj_t *ui_Menustrap;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_qr_code = NULL;

static lv_obj_t *white_btn = NULL;
static lv_obj_t *white_btn2 = NULL;
static lv_obj_t *white_btn3 = NULL;
static lv_obj_t *white_btn4 = NULL;

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

    // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    if (selected_btn != NULL)
    {
        lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);
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
    _ui_screen_delete(&ui_Menustrap);
}

void ui_Menustrap_screen_init(void)
{
    ui_Menustrap = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Menustrap, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Menustrap, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Menustrap);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "设备绑定");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Menustrap);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Menustrap);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_qr_code = lv_img_create(ui_Menustrap);
    lv_img_set_src(img_qr_code, &QR_code_image);
    lv_obj_align(img_qr_code, LV_ALIGN_TOP_LEFT, 160, 87);
    lv_obj_add_flag(img_qr_code, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_qr_code, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    white_btn = lv_btn_create(ui_Menustrap);
    lv_obj_set_pos(white_btn, 0, 259);
    lv_obj_set_size(white_btn, 480, 36);
    lv_obj_set_style_radius(white_btn, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn, LV_OPA_0, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton = lv_label_create(white_btn);
    // lv_label_
    lv_obj_align(ui_LabelButton, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton, "打开微信，扫码绑定设备");
    lv_obj_set_style_text_color(ui_LabelButton, lv_color_hex(0xFFFFFF), 0);

    lv_obj_add_event_cb(ui_Menustrap, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}