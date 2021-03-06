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
#include "game/input_thread.h"
#include "game/domain.h"
#include "game/gp_over.h"
#include "game/gp_flash.h"

class Invaders : public Thread
 {
private:
    Invaders (const Invaders &copy); // Verhindere Kopieren
	Guarded_Buzzer buzzer;
	GamePhase* curPhase;
	
	void updateGamePhase();
	void renderGamePhase();

public:
	Domain domain;
	FlashAnimation flashAnim;
	GameOver gameOver;

	Invaders(void* tos);
    void action ();
	void initializeGame();
	void setPhase(GamePhase* phase);
 };
extern Invaders appInv;
#endif
