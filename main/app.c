#include "app.h"
#include "esp_app_desc.h"
#include "esp_check.h"
#include "esp_log.h"
#include "esp_task_wdt.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "nvs_flash.h"
#include <unistd.h>

static const char *TAG = "app";

#define CFG_NAMESPACE "cfg"

app_t app = {
    .subsele = 0,
};

esp_err_t app_init(void)
{
    esp_err_t ret = ESP_OK;
    nvs_handle_t handle;

    ret = nvs_open_from_partition(BSP_NVS_MFG_PARTITION, CFG_NAMESPACE,
                                  NVS_READWRITE, &handle);
    if(ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to open NVS partition %s namespace %s: %s",
                     BSP_NVS_MFG_PARTITION, CFG_NAMESPACE, esp_err_to_name(ret));
        return ret;
    }
    nvs_close(handle);

    return ESP_OK;
}