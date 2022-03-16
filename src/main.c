#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"
#include "hardware/irq.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;



void boardLEDTask(void *param)
{
    gpio_put(LED_PIN, 1);
    vTaskDelay(100);
    gpio_put(LED_PIN, 0);
    vTaskDelay(100);
}

int main() 
{
 
     gpio_init(LED_PIN);
     gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);


    TaskHandle_t hTask=NULL;
    xTaskCreate(boardLEDTask,"",1024,NULL,tskIDLE_PRIORITY,&hTask);

    vTaskStartScheduler();

    while (true){
        sleep_ms(50);
    }
    
}
