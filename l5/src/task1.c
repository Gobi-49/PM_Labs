#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"
#include "adc.h"
#include "task1.h"

void task1(void) {
  while (1) {
    // TODO [task1]: Use the previous defined function to read the ADC
    // value of the temperature sensor (PA0) and print it to the serial
    uint32_t t = myAnalogRead(PA0);
    uint32_t Vin = t*3300/1024;
    uint32_t Ta = (Vin - 400)/19.5;
    printf("val: %ld\n", Ta);
  }
}
