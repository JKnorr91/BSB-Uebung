/* $Id: cgascr.cc 5834 2013-10-08 17:04:08Z os $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

	char* CGA_START = (char*)0xb8000;


	CGA_Screen::CGA_Screen():ctrl_port (0x3d4), data_port (0x3d5)
	{
		int i;
		for (i = 0; i < 26 * 80; i++){
			atr_buffer[i] = 0x0f;
		}
		for (i = 0; i < 26 * 80; i++){
			scr_buffer[i] = ' ';
		}
	}
	void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
		int offset = (x + y * 80) * 2;
		char* posChar = CGA_START + offset;
		char* posAttr = CGA_START + offset + 1;
		*posChar = c;
		*posAttr = attrib;
		scr_buffer[x+y*80]= c;
		atr_buffer[x+y*80]=attrib;
	}

	void CGA_Screen::setpos(int x, int y) {
		int offset = x+y*80;
		unsigned char low = (unsigned char) offset;
		unsigned char high = (unsigned char) (offset >> 8);

		//cursor high
		ctrl_port.outb(14);
		data_port.outb(0xff);

		//cursor low
		ctrl_port.outb(15);
		data_port.outb(low);

		//cursor high
		ctrl_port.outb(14);
		data_port.outb(high);
	}

	void CGA_Screen::getpos(int &x, int &y) {
		ctrl_port.outb(14);
		int offset = data_port.inb() << 8;

		//cursor low
		ctrl_port.outb(15);
		offset |= data_port.inb();

		x = offset%80;
		y = offset/80;
	}

	void CGA_Screen::reprint(){
		int i;
		int length = 25 * 80;
		int x = 0;
		int y = 0;
		char *p = scr_buffer;
		unsigned char *a = atr_buffer;
		p = p + 80;
		a = a + 80;
		for (i = 0; i < length; i++){
			if (x < 80){
				show(x++,y,*(p+i),*(a+i));
			}else{
				x=0;
				y++;
				show(x++,y,*(p+i),*(a+i));
			}
		}
	}

	void CGA_Screen::print(char* text, int length, unsigned char attrib) {
		int i;
		int x,y;
		getpos(x,y);
		
		for (i = 0; i < length; i++){
			if (text[i] == '\n'){
				show(x, y, ' ', attrib);
				x = 0;
				y++;
				if (y >= 25) {
					reprint();
					y = 24;
				}
			} else {
				//debug.out(6, 12, text);
				show(x++, y, text[i], attrib);
				if (x == 80) {
					x = 0;
					y++;
					if (y >= 25) {
						reprint();
						y = 24;
					}
				}
			}
		}
		setpos(x,y);
	}
