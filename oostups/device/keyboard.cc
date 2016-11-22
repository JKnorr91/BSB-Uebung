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
#include "user/appl.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
Keyboard::Keyboard(){}

void Keyboard::plugin (){
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

bool Keyboard::prologue (){
	key = key_hit();
	if(key.ctrl() && key.alt() && key.scancode() == Key::scan::del){
		reboot();
	}else if (key.valid()){
		//ausgabe vormerken
		return true;
	}
	//kout << "Keyboard::trigger()" << el;
	return false;
}

void Keyboard::epilogue (){
	kout << key.ascii() << el;
}
