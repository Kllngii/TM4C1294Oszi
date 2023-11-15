/*
 * Name: Lasse Kelling
 * Matrikelnummer: 2590639
 * Datum: 26.10.2023
 *
 * TouchControl
 * stellt Funktionen zum Umgang mit dem Touchdisplay zur Verfügung
 *
 * Unter (Properties -> Resource) encoding UTF-8 und line delimitor Unix auswählen!
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <inc/hw_types.h>
#include <inc/tm4c1294ncpdt.h>
#include <driverlib/gpio.h>
#include <driverlib/pin_map.h>
#include <driverlib/sysctl.h>
#include <inc/hw_memmap.h>

#define WAIT_1MS SysCtlDelay(10000) //~1ms warten
#define WAIT_12MS SysCtlDelay(120000) //Mehr als 10ms warten

#define MAX_X 800
#define MAX_Y 480

#define RST 0x10
#define INITIAL_STATE (0x1F)
#define SOFTWARE_RESET (0x01)
#define SET_PLL_MN (0xE2)
#define START_PLL (0xE0)
#define LOCK_PLL (0xE0)  // same as START_PLL
#define SET_PIXEL_CLOCK_FREQ (0xE6)
#define SET_LCD_MODE (0xB0)
#define SET_HORI_PERIOD (0xB4)
#define SET_VERT_PERIOD (0xB6)
#define SET_ADRESS_MODE (0x36)
#define SET_PIXEL_DATA_FORMAT (0xF0)
#define SET_DISPLAY_ON (0x29)
#define SET_DISPLAY_OFF (0x29)

#define FONT_WIDTH 5
#define FONT_HEIGHT 7

enum Colors {
	BLACK = 0x000000,
	WHITE = 0xffffff,
	//TODO mehr Farben hinzufügen
};

// *** Nach dem Beispiel V0.1-V0.4 K.R. Riemschneider .. 1-4 Oct 2020 ***
inline void write_command(unsigned char command) {
	GPIO_PORTM_DATA_R = command;        // Write command byte
	GPIO_PORTL_DATA_R = 0x11;           // Chip select = 0, Command mode select = 0, Write state = 0
	GPIO_PORTL_DATA_R = INITIAL_STATE;           // Initial state
}
inline void write_data(unsigned char data) {
	GPIO_PORTM_DATA_R = data;           // Write data byte
	GPIO_PORTL_DATA_R = 0x15;           // Chip select = 0, Write state = 0
	GPIO_PORTL_DATA_R = INITIAL_STATE;           // Initial state
}
inline void window_set(uint16_t min_x, uint16_t min_y, uint16_t max_x, uint16_t max_y) {
	write_command(0x2A);           // Set row address x-axis
	write_data(min_x >> 8);        // Set start  address           (high byte)
	write_data(min_x);             // as above                     (low byte)
	write_data(max_x >> 8);        // Set stop address             (high byte)
	write_data(max_x);             // as above                     (low byte)
	write_command(0x2B);           // Set column address (y-axis)
	write_data(min_y >> 8);        // Set start column address     (high byte)
	write_data(min_y);             // as above                     (low byte)
	write_data(max_y >> 8);        // Set stop column address      (high byte)
	write_data(max_y);             // as above                     (low byte)
}
inline void softwareReset() {
	write_command(SOFTWARE_RESET);
	WAIT_12MS;
}
inline void setPixel(uint16_t x, uint16_t y, uint32_t color) {
	window_set(x, y, x, y);
	write_command(0x2C);
	write_data((color>>16)&0xff);   //R
	write_data((color>>8)&0xff);    //G
	write_data((color)&0xff);       //B
}

uint8_t initializeTouchControl();

void fillRect(uint16_t, uint16_t, uint16_t, uint16_t, uint32_t);

void drawChar(uint16_t x, uint16_t y, char c, uint32_t color);
void drawTitleChar(uint16_t x, uint16_t y, char c, uint32_t color);
void drawString(uint16_t x, uint16_t y, const char *str, uint32_t color);
void drawTitleString(uint16_t x, uint16_t y, const char *str, uint32_t color);
