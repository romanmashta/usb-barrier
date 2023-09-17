#include "init.h"
#include <Arduino.h>

void initSystem()
{
  Serial.begin(115200);
  vTaskDelay(2000);
}