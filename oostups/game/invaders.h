/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __Invaders_include__
#define __Invaders_include__

#include "syscall/thread.h"
#include "syscall/guarded_organizer.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_buzzer.h"
#include "user/debug.h"
#include "game/input_thread.h"
#include "game/entity.h"
#include "game/player.h"
#include "object/list.h"
#include "game/domain.h"

class Invaders : public Thread
 {
private:
    Invaders (const Invaders &copy); // Verhindere Kopieren
	Guarded_Buzzer buzzer;
	Domain domain;

	void initializeGame();
	void updateDomain();
	void renderDomain();

public:
	Invaders(void* tos);
    void action ();
 };
#endif
