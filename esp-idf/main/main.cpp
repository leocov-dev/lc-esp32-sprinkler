#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <cstdio>
#include <driver/i2c.h>
#include <esp_log.h>
#include <iostream>
#include <sdkconfig.h>
#include <sprinkler/app/app.hpp>
#include <sprinkler/constants.hpp>

extern "C" {
void app_main();
}

namespace {
namespace app = sprinkler::app;
namespace esp = sprinkler::esp;
}


void app_main() {
  esp::SSD1306Display display(kDisplayWidth, kDisplayHeight);

  app::App app(&display);
  app.init();

  while (true) {
    app.Tick();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}