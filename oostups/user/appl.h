/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "thread/coroutine.h"

class Application : public Coroutine
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
    

public:                
	int output_num;
    int id, x,y;
    Application *next;

	Application(void* tos, int id, int x, int y);
    void action ();

 };

#endif
