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

#ifndef __strbuf_include__
#define __strbuf_include__

#define BUFFER_SIZE 80

class Stringbuffer
 {
private:
      Stringbuffer(const Stringbuffer &copy); // Verhindere Kopieren

protected:
	char str_buffer[BUFFER_SIZE];
	unsigned char next_index;

	void clear();

public:
	Stringbuffer();

	unsigned char size();

	void put(char c);

	virtual void flush()=0;

 };

#endif
