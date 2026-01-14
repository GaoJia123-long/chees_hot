#include "ui.h"
#include "app.h"

static const char *TAG = "ui_netpassword";

lv_obj_t *ui_Netpassword;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_white = NULL;
static lv_obj_t *img_openeye = NULL;
static lv_obj_t *img_closeeye = NULL;

static lv_obj_t *wifi_btn1 = NULL;
static lv_obj_t *wifi_btn2 = NULL;
static lv_obj_t *wifi_btn3 = NULL;
static lv_obj_t *wifi_btn4 = NULL;
static lv_obj_t *wifi_btn5 = NULL;

static lv_obj_t *list = NULL;

static void create_list_item(lv_obj_t *parent, const char *text, int id);
static void netset_item_handler(lv_event_t *e);

static void
update_button_colors(lv_obj_t *selected_btn)
{
    // 将所有按钮设置为未选中状态（0xffffff，透明度41）
    lv_obj_set_style_bg_color(wifi_btn1, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn1, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(wifi_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn2, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(wifi_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn3, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(wifi_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn4, 41, LV_PART_MAIN);

    lv_obj_set_style_bg_color(wifi_btn5, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn5, 41, LV_PART_MAIN);

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
    _ui_screen_delete(&ui_Netpassword);
}

void ui_Netpassword_screen_init(void)
{
    ui_Netpassword = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Netpassword, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Netpassword, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Netpassword);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "网络设置");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Netpassword);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Netpassword);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // wifi_btn1 = lv_btn_create(ui_Netpassword);
    // lv_obj_set_pos(wifi_btn1, 32, 89);
    // lv_obj_set_size(wifi_btn1, 415, 35);
    // lv_obj_set_style_radius(wifi_btn1, 12, LV_PART_MAIN);
    // lv_obj_set_style_bg_color(wifi_btn1, lv_color_hex(0x171726), LV_PART_MAIN);
    // lv_obj_set_style_bg_opa(wifi_btn1, LV_OPA_100, LV_PART_MAIN);
    // lv_obj_clear_flag(wifi_btn1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_add_event_cb(wifi_btn1, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton = lv_label_create(ui_Netpassword);
    // lv_label_
    lv_obj_align(ui_LabelButton, LV_ALIGN_TOP_MID, 0, 89);
    lv_obj_set_style_text_font(ui_LabelButton, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton, "XXXXX");
    lv_obj_set_style_text_color(ui_LabelButton, lv_color_hex(0xFFFFFF), 0);

    wifi_btn2 = lv_btn_create(ui_Netpassword);
    lv_obj_set_pos(wifi_btn2, 69, 138);
    lv_obj_set_size(wifi_btn2, 342, 47);
    lv_obj_set_style_radius(wifi_btn2, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(wifi_btn2, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn2, LV_OPA_100, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(wifi_btn2, LV_OBJ_FLAG_SCROLLABLE);         /// Flags
    lv_obj_add_event_cb(wifi_btn2, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton2 = lv_label_create(wifi_btn2);
    // lv_label_
    lv_obj_align(ui_LabelButton2, LV_ALIGN_CENTER, -100, 0);
    lv_obj_set_style_text_font(ui_LabelButton2, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton2, "输入密码");
    lv_obj_set_style_text_color(ui_LabelButton2, lv_color_hex(0xAAAAAA), 0);

    wifi_btn3 = lv_btn_create(ui_Netpassword);
    lv_obj_set_pos(wifi_btn3, 361, 149);
    lv_obj_set_size(wifi_btn3, 28, 28);
    lv_obj_set_style_radius(wifi_btn3, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(wifi_btn3, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn3, LV_OPA_100, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(wifi_btn3, LV_OBJ_FLAG_SCROLLABLE);         /// Flags
    lv_obj_add_event_cb(wifi_btn3, button_click_handler, LV_EVENT_CLICKED, NULL);

    img_openeye = lv_img_create(ui_Netpassword);
    lv_img_set_src(img_openeye, &openeye_image);
    lv_obj_align(img_openeye, LV_ALIGN_TOP_LEFT, 363, 155);
    lv_obj_add_flag(img_openeye, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_openeye, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);
#if 0
    img_closeeye = lv_img_create(ui_Netpassword);
    lv_img_set_src(img_closeeye, &closeeye_image);
    lv_obj_align(img_closeeye, LV_ALIGN_TOP_LEFT, 363, 155);
    lv_obj_add_flag(img_closeeye, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_closeeye, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);
#endif

    wifi_btn4 = lv_btn_create(ui_Netpassword);
    lv_obj_set_pos(wifi_btn4, 88, 225);
    lv_obj_set_size(wifi_btn4, 120, 50);
    lv_obj_set_style_radius(wifi_btn4, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(wifi_btn4, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn4, 41, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(wifi_btn4, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_event_cb(wifi_btn4, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton4 = lv_label_create(wifi_btn4);
    // lv_label_
    lv_obj_align(ui_LabelButton4, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton4, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton4, "取消");
    lv_obj_set_style_text_color(ui_LabelButton4, lv_color_hex(0xFFFFFF), 0);

    wifi_btn5 = lv_btn_create(ui_Netpassword);
    lv_obj_set_pos(wifi_btn5, 270, 225);
    lv_obj_set_size(wifi_btn5, 120, 50);
    lv_obj_set_style_radius(wifi_btn5, 12, LV_PART_MAIN);
    lv_obj_set_style_bg_color(wifi_btn5, lv_color_hex(0xFF851A), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(wifi_btn5, LV_OPA_100, LV_PART_MAIN); // 41是透明度为16%
    lv_obj_clear_flag(wifi_btn5, LV_OBJ_FLAG_SCROLLABLE);         /// Flags
    lv_obj_add_event_cb(wifi_btn5, button_click_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t *ui_LabelButton5 = lv_label_create(wifi_btn5);
    // lv_label_
    lv_obj_align(ui_LabelButton5, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(ui_LabelButton5, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelButton5, "连接");
    lv_obj_set_style_text_color(ui_LabelButton5, lv_color_hex(0xFFFFFF), 0);

    lv_obj_add_event_cb(ui_Netpassword, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}
