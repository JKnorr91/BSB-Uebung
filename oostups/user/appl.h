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

#include "thread/entrant.h"
#include "thread/scheduler.h"

class Application : public Entrant
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
    

public:                
	int output_num;
    int id, x,y;
    Application* nextApp;

	Application(void* tos, int id, int x, int y);
    void action ();

 };

#endif
