#include "ui.h"
#include "app.h"

static const char *TAG = "ui_main";

lv_obj_t *ui_Main;

static lv_obj_t* img_obj = NULL;

// 图片数组，包含所有4张图片
static const lv_img_dsc_t* demo_images[] = {
    
    &no_visiondemo,
    &chain_chees,
    &demo,
    
    &notion_chees
};

#define DEMO_IMAGE_COUNT 4

// 当前显示的图片索引
static int current_image_index = 0;


// 手势事件处理函数
static void gesture_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_GESTURE) {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        
        if(dir == LV_DIR_LEFT) {
            // 向左滑动，显示下一张图片
            current_image_index++;
            if(current_image_index >= DEMO_IMAGE_COUNT) {
                current_image_index = 0;  // 循环到第一张
            }
        }
        else if(dir == LV_DIR_RIGHT) {
            // 向右滑动，显示上一张图片
            current_image_index--;
            if(current_image_index < 0) {
                current_image_index = DEMO_IMAGE_COUNT - 1;  // 循环到最后一张
            }
            
        }
    }
    // lv_obj_set_size(img_obj, LV_HOR_RES, LV_VER_RES);
    //lv_img_set_src(img_obj, demo_images[current_image_index]);
    lv_img_set_src(img_obj, demo_images[current_image_index]);
}


void ui_Main_screen_init(void)
{
    ui_Main = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Main, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_Main,  lv_color_hex(0x000000), 0);

    img_obj = lv_img_create(ui_Main);
    lv_img_set_src(img_obj, demo_images[current_image_index]);
    
    // 设置图片为全屏显示
    lv_obj_align(img_obj, LV_ALIGN_CENTER, 0, 0);
//
    // 禁用滚动，这样手势事件才能正确触发
    lv_obj_clear_flag(img_obj, LV_OBJ_FLAG_SCROLLABLE);
    
    // 添加手势事件处理
    lv_obj_add_event_cb(img_obj, gesture_event_handler, LV_EVENT_GESTURE, NULL);
    // 阻止手势事件向上传递
    lv_obj_clear_flag(img_obj, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // 使图片可点击（用于手势检测）
    lv_obj_add_flag(img_obj, LV_OBJ_FLAG_CLICKABLE);
}