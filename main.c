/*============================;
 *
 * File: main.c
 * Content: Main source file for alarm clock
 * using the AVR128DB28 microcontroller.
 * Some hardware will be used for display and
 * audio output.
 * Date: 22/2/2026
 *
 *********************************/

// Blinking led to start.
// Use PORTA pin 0 as the output pin of the output waveform
int main()
{
	CPU.CCP = CPU_CCP_IOREG_gc; // wriet to Configuration Change Protection
				    // to be able to write to CLKCTRL.MCLKCTRLA
	CLKCTRL.MCLKCTRLA = 1; // Set the CLK_MAIN to internal 32k oscillator
	                       // disable CLK_MAIN on output pin
	CPU.CCP = CPU_CCP_IOREG_gc; // write to Configuration Change Protection
                                    // to be able to write to CLKCTRL.MCLKCTRLB
				     
        CLKCTRL.MCLKCTRLB = 0; // Prescaler to obtain CLK_PER and CLK_CPU from
			       // CLK_MAIN is disabled and therefore is 1.
			       // CLK_PER and CLK_CPU are CLK_MAIN
	TCA0.CMP0L = 255; 
        TCA0.CMP0H = 127; // set the CMP0 value that gets compared to the
                          // TCA0 timer
	TAC0.CTRLECLR = 2; // no command, count upwards, do not update CMP0
                           // when the timer updates (goes back to 0) 	
	PORTA.DIRSET = 1; // Enable output driver of PORTA pin 0
	TCA0.CTRLB = 17; // set waveform generation of PA0, and set the type
                         // of waveform

	TCA0.CTRLA = 129; // freq of TCA0 is equal to CLK_PER and TCA0 is 
			  // enabled in standby sleep mode	
	while (1) {

	}
}
