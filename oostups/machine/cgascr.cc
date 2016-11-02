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

	}
	void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
		int offset = (x + y * 80) * 2;
		char* posChar = CGA_START + offset;
		char* posAttr = CGA_START + offset + 1;
		*posChar = c;
		*posAttr = attrib;
		scr_buffer[x+y*80]= c;//
	}

	void CGA_Screen::setpos(int x, int y) {
		int offset = x+y*80;
		unsigned char low = (unsigned char) offset;
		unsigned char high = (unsigned char) (offset<<8);
		//cursor low
		ctrl_port.outw(15);
		data_port.outw(low);

		//cursor high
		ctrl_port.outw(14);
		data_port.outw(high);
	}

	void CGA_Screen::getpos(int &x, int &y) {
		//cursor low
		ctrl_port.outw(15);
		int low = data_port.inw();

		//cursor high
		ctrl_port.outw(14);
		int high = data_port.inw();
		high = high>>8;

		int offset = low | high;
		x = offset%80;
		y = offset%80;
	}



	void CGA_Screen::print(char* text, int length, unsigned char attrib) {
		int i;
		int x,y;
		getpos(x,y);
		for (i = 0;i < length; i++){
			if (text[i]=='\n'){
				x=0;
				show(x++,++y,text[i],attrib);
			}
			if(x<80){
				show(x++,y,text[i],attrib);
			}else{
				if(y<25){
					x=0;
					show(x++,++y,text[i],attrib);
				}else{
					setpos(0,0);
					x=0;
					y=0;
					char *p = scr_buffer;
					p = p + 25;
					print(p,24*80,attrib);
				}
			}

		}
		setpos(x,y);
	}
