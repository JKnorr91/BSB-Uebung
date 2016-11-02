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



	void CGA_Screen::print(char* text, int length, unsigned char attrib) {
		int i;
		int x,y;
		getpos(x,y);
		for (i = 0;i < length; i++){
				//Platz in der Zeile verfügbar
				if(x<80){
					if (text[i]!='\n'){
						show(x++,y,text[i],attrib);
					//Sonderbehandlung \n
					}else{
						show(x++,y,' ',attrib);
						x=0;
						y++;
						if(y<24){
							show(x,y,' ',attrib);
						}else{
							setpos(0,0);
							char *p = scr_buffer;
							p = p + 80;
							print(p,25*80,attrib);
							x=0;
							y=24;
						}
					}
				//neue Zeile
				}else{
					if(y<24){
						x=0;
						y++;
						show(x++,y,text[i],attrib);
					//neue Seite
					}else{
						setpos(0,0);
						x=0;
						y=24;
						char *p = scr_buffer;
						p = p + 80;
						print(p,25*80,attrib);
						if(text[i]!='\n'){
							show(x++,y,text[i],attrib);
						}
					}
				}
		}
		setpos(x,y);
	}
