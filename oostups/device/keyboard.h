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
 
<<<<<<< c9f508a56fed692461fccc785bc4bf5a4fe025e2
class Keyboard : public Gate     
=======
class Keyboard : public Gate, public Keyboard_Controller
/* Hier muesst ihr selbst Code vervollstaendigen */         
>>>>>>> d5380651a08ab86aa58c5d5d512d88cae1f0f626
{        
private:
      Keyboard (const Keyboard &copy); // Verhindere Kopieren
      Key key;               
         
public:
      Keyboard ();
      void plugin ();
      void trigger ();

        
 };
extern Keyboard keyboard;

#endif
