/*
 * Name: Lasse Kelling
 * Matrikelnummer: 2590639
 * Datum: 26.10.2023
 *
 * ValueCollector
 * holt sich zyklisch die Sensordaten und bereitet diese auf
 *
 * Unter (Properties -> Resource) encoding UTF-8 und line delimitor Unix auswählen!
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <driverlib/gpio.h>
#include <driverlib/pin_map.h>
#include <driverlib/sysctl.h>
#include <driverlib/adc.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c1294ncpdt.h>

uint8_t initializeValueCollector();

void processSample(void);

void sample(uint32_t*);

