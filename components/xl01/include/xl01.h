#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_event.h"
#include "lvgl.h"
#include "lv_port.h"

#define RETURN_ON_ERROR(x)                                                     \
    do {                                                                       \
        esp_err_t err_rc_ = (x);                                               \
        if (unlikely(err_rc_ != ESP_OK)) {                                     \
            return err_rc_;                                                    \
        }                                                                      \
    } while (0)

#define GOTO_ON_ERROR(x, goto_tag)                                             \
    do {                                                                       \
        esp_err_t err_rc_ = (x);                                               \
        if (unlikely(err_rc_ != ESP_OK)) {                                     \
            ret = err_rc_;                                                     \
            goto goto_tag;                                                     \
        }                                                                      \
    } while (0)

#define GOTO_ON_NULL(x, goto_tag)                                              \
    do {                                                                       \
        if ((x) == NULL) {                                                     \
            goto goto_tag;                                                     \
        }                                                                      \
    } while (0)

#define RETURN_NULL_ON_ERROR(x)                                                \
    do {                                                                       \
        if (unlikely((x) != ESP_OK)) {                                         \
            return NULL;                                                       \
        }                                                                      \
    } while (0)

#define RETURN_NULL_ON_NULL(x)                                            \
    do {                                                                       \
        if ((x) == NULL) {                                                     \
            return NULL;                                                       \
        }                                                                      \
    } while (0)


#define BSP_NVS_MFG_PARTITION "fctry"

esp_err_t bsp_init(void);

void bsp_display_start(void);

bool bsp_display_lock(uint32_t timeout_ms);
void bsp_display_unlock(void);


#ifdef __cplusplus
}
#endif