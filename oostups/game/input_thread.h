/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __InputThread_include__
#define __InputThread_include__

#include "syscall/thread.h"
#include "syscall/guarded_organizer.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_buzzer.h"
#include "user/debug.h"
#include "game/gameKey.h"

class InputThread : public Thread
 {
private:
    InputThread (const InputThread &copy); // Verhindere Kopieren

public:
	InputThread(void* tos);
    void action ();

	Key keyNow;
	bool keyValid;
 };
#endif
