/*
 * Name: Lasse Kelling
 * Matrikelnummer: 2590639
 * Datum: 26.10.2023
 *
 * Unter (Properties -> Resource) encoding UTF-8 und line delimitor Unix auswählen!
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <inc/hw_memmap.h>
#include <inc/hw_types.h>

#include <driverlib/gpio.h>
#include <driverlib/pin_map.h>
#include <driverlib/sysctl.h>

#include "valueCollector.h"

void main(), setup();

void main() {
    uint32_t adcBuffer[1];
    setup();
    while(1) {
        sample(adcBuffer);
        printf("Sample erhalten: %4d\n", adcBuffer[0]);
    }
}

void setup() {
    /*
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL));
    GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3| GPIO_PIN_4);
    */
    initializeValueCollector();
    printf("Setup erfolgreich!\n");
}
