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
#include "touchControl.h"

void main(), setup();

void main() {
    uint32_t adcBuffer[1];
    setup();
    fillRect(0, 0, MAX_X, MAX_Y, 0x000000);
    fillRect(100, 40, 700, 440, 0xffff00);
    fillRect(200, 300, 300, 400, 0xff00ff);
    while(1) {
        //
        //sample(adcBuffer);
        //printf("Sample erhalten: %4d\n", adcBuffer[0]);
    }
}

void setup() {
    initializeTouchControl();
    initializeValueCollector();
    printf("Setup erfolgreich!\n");
}
