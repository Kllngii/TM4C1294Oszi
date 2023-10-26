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

#include "valueCollector.h"

/**
 * @short PC4-PC7 als Input setzen und mit ADC verbinden
 * @return 0 wenn alles erfolgreich
 */
int initialize() {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
    return 0;
}
