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

void Keyboard::trigger (){
	key = key_hit();
	if(key.ctrl() && key.alt() && key.scancode() == Key::scan::del){
		reboot();
	}else if (key.valid()){
		//app.output_num++;
		kout << key.ascii() << el;
	}
	//kout << "Keyboard::trigger()" << el;
}
