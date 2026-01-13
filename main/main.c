#include <stdio.h>

#include "bsp_i2c.h"
#include "bsp_display.h"
#include "bsp_touch.h"

#include "lv_port.h"
#include "esp_log.h"

#include "demos/lv_demos.h"
#include "esp_io_expander_tca9554.h"
#include "xl01.h"
#include "app.h"
#include "ui.h"
#include "lvgl.h"

static const char *TAG = "app_main";

void app_main(void)
{
    esp_err_t ret = ESP_OK;
    bsp_init();

    app_init();

    bsp_display_start();

    bsp_display_lock(0);
    ui_init();
    ui_Main_screen_init();
    lv_disp_load_scr(ui_Main);
    // ui_Username_screen_init();
    // lv_disp_load_scr(ui_Username);
    // ui_Userswitch_screen_init();
    // lv_disp_load_scr(ui_Userswitch);
    ui_Menustrap_screen_init();
    lv_disp_load_scr(ui_Menustrap);
    bsp_display_unlock();

    bsp_display_set_brightness(100);

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
