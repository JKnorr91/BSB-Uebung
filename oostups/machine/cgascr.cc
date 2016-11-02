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
	CGA_Screen::CGA_Screen(){

	}
	void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
		int offset = (x + y * 80) * 2;
		char* posChar = CGA_START + offset;
		char* posAttr = CGA_START + offset + 1;
		*posChar = c;
		*posAttr = attrib;
		scr_buffer[x+(y*80)] = c;
	}

	void CGA_Screen::setpos(int x, int y) {

	}

	void CGA_Screen::getpos(int &x, int &y) {
	
	}

	void CGA_Screen::shiftline() {
		for( int linenumber = 1 ; linenumber < 25 ; linenumber++) {
			char line[80];
			getline(line, linenumber);
			for(int i = 0; i < 80 ; i++) {
				show(i, linenumber-1, line[i], 0x0f);
			}
			//print(line,80,0x0f);
			//printline(i-1, line);
		}

		//char line[80];
		//print(line, 80, 0x0f);
	}

	void CGA_Screen::getline(char* arr, int linenumber) {
		for(int i = 0; i < 80 ; i++) {
			arr[i] = scr_buffer[i + (linenumber * 80)]; 
		}
	}

	void CGA_Screen::printline(int linenumber, char* line) {
		for( int i = 0; i < 80 ; i++) {
			show(i, linenumber, line[i], 0x0f);
		}
	}

	void CGA_Screen::print(char* text, int length, unsigned char attrib) {
		int x,y;
		getpos(x,y);
		for( int i = 0; i < length ; i++) {

			show(x+i,1,*(text+i),attrib);

			/*if( x+1 == 80 ) {
				y = y + 1;
			}

			x = (x+1)%80

			if(y == 25) {
				shiftLine();
			}*/

		}
		//setpos(x+1,y+1);
	}
