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
uint8_t initializeValueCollector() {
    //ADC Takt erzeugen
    SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));

    GPIOPinTypeADC(GPIO_PORTC_BASE, GPIO_PIN_4);
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 3);
    ADCIntClear(ADC0_BASE, 3);

    printf("ValueCollector Setup erfolgreich!\n");
    return 0;
}

void sample(uint32_t* adcBuffer) {
    ADCProcessorTrigger(ADC0_BASE, 3);
    while(!ADCIntStatus(ADC0_BASE, 3, false));
    ADCIntClear(ADC0_BASE, 3);
    ADCSequenceDataGet(ADC0_BASE, 3, adcBuffer);
}
