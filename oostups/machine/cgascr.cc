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


//25 * 80 größe

#include "machine/cgascr.h"

	char* CGA_START = (char*)0xb8000;
	CGA_Screen::CGA_Screen():ctrl_port (0x3d4), data_port (0x3d5){

	}
	void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
		int offset = (x + y * 80) * 2;
		char* posChar = CGA_START + offset;
		char* posAttr = CGA_START + offset + 1;
		*posChar = c;
		*posAttr = attrib;
		scr_buffer[x+(y*80)] = c;
		scr_attr_buffer[x+(y*80)] = attrib;
	}

	void CGA_Screen::setpos(int x, int y) {
		int offset = x+y*80;
		unsigned char low = (unsigned char) offset;
		unsigned char high = (unsigned char) (offset >> 8);
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

	void CGA_Screen::shiftline() {
		for( int linenumber = 1 ; linenumber < 26 ; linenumber++) {
			char line[80];
			char attrs[80];
			getline(line, attrs, linenumber);
			printline(line,attrs,linenumber-1);
		}

		//Fill last line with empty spaces
		char emptyline[80];
		char emptyattrs[80];
		for( int i = 0 ; i < 80 ; i++) {
			emptyline[i] = ' ';
			emptyattrs[i] = 0x0f;
		}
		printline(emptyline,emptyattrs,25);
	}

	void CGA_Screen::getline(char* arr, char* attr_arr, int linenumber) {
		for(int i = 0; i < 80 ; i++) {
			arr[i] = scr_buffer[i + (linenumber * 80)]; 
			attr_arr[i] = scr_attr_buffer[i + (linenumber * 80)]; 
		}
	}

	void CGA_Screen::printline(char* line, char* attrs, int linenumber) {
		for( int i = 0; i < 80 ; i++) {
			show(i, linenumber, line[i], attrs[i]);
		}
	}

	void CGA_Screen::calcpos(int &x, int &y) {
		if( x+1 == 80 ) {
			y = y + 1;
		}

		x = (x+1)%80;

		show(70,2,y,0x0f);

		if(y == 26) {
			shiftline();
			y = 25;
		}
	}

	void CGA_Screen::print(char* text, int length, unsigned char attrib) {
		int x,y;
		getpos(x,y);
		for( int i = 0; i < length ; i++) {

			if(*(text+i) == '\n') {
				y = y + 1;
				x = 0;
				calcpos(x,y);
				continue;
			}

			show(x,y,*(text+i),attrib);
			calcpos(x,y);

		}
		setpos(x,y);
	}
