/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_task_wdt.h"

int main(int argc, char *argv[]);

void main_task(void *p)
{
    char *param[] = {"0", "0", "0x66", "2500"};		// These parameters are not taken into account

    main(4,param);

    vTaskDelete(NULL);
}

void app_main(void)
{
    xTaskCreate(main_task, "main", 8192, NULL, 6, NULL);
}
