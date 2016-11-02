#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

class CGA_Screen
 {
private:
	
	char scr_buffer[25*80];
	void getline(char* arr, int linenumber);
	void printline(int linenumber, char* line);

	CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
public:
	CGA_Screen();
	void shiftline();
	void show(int x, int y, char c, unsigned char attrib);

	void setpos(int x, int y);

	void getpos(int &x, int &y);

	void print(char* text, int length, unsigned char attrib);

 };

#endif

