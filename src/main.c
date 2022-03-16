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
const uint OUT_PIN = 0; //external output pin


void boardLEDTask(void *param)
{
    while (true){
    
    gpio_put(LED_PIN, 1);
    vTaskDelay(333);
    gpio_put(LED_PIN, 0);
    vTaskDelay(333);
    }
}

void outBoardLEDTask(void *param)
{
    while (true){
    
    gpio_put(OUT_PIN, 1);
    vTaskDelay(500);
    gpio_put(OUT_PIN, 0);
    vTaskDelay(500);
    }
}






int main() 
{
 
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, 1);





    TaskHandle_t hTask1=NULL;
    TaskHandle_t hTask2=NULL;

    xTaskCreate(boardLEDTask,"",1024,NULL,1,&hTask1);
    xTaskCreate(outBoardLEDTask,"",1024,NULL,1,&hTask2);

    vTaskStartScheduler();

    while (true){
        sleep_ms(50);
    }
    
}
