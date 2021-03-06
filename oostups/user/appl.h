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

#include "syscall/thread.h"
#include "syscall/guarded_organizer.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_buzzer.h"

class Application : public Thread
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
    Guarded_Buzzer buzzer;

public:                
	int output_num;
    int x,y;
    Application* nextApp;

	Application(void* tos, int id, int x, int y);
    void action ();

 };
#endif
