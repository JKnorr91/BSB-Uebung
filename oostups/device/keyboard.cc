/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/
#include "device/keyboard.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
Keyboard::Keyboard(){}

void Keyboard::plugin (){
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger (){
	/*key = keyctl.key_hit();
	if(key.ctrl() && key.alt() && key.scancode() == Key::scan::del){
		keyctl.reboot();
	}else if (key.valid()){
		kout << key.ascii() << el;
	}*/
<<<<<<< Updated upstream
	kout << "Keyboard::trigger()" << el;
=======
	kout << "key hit"<<el;
>>>>>>> Stashed changes
}
