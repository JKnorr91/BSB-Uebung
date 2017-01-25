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
#include "user/debug.h"
 
Keyboard::Keyboard(){
	keyBufPosWrite = 0;
	keyBufPosRead = 0;
}

void Keyboard::plugin (){
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

bool Keyboard::prologue (){
	Key curKey = key_hit();

	if(curKey.ctrl() && curKey.alt() && curKey.scancode() == Key::scan::del){
		reboot();
	}else if (curKey.valid()){
		key[keyBufPosWrite] = curKey;
		//ausgabe vormerken
		return true;
	}
	//kout << "Keyboard::trigger()" << el;
	return false;
}

void Keyboard::epilogue () {
	keyBufPosWrite++;
	if (keyBufPosWrite >= KEY_BUFFER_SIZE) {
		keyBufPosWrite = 0;
	}
	keysem.Semaphore::v();
}

Key Keyboard::getkey() {
	keysem.Semaphore::p();
	Key result = key[keyBufPosRead];

	keyBufPosRead++;
	if (keyBufPosRead >= KEY_BUFFER_SIZE) {
		keyBufPosRead = 0;
	}
	return result;
}
