/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ iO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

class O_Stream : public Stringbuffer
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
	O_Stream(const O_Stream &copy); // Verhindere Kopieren
	// Must be either of BIN, OCT, DEC or HEX
	unsigned char number_base;

	// The maximum number of digits the string for a given number can have
	static const int DIGIT_BUFFER_SIZE = 64;
	// Used to buffer the digits of a number turned to string before being written out
	char digit_buffer[DIGIT_BUFFER_SIZE];
	// the number of digits currently written to the digit_buffer
	unsigned char digit_count;
	// Adds a char to the digit_buffer and increments digit_count by one.
	// If the buffer is full nothing will be done
	void putDigit(char digitAsChar);
	// Outputs the digit_buffer to the main buffer in reverse order.
	// Sets digit_count to 0 but does not null the digit_buffer.
	void flushDigitBuffer();

	// returns a char based on the current number_base.
	// uses the values from the various XX_digit_to_char_tables.
	char toChar(unsigned char digit);
	// puts the prefix of the current number_base (either 0b, 0x, 0o or the empty string)
	void putBasePrefix();

public:
	// these are the different number bases.
	enum { BIN = 2, OCT = 8, DEC = 10, HEX = 16 };

	static char bin_digit_to_char_table[];
	static char oct_digit_to_char_table[];
	static char dec_digit_to_char_table[];
	static char hex_digit_to_char_table[];
	static char prefix_bin[];
	static char prefix_oct[];
	static char prefix_dec[];
	static char prefix_hex[];
	static char negative_sign;
	static char newline_char;

	O_Stream();

	void setBase(unsigned char value);
	unsigned char getBase();

	O_Stream& operator<< (unsigned char c);
 	O_Stream& operator<< (char c);

	O_Stream& operator<< (unsigned short number);
	O_Stream& operator<< (short number);
	O_Stream& operator<< (unsigned int number);
	O_Stream& operator<< (int number);
	O_Stream& operator<< (unsigned long number);
	O_Stream& operator<< (long number);

	O_Stream& operator<< (void* pointer);

	O_Stream& operator<< (char* text);
	O_Stream& operator<< (O_Stream& (*fkt) (O_Stream&));
 };

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          M A N I P U L A T O R E N                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die folgenden Funktionen erhalten und liefern jeweils eine Referenz auf   */
/* ein O_Stream Objekt. Da die Klasse O_Stream einen Operator << fuer        */
/* derartige Funktionen definiert, koennen sie mit Hilfe dieses Operators    */
/* aufgerufen und sogar in weitere Eingaben eingebettet werden.              */
/* Aufgabe der Manipulatoren ist, die Darstellung der nachfolgenden Ausgaben */
/* zu beeinflussen, z.B durch die Wahl des Zahlensystems.                    */
/*---------------------------------------------------------------------------*/
	O_Stream& endl (O_Stream& os);
	O_Stream& bin (O_Stream& os);
	O_Stream& oct (O_Stream& os);
	O_Stream& dec (O_Stream& os);
	O_Stream& hex (O_Stream& os);
	O_Stream& el (O_Stream& os);
#endif

