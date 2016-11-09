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

class Application 
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren

public:                
	int output_num;

	Application();

    void action ();

 };
extern Application app;

#endif
