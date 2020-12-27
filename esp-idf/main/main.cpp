#include <cstdio>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <driver/i2c.h>
#include <esp_log.h>
#include <sdkconfig.h>
#include <sprinkler/app/app.hpp>

extern "C" {
void app_main();
}

static char tag[] = "MAIN";

void app_main() {
//  App app(nullptr);

  ESP_LOGD(tag, ">> task_simple_tests_ssd1306");
  ESP_LOGD(tag, "<< task_simple_tests_ssd1306");

  int i = 0;
  while (1) {
    printf("[%d] Hello world!\n", i);
    i++;
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}