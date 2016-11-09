/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/
#include "machine/pic.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/cgastr.h"

PIC::PIC():mocw(0x21), socw(0xa1){
}

void PIC::allow (int interrupt_device){
	//kout << "allow interrupt" << endl;
	if(interrupt_device == PIC::timer){
		int tmp = mocw.inb();
		tmp = tmp & 0b11111110;
		mocw.outb(tmp);
		socw.outb(tmp);
	}else if(interrupt_device == PIC::keyboard){
		int tmp = mocw.inb();
		tmp = tmp & 0b11111101;
		mocw.outb(tmp);
		socw.outb(tmp);
	}
}


void PIC::forbid (int interrupt_device){
	if(interrupt_device == PIC::timer){
			int tmp = mocw.inb();
			tmp = tmp | 0b00000001;
			mocw.outb(tmp);
			socw.outb(tmp);
		}else if(interrupt_device == PIC::keyboard){
			int tmp = mocw.inb();
			tmp = tmp | 0b00000010;
			mocw.outb(tmp);
			socw.outb(tmp);
		}
}

PIC pic;
