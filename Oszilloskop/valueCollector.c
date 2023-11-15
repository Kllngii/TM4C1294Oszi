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
 * Dem Tivaware Datenblatt (S. 23ff) zufolge:
 * - Takt an Periphere geben
 * - GPIO Pins konfigurieren
 * - Sample Sequencer Setup
 * - ADC Interrupt Setup
 *
 * @short PC4 bis PC7 als ADC Input konfigurieren
 *
 * @return 0 wenn alles erfolgreich
 */
uint8_t initializeValueCollector() {
	const int PIN4_SAMPLE_SEQUENCER = 3;

	//Takt an benötigte Peripherie geben
	SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	ADCClockConfigSet(ADC0_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1); //Samplefrequenz von PIOSC * FULL / 1 -> 16MHz (* 1/1)

	//GPIO Pins setzen & SampleSequencer Setup
	GPIOPinTypeADC(GPIO_PORTC_BASE, GPIO_PIN_4);
	ADCSequenceConfigure(ADC0_BASE, PIN4_SAMPLE_SEQUENCER, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, PIN4_SAMPLE_SEQUENCER, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);
	ADCSequenceEnable(ADC0_BASE, PIN4_SAMPLE_SEQUENCER);

	//ADC Interrupt Setup
	ADCIntRegister(ADC0_BASE, PIN4_SAMPLE_SEQUENCER, processSample);
	ADCIntClear(ADC0_BASE, PIN4_SAMPLE_SEQUENCER); //Sicherheitshalber INT Flag löschen...
	ADCIntEnable(ADC0_BASE, PIN4_SAMPLE_SEQUENCER);

//
//	GPIO_PORTC_AHB_DIR_R &= ~0xF0;   // Eingang für C4, C5, C6, C7
//	GPIO_PORTC_AHB_AFSEL_R |= 0xF0;  // Alternative Funktion (ADC)
//	GPIO_PORTC_AHB_DEN_R &= ~0xF0;   // Digital Input Disable
//	GPIO_PORTC_AHB_AMSEL_R |= 0xF0;  // Analog Mode Enable

	printf("ValueCollector Setup erfolgreich!\n");
	return 0;
}

void processSample(void) {
	printf("Sample\n");
	ADCIntClear(ADC0_BASE, 3);
}

void sample(uint32_t* adcBuffer) {
	ADCProcessorTrigger(ADC0_BASE, 3);
	while(!ADCIntStatus(ADC0_BASE, 3, false));
	ADCIntClear(ADC0_BASE, 3);
	ADCSequenceDataGet(ADC0_BASE, 3, adcBuffer);

	printf("Sample erhalten: %4d\n", adcBuffer[0]);
}

