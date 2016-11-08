/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Stream kout;
	Keyboard_Controller key_ctrl;
	kout.setpos(0,19);

	while(true) {

		Key k = key_ctrl.key_hit();

		if(!k.valid()) {
			continue;
		}

		char t = k.ascii();
		kout << t;
		kout.flush();
		//kout.show(0,20,t, 0x0f);
	}

   return 0;
 }
