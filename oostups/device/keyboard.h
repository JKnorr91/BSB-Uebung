/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_semaphore.h"
 

class Keyboard : public Gate, public Keyboard_Controller
{        
private:
      Keyboard (const Keyboard &copy); // Verhindere Kopieren
      Key key;
public:
	Keyboard ();
	void plugin ();
	bool prologue ();
	void epilogue ();
	Key getkey();
        
 };
extern Guarded_Semaphore keysem;

#endif
