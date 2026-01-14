#include "ui.h"
#include "app.h"

static const char *TAG = "ui_netset";

lv_obj_t *ui_Netset;

static lv_obj_t *img_leftarr = NULL;
static lv_obj_t *img_home = NULL;
static lv_obj_t *img_white = NULL;
static lv_obj_t *img_link = NULL;
static lv_obj_t *img_lock = NULL;
static lv_obj_t *img_wifi0 = NULL;
static lv_obj_t *img_wifi1 = NULL;
static lv_obj_t *img_wifi2 = NULL;
static lv_obj_t *img_wifi3 = NULL;

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
    _ui_screen_delete(&ui_Netset);
}

void ui_Netset_screen_init(void)
{
    ui_Netset = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Netset, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Netset, lv_color_hex(0x171726), 0);

    lv_obj_t *ui_LabelMenu = lv_label_create(ui_Netset);
    // lv_label_
    lv_obj_align(ui_LabelMenu, LV_ALIGN_TOP_MID, 0, 29);
    lv_obj_set_style_text_font(ui_LabelMenu, &MiSansBold_26, 0);
    lv_label_set_text(ui_LabelMenu, "网络设置");
    lv_obj_set_style_text_color(ui_LabelMenu, lv_color_hex(0xffffff), 0);

    img_home = lv_img_create(ui_Netset);
    lv_img_set_src(img_home, &home_image);
    lv_obj_align(img_home, LV_ALIGN_TOP_LEFT, 32, 29);
    lv_obj_add_flag(img_home, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_home, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    img_leftarr = lv_img_create(ui_Netset);
    lv_img_set_src(img_leftarr, &leftarr_image);
    lv_obj_align(img_leftarr, LV_ALIGN_TOP_LEFT, 407, 29);
    lv_obj_add_flag(img_leftarr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_leftarr, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // img_white = lv_img_create(ui_Netset);
    // lv_img_set_src(img_white, &white_image);
    // lv_obj_align(img_white, LV_ALIGN_TOP_LEFT, 32, 87);
    // lv_obj_set_size(img_white, 415, 205);
    // lv_obj_align(img_white, LV_ALIGN_TOP_MID, 0, 100);

    // lv_obj_add_flag(img_white, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(img_white, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // img_link = lv_img_create(ui_Netset);
    // lv_img_set_src(img_link, &link_image);
    // lv_obj_align(img_link, LV_ALIGN_TOP_LEFT, 32, 87);
    // lv_obj_add_flag(img_link, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(img_link, button_click_handler, LV_EVENT_SHORT_CLICKED, NULL);

    // 直接在白色图片上创建列表（作为子对象）
    lv_obj_t *list_cont = lv_obj_create(ui_Netset);

    // 设置列表容器的大小和位置
    lv_obj_set_size(list_cont, 415, 205);
    lv_obj_align(list_cont, LV_ALIGN_TOP_MID, 0, 100);

    // 设置列表样式
    lv_obj_set_style_bg_color(list_cont, lv_color_hex(0xDCDFE5), 0);
    lv_obj_set_style_bg_opa(list_cont, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(list_cont, 10, 0);
    lv_obj_set_style_border_width(list_cont, 1, 0);
    lv_obj_set_style_border_color(list_cont, lv_color_hex(0xDCDFE5), 0);

    // 设置垂直布局
    lv_obj_set_flex_flow(list_cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(list_cont, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    // 创建列表项
    create_list_item(list_cont, "XXXXXXXXXXX", 0);
    create_list_item(list_cont, "XXXXXXXXXX", 1);
    create_list_item(list_cont, "XXXX", 2);
    create_list_item(list_cont, "XXXXXXXXXXXX", 3);
    create_list_item(list_cont, "XXXXXXXXX", 4);
    create_list_item(list_cont, "XXXXXXXXXXXXXX", 5);
    create_list_item(list_cont, "XXXXXX", 6);

    lv_obj_add_event_cb(ui_Netset, event_unload_handler, LV_EVENT_SCREEN_UNLOADED,
                        NULL);
}

// 创建列表项函数
static void create_list_item(lv_obj_t *parent, const char *text, int id)
{
    // 创建按钮容器
    lv_obj_t *item = lv_obj_create(parent);
    lv_obj_set_width(item, lv_pct(100)); // 100%宽度
    lv_obj_set_height(item, 35);         // 适当的高度

    // lv_obj_clear_flag(item, LV_OBJ_FLAG_SCROLLABLE);

    // 设置按钮样式
    lv_obj_set_style_bg_color(item, lv_color_hex(0xDCDFE5), 0);
    lv_obj_set_style_bg_color(item, lv_color_hex(0xDCDFE5), LV_STATE_PRESSED);
    lv_obj_set_style_radius(item, 0, 35); // 矩形，无圆角
    lv_obj_set_style_border_width(item, 0, 0);
    lv_obj_set_style_pad_hor(item, 10, 0); // 水平内边距
    lv_obj_set_style_pad_ver(item, 5, 0);  // 垂直内边距

    // 移除默认外边距
    lv_obj_set_style_pad_all(item, 0, 0);

    // 设置为可点击
    lv_obj_add_flag(item, LV_OBJ_FLAG_CLICKABLE);

    // 添加点击事件
    lv_obj_add_event_cb(item, netset_item_handler, LV_EVENT_CLICKED, (void *)(intptr_t)id);

    // 创建文本标签
    lv_obj_t *text_label = lv_label_create(item);
    lv_label_set_text(text_label, text);
    lv_obj_set_style_text_color(text_label, lv_color_hex(0x000000), 0);
    lv_obj_set_style_text_font(text_label, &MiSansBold_26, 0);
    lv_obj_align(text_label, LV_ALIGN_LEFT_MID, 50, 0);

    // 如果有图标，文本向右偏移
    lv_obj_align(text_label, LV_ALIGN_LEFT_MID, 15, 0); // 无图标时更靠左

    img_lock = lv_img_create(item);
    lv_img_set_src(img_lock, &lock_imaeg);
    lv_obj_align(img_lock, LV_ALIGN_RIGHT_MID, -40, 0);

    if (id == 0)
    {
        img_link = lv_img_create(item);
        lv_img_set_src(img_link, &link_image);
        lv_obj_align(img_link, LV_ALIGN_RIGHT_MID, -70, 0); // 在箭头左侧

        img_wifi3 = lv_img_create(item);
        lv_img_set_src(img_wifi3, &wifi3_image);
        lv_obj_align(img_wifi3, LV_ALIGN_RIGHT_MID, 0, 0); // 在箭头左侧
    }
    else if (id == 1)
    {
        img_wifi2 = lv_img_create(item);
        lv_img_set_src(img_wifi2, &wifi2_image);
        lv_obj_align(img_wifi2, LV_ALIGN_RIGHT_MID, 0, 0); // 在箭头左侧
    }
    else if (id == 2)
    {
        img_wifi1 = lv_img_create(item);
        lv_img_set_src(img_wifi1, &wifi1_image);
        lv_obj_align(img_wifi1, LV_ALIGN_RIGHT_MID, 0, 0); // 在箭头左侧
    }
    else
    {
        img_wifi0 = lv_img_create(item);
        lv_img_set_src(img_wifi0, &wifi0_image);
        lv_obj_align(img_wifi0, LV_ALIGN_RIGHT_MID, 0, 0); // 在箭头左侧
    }

    // 添加分隔线（在按钮底部）
    lv_obj_t *line = lv_obj_create(item);
    lv_obj_set_size(line, 360, 1);
    lv_obj_align(line, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(line, lv_color_hex(0x3A3A4A), 0);
    lv_obj_set_style_bg_opa(line, LV_OPA_30, 0);
    lv_obj_clear_flag(line, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_parent(line, item); // 确保分隔线在按钮内
}

// 事件处理函数
static void netset_item_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        int item_id = (int)(intptr_t)lv_event_get_user_data(e);

        // 根据item_id执行不同的操作
        switch (item_id)
        {
        case 0: // Wi-Fi设置
            printf("打开Wi-Fi设置\n");
            break;
        case 1: // 蓝牙设置
            printf("打开蓝牙设置\n");
            break;
        case 2: // 移动网络
            printf("打开移动网络设置\n");
            break;
        case 3: // 热点设置
            printf("打开热点设置\n");
            break;
        case 4: // VPN设置
            printf("打开VPN设置\n");
            break;
        case 5: // 飞行模式
            printf("切换飞行模式\n");
            break;
        case 6: // 更多设置
            printf("打开更多设置\n");
            break;
        }
    }
}