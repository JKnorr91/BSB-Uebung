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
	plugbox.assign(33,*this);
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger (){
	key = keyctl.key_hit();
	if(key.ctrl() && key.alt() && key.scancode() == Key::scan::del){
		keyctl.reboot();
	}else if (key.valid()){
		kout << key.ascii() << el;
	}
}
