/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "machine/pit.h"

void PIT::interval(int us) {

    //convert into us
    us = (us * 1.19) + 0.5;

    /*6-7	Zählerauswahl
            00 	Zähler 0
            01 	Zähler 1
            10 	Zähler 2
            11 	ungültig beim 8253, Read-Back-Befehl beim 8254

        4-5	Lesen/Schreiben
            00 	Zähler-Latch-Befehl
            01 	nur niederwertiges Zählerbyte
            10 	nur höherwertiges Zählerbyte
            11 	niederwertiges, anschließend höherwertiges Zählerbyte

        1-3	Modus 0 bis Modus 5
            000 	Einmalige Unterbrechung
            001 	Einmalige Unterbrechung mit Hardwaresteuerung
            010 	Periodische Unterbrechungen
            011 	Rechtecksignalgenerator
            100 	Softwaregesteuerte Unterbrechung
            101 	Hardwaregesteuerte Unterbrechung
            
        0 	Zählformat
            0 	binäre Zählung von 16 Bit
            1 	Zählung mit vierstelligen BCD Zahlen*/
    ctrlw.outb(0b00110100);

    char lower = (char) us;
    char higher = (char) (us>>8);

    currentInterval = us & 0x00ff;
    
    counter0w.outb(lower);
    counter0w.outb(higher);
}
