#include "ui.h"
#include "app.h"

static const char *TAG = "ui_newversion";

lv_obj_t *ui_Newversion;

static lv_obj_t *img_notice = NULL;

static lv_obj_t *white_btn = NULL;
static lv_obj_t *white_btn2 = NULL;

static void update_button_colors(lv_obj_t *selected_btn)
{
    // 将所有按钮设置为未选中状态（0xffffff，透明度41）
    // lv_obj_set_style_bg_color(white_btn, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(white_btn2, 41, LV_PART_MAIN);

    // lv_obj_set_style_bg_color(selected_btn, lv_color_hex(0xE8E8E8), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(selected_btn, LV_OPA_100, LV_PART_MAIN);

    // 将选中的按钮设置为选中状态（0xE8E8E8，透明度100）
    // if (selected_btn == white_btn)
    // {
    //     _ui_screen_change(&ui_Username, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                       ui_Username_screen_init);
    // }
    // else if (selected_btn == white_btn2)
    // {
    //     _ui_screen_change(&ui_Newversion, LV_SCR_LOAD_ANIM_NONE, 0, 0,
    //                       ui_Newversion_screen_init);
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
        // if (lv_event_get_target(e) == img_home || lv_event_get_target(e) == img_leftarr)
        // {
        //     _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_NONE, 0, 0,
        //                       ui_Main_screen_init);
        // }
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
    _ui_screen_delete(&ui_Newversion);
}

void ui_Newversion_screen_init(void)
{
    ui_Newversion = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Newversion, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Newversion, lv_color_hex(0x000000), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Newversion);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 58);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansRegular_40, 0);
    lv_label_set_text(ui_LabelMenu, "当前系统已是最新版本");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xFFAA00), 0);

    lv_obj_t *ui_LabelButton3 = lv_label_create(ui_Newversion);
    // lv_label_
    lv_obj_align(ui_LabelButton3, LV_ALIGN_TOP_MID, 0, 131);
    lv_obj_set_style_text_font(ui_LabelButton3, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton3, "系统版本:QS2026.0120");
    lv_obj_set_style_text_color(ui_LabelButton3, lv_color_hex(0xFFFFFF), 0);

    white_btn2 = lv_btn_create(ui_Newversion);
    lv_obj_set_pos(white_btn2, 180, 217);
    lv_obj_set_size(white_btn2, 120, 49);
    lv_obj_set_style_radius(white_btn2, 44, LV_PART_MAIN);
    lv_obj_set_style_bg_color(white_btn2, lv_color_hex(0xFFB53D), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(white_btn2, LV_OPA_100, LV_PART_MAIN);
    lv_obj_clear_flag(white_btn2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(white_btn2, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton2 = lv_label_create(white_btn2);
    // lv_label_
    lv_obj_align(ui_LabelButton2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton2, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton2, "确认");
    lv_obj_set_style_text_color(ui_LabelButton2, lv_color_hex(0xFFFFFF), 0);

    lv_obj_add_event_cb(ui_Newversion, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}