idf_component_register(
    SRCS "xl01.c" 
    INCLUDE_DIRS "include"
    REQUIRES driver
    PRIV_REQUIRES esp_lcd esp_timer esp_event nvs_flash fatfs esp32-camera lvgl_ui XPowersLib esp_bsp esp_lv_port 
)
