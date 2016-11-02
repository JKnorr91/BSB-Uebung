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
	
	char scr_buffer[26*80];
	const IO_Port ctrl_port; // Status- (R) u. Steuerregister (W)
	const IO_Port data_port; // Ausgabe- (R) u. Eingabepuffer (W)


	CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
public:
	CGA_Screen();
	void show(int x, int y, char c, unsigned char attrib);

	void setpos(int x, int y);

	void getpos(int &x, int &y);

	void print(char* text, int length, unsigned char attrib);

 };

#endif

