#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include "driver/gpio.h"
#include "soc/wdev_reg.h"
#include "xtensa/core-macros.h"

int i = 0;

void LED_task(void *pvParameter)
{
    (void)pvParameter;

    Serial.println("LED Start");


    while(1)
    {
        if(i % 3 == 0){
          Serial.println("1 Occasion");
          digitalWrite(25,HIGH);
          digitalWrite(32,LOW);
          digitalWrite(33,LOW);
          
          i++;
          vTaskDelay(1000 / portTICK_RATE_MS);

        }else if (i % 3 == 1){
          Serial.println("2 Occasion");
          digitalWrite(25,LOW);
          digitalWrite(32,HIGH);
          digitalWrite(33,LOW);
          
          i++;
          vTaskDelay(1000 / portTICK_RATE_MS);
          
        }else {
          Serial.println("3 Occasion");
          digitalWrite(25,LOW);
          digitalWrite(32,LOW);
          digitalWrite(33,HIGH);
          
          i++;
          vTaskDelay(1000 / portTICK_RATE_MS);

        }
        // vTaskDelay(100 / portTICK_RATE_MS);
    }
}


void freeRTOS_setup() {
    xTaskCreatePinnedToCore(&LED_task, "LED_task", 8192, NULL, 6, NULL, ARDUINO_RUNNING_CORE);

}