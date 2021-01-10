#include "../components/esp-sprinkler/ssd-1306-display.hpp"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <cstdio>
#include <driver/i2c.h>
#include <esp_log.h>
#include <iostream>
#include <sdkconfig.h>
#include <sprinkler/app/app.hpp>

extern "C" {
void app_main();
}


void app_main() {
  sprinkler::esp::SSD1306Display display(128, 64);

  sprinkler::app::App app(&display);
  app.init();

  while (true) {
    app.tick();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}