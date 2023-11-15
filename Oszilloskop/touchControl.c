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

#include "touchControl.h"


const char font[][FONT_WIDTH] = {
	{0x3E, 0x41, 0x41, 0x41, 0x3E}, // 0
	{0x04, 0x02, 0x7F, 0x00, 0x00}, // 1
	{0x62, 0x51, 0x49, 0x49, 0x46}, // 2
	{0x22, 0x41, 0x49, 0x49, 0x36}, // 3
	{0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
	{0x2F, 0x49, 0x49, 0x49, 0x31}, // 5
	{0x3E, 0x49, 0x49, 0x49, 0x30}, // 6
	{0x01, 0x01, 0x79, 0x05, 0x03}, // 7
	{0x36, 0x49, 0x49, 0x49, 0x36}, // 8
	{0x06, 0x49, 0x49, 0x49, 0x3E}, // 9
	{0x7E, 0x09, 0x09, 0x09, 0x7E}, // A
	{0x7F, 0x49, 0x49, 0x49, 0x36}, // B
	{0x3E, 0x41, 0x41, 0x41, 0x22}, // C
	{0x7F, 0x41, 0x41, 0x22, 0x1C}, // D
	{0x7F, 0x49, 0x49, 0x49, 0x41}, // E
	{0x7F, 0x09, 0x09, 0x09, 0x01}, // F
	{0x3E, 0x41, 0x49, 0x49, 0x7A}, // G
	{0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
	{0x00, 0x41, 0x7F, 0x41, 0x00}, // I
	{0x20, 0x40, 0x41, 0x3F, 0x01}, // J
	{0x7F, 0x08, 0x14, 0x22, 0x41}, // K
	{0x7F, 0x40, 0x40, 0x40, 0x40}, // L
	{0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
	{0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
	{0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
	{0x7F, 0x09, 0x09, 0x09, 0x06}, // P
	{0x1E, 0x21, 0x21, 0x21, 0x5E}, // Q
	{0x7F, 0x09, 0x09, 0x09, 0x76}, // R
	{0x26, 0x49, 0x49, 0x49, 0x32}, // S
	{0x01, 0x01, 0x7F, 0x01, 0x01}, // T
	{0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
	{0x0F, 0x30, 0x40, 0x30, 0x0F}, // V
	{0x7F, 0x20, 0x10, 0x20, 0x7F}, // W
	{0x63, 0x14, 0x08, 0x14, 0x63}, // X
	{0x03, 0x04, 0x78, 0x04, 0x03}, // Y
	{0x61, 0x51, 0x49, 0x45, 0x43}, // Z
	{0x3C, 0x42, 0x42, 0x42, 0x3C}, // a //TODO neu machen
	{0x7F, 0x48, 0x48, 0x48, 0x30}, // b
	{0x3C, 0x42, 0x42, 0x42, 0x24}, // c
	{0x30, 0x48, 0x48, 0x48, 0x7F}, // d
	{0x38, 0x54, 0x54, 0x54, 0x08}, // e
	{0x3C, 0x4A, 0x4A, 0x4A, 0x24}, // f //TODO neu machen
	{0x18, 0xA4, 0xA4, 0xA4, 0x7C}, // g //TODO neu machen
	{0x7F, 0x08, 0x08, 0x08, 0x70}, // h
	{0x00, 0x44, 0x7D, 0x40, 0x00}, // i
	{0x20, 0x40, 0x44, 0x3D, 0x00}, // j
	{0x7F, 0x10, 0x28, 0x44, 0x00}, // k
	{0x00, 0x41, 0x7F, 0x40, 0x00}, // l
	{0x7C, 0x04, 0x78, 0x04, 0x78}, // m
	{0x7C, 0x08, 0x04, 0x04, 0x78}, // n
	{0x38, 0x44, 0x44, 0x44, 0x38}, // o
	{0xFC, 0x24, 0x24, 0x24, 0x18}, // p //TODO neu machen
	{0x18, 0x24, 0x24, 0x24, 0xFC}, // q //TODO neu machen
	{0x7C, 0x08, 0x04, 0x04, 0x08}, // r
	{0x48, 0x54, 0x54, 0x54, 0x20}, // s
	{0x04, 0x3F, 0x44, 0x40, 0x20}, // t
	{0x3C, 0x40, 0x40, 0x20, 0x7C}, // u
	{0x1C, 0x20, 0x40, 0x20, 0x1C}, // v
	{0x3C, 0x40, 0x30, 0x40, 0x3C}, // w
	{0x44, 0x28, 0x10, 0x28, 0x44}, // x
	{0x1C, 0xA0, 0xA0, 0xA0, 0x7C}, // y //TODO neu machen
	{0x44, 0x64, 0x54, 0x4C, 0x44}, // z
    {0x00, 0x00, 0x00, 0x00, 0x00},  // Leerzeichen
	{0x00, 0x36, 0x36, 0x00, 0x00}, // :
	//TODO : und weitere Zeichen einbinden
};

/**
 * @short Initialisiert das Touchdisplay
 * @return 0 wenn alles erfolgreich
 */
uint8_t initializeTouchControl() {
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM));
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, 0xFF);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL));
	GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3| GPIO_PIN_4);

	GPIO_PORTL_DATA_R = INITIAL_STATE;
	GPIO_PORTL_DATA_R &= ~RST; // Hardware reset
	WAIT_1MS;
	GPIO_PORTL_DATA_R |= RST;
	SysCtlDelay(12000); // wait >1 ms

	softwareReset();

	write_command(SET_PLL_MN); // Set PLL Freq to 120 MHz
	write_data(0x24);
	write_data(0x02);
	write_data(0x04);

	write_command(START_PLL);
	write_data(0x01);
	WAIT_1MS;

	write_command(LOCK_PLL);
	write_data(0x03);
	WAIT_1MS;

	softwareReset();

	write_command(SET_PIXEL_CLOCK_FREQ);
	write_data(0x01); // KRR Set LCD Pixel Clock 9MHz
	write_data(0x70);
	write_data(0xA3);

	write_command(SET_LCD_MODE); // SET LCD MODE SIZE, manual p. 44
	write_data(0x20); // ..TFT panel 24bit
	write_data(0x00); // ..TFT mode
	write_data(0x03); // SET horizontal size = 800-1 (high byte)
	write_data(0x1F); // SET horizontal size = 800-1 (low byte)
	write_data(0x01); // Set vertical size = 480-1 (high byte)
	write_data(0xDF); // Set vertical size = 480-1 (low byte)
	write_data(0x00); // Even line RGB sequence / Odd line RGB sequence

	write_command(SET_HORI_PERIOD);       // Set Horizontal Period
	write_data(0x03);                     // Horizontal total period (display + non-displayed)  (high byte)
	write_data(0x5E);                     // Horizontal total period (display + non-display) (low byte)
	write_data(0x00);                     // Non-displayed period between the start of the horizontal sync (LLINE) signal and the first displayed data.
	write_data(0x46);                     // Low byte of the non-display period between the start of the horizontal sync (LLINE) signal and the first display data
	write_data(0x09);                     // Set the vertical sync width
	write_data(0x00);                     // Set horiz.Sync pulse start    (high byte)
	write_data(0x08);                     // Set horiz.Sync pulse start    (low byte)
	write_data(0x00);                     //

	write_command(SET_VERT_PERIOD);         // Set vertical periods, manual  p. 49
	write_data(0x01);                       // Vertical total period (display + non-displayed) in lines (high byte)
	write_data(0xFE);                       // as above (low byte) = total 510  lines
	write_data(0x00);                       //
	write_data(0x0C);                       // The non-displayed period in lines between the start of the frame and the first
	// display data = 12 line.s
	write_data(0x0A);                       // Set the vertiacla sync width = 10 pixels
	write_data(0x00);                       // Set vertical sync pulse start position (high byte)
	write_data(0x04);                       // as above (low byte) = total sync pulse start position is 4 lines

	write_command(SET_ADRESS_MODE);         // Pixel address counting = flip display , manual p. 36
	write_data(0x03);                       // necessary to match with touch screen addressing

	//  write_command(0x0A);                    // Power control mode not tested in detail
	//  write_data(0x1C);

	write_command(SET_PIXEL_DATA_FORMAT);    // set pixel data format 8bit manual p. 78
	write_data(0x00);

	write_command(SET_DISPLAY_ON);

	printf("TouchControl Setup erfolgreich!\n");
	return 0;
}

void fillRect(uint16_t minX, uint16_t minY, uint16_t maxX, uint16_t maxY, uint32_t color) {
	uint16_t x, y;
	//FIXME maxX darf nie größer als MAX_X sein...
	window_set(minX, minY, maxX, maxY);
	write_command(0x2C);

	for (x=minX; x<=maxX-1; x++) {
		for (y=minY; y<=maxY-1; y++) {
			write_data((color>>16)&0xff);   //R
			write_data((color>>8)&0xff);    //G
			write_data((color)&0xff);       //B
		}
	}
}

void drawChar(uint16_t x, uint16_t y, char c, uint32_t color) {
	if (c >= '0' && c <= '9') { //Ziffern (10)
		c = c - '0';
	} else if (c >= 'A' && c <= 'Z') { //Großbuchstaben (26)
		c = c - 'A' + 10;
	} else if (c >= 'a' && c <= 'z') { //Kleinbuchstaben (26)
		c = c - 'a' + 36;
	} else { //Leerzeichen als Fallback
		c = 62;
	}

	for (int i = 0; i < FONT_WIDTH; ++i) {
		for (int j = 0; j < FONT_HEIGHT; ++j) {
			if (font[c][i] & (1 << j)) {
				setPixel(x + i, y + j, color);
			}
		}
	}
}

void drawTitleChar(uint16_t x, uint16_t y, char c, uint32_t color) {
	if (c >= '0' && c <= '9') { //Ziffern (10)
		c = c - '0';
	} else if (c >= 'A' && c <= 'Z') { //Großbuchstaben (26)
		c = c - 'A' + 10;
	} else { //Leerzeichen als Fallback
		c = 62;
	}

	for (int i = 0; i < FONT_WIDTH; ++i) {
		for (int j = 0; j < FONT_HEIGHT; ++j) {
			if (font[c][i] & (1 << j)) {
				fillRect(x + i*2, y + j*2, x + i*2 + 1, y + j*2 + 1, color);
			}
		}
	}
}

void drawString(uint16_t x, uint16_t y, const char *str, uint32_t color) {
    for (int i = 0; str[i] != '\0'; ++i) {
        drawChar(x + i * (FONT_WIDTH + 1), y, str[i], color);
    }
}

void drawTitleString(uint16_t x, uint16_t y, const char *str, uint32_t color) {
    for (int i = 0; str[i] != '\0'; ++i) {
        drawTitleChar(x + i * (FONT_WIDTH*2 + 1), y, str[i], color);
    }
}
