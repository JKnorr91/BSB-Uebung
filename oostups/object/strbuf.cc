/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Stringbuffer stellt einen Puffer fuer die Sammlung von Zeichen */
/* zur Darstellung auf dem Bildschirm oder anderen Ausgabegeraeten bereit.   */
/* Die Ausgabe der Zeichen erfolgt, sobald der Puffer voll ist oder wenn     */
/* explizit die Methode flush() aufgerufen wird.                             */
/* Da Stringbuffer geraeteunabhaengig sein soll, ist flush() eine virtuelle  */
/* Methode, die von den abgeleiteten Klassen definiert werden muss.          */
/*****************************************************************************/

#include "object/strbuf.h"

	Stringbuffer::Stringbuffer() {}

	void Stringbuffer::clear() {
		for (int i = 0; i < BUFFER_SIZE; i++) {
			str_buffer[i] = 0;
		}
		next_index = 0;
	}

	unsigned char Stringbuffer::size() {
		return next_index;
	}

	void Stringbuffer::put(char c) {
		if (next_index >= BUFFER_SIZE) {
			flush();
			clear();
		}
		str_buffer[next_index++] = c;
	}
