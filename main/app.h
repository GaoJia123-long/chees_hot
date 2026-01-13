#include <stdbool.h>
#include <stdint.h>
#include "xl01.h"

typedef struct {
    uint8_t subsele;
} app_t;

extern app_t app;


esp_err_t app_init(void);