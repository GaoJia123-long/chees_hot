#include "ui.h"
#include "app.h"

static const char *TAG = "ui_volume";

lv_obj_t *ui_Volume;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_volume = NULL;
static lv_obj_t *img_slide = NULL;

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
    //     _ui_screen_change(&ui_Volume, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                       ui_Volume_screen_init);
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
    _ui_screen_delete(&ui_Volume);
}

void ui_Volume_screen_init(void)
{
    ui_Volume = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Volume, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Volume, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Volume);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "音量设置");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Volume);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Volume);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // 添加滑轨（slider）
    lv_obj_t *ui_SliderVolume = lv_slider_create(ui_Volume);
    lv_obj_set_size(ui_SliderVolume, 382, 37);                 // W382, H37
    lv_obj_align(ui_SliderVolume, LV_ALIGN_TOP_LEFT, 49, 161); // 位置49,161

    // 设置滑轨的样式
    // 设置滑轨的背景（未滑动到的部分）颜色
    lv_obj_set_style_bg_color(ui_SliderVolume, lv_color_hex(0xA9ACB2), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_SliderVolume, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(ui_SliderVolume, 44, LV_PART_MAIN); // 圆角效果

    // 设置滑轨的指示器（已滑动到的部分）颜色
    lv_obj_set_style_bg_color(ui_SliderVolume, lv_color_hex(0xFF9D00), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(ui_SliderVolume, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_radius(ui_SliderVolume, 44, LV_PART_INDICATOR); // 圆角效果

    img_volume = lv_img_create(ui_Volume);
    lv_img_set_src(img_volume, &volum_image);
    lv_obj_align(img_volume, LV_ALIGN_TOP_LEFT, 74, 169);
    lv_obj_add_flag(img_volume, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_volume, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // 完全去掉滑块
    // 将滑块大小设置为0
    lv_obj_set_style_width(ui_SliderVolume, 0, LV_PART_KNOB);
    lv_obj_set_style_height(ui_SliderVolume, 0, LV_PART_KNOB);
    // 或者使用透明度为0
    lv_obj_set_style_bg_opa(ui_SliderVolume, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_outline_opa(ui_SliderVolume, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_shadow_opa(ui_SliderVolume, LV_OPA_TRANSP, LV_PART_KNOB);

    // 设置滑轨的范围（0-100）
    lv_slider_set_range(ui_SliderVolume, 0, 100);

    // 设置初始值（例如50%）
    lv_slider_set_value(ui_SliderVolume, 50, LV_ANIM_OFF);

    lv_obj_add_event_cb(ui_Volume, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}