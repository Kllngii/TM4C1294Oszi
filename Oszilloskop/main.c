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
	fillRect(0, 0, MAX_X, MAX_Y+1, 0x000000);
	fillRect(0, 0, 200, 200, 0x0000ff);
	fillRect(200, 0, 400, 200, 0x00ffff);
	fillRect(400, 0, 600, 200, 0x00ff00);
	fillRect(600, 0, 800, 200, 0xffff00);

	drawString(0, 240, "0123456789", 0xff0000);
	drawString(0, 260, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0xff0000);
	drawString(0, 280, "abcdefghijklmnopqrstuvwxyz", 0xff0000);

	drawTitleString(0, 300, "0123456789", 0xff0000);
	drawTitleString(0, 320, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0xff0000);
	drawTitleString(0, 340, "abcdefghijklmnopqrstuvwxyz", 0xff0000);

	uint32_t iterations = 800000;

	//fillRect(200, 300, 300, 400, 0xff00ff);
	while(1) {
		//
		//sample(adcBuffer);
//		printf("Sample erhalten: %4d\n", adcBuffer[0]);
		// Aktives Warten (Busy Waiting)
		for (uint32_t i = 0; i < iterations; ++i) {
			// Keine Operation (NOP)
		}
		printf("isBusy = %d\n", ADCBusy(ADC0_BASE));
	}
}

void setup() {
	initializeTouchControl();
	initializeValueCollector();
	printf("Setup erfolgreich!\n");
}
