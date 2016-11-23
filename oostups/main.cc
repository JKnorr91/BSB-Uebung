/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "device/cgastr.h"
#include "machine/pic.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "machine/keyctrl.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "user/debug.h"

CPU cpu;
CGA_Stream kout;
PIC pic;
Panic panic;
Plugbox plugbox;
Keyboard keyboard;
Keyboard_Controller keyctl;
Application app;
Guard guard;
Debug debug;

int main()
{
	kout.setpos(0,24);
	kout << endl;
	kout.setpos(0,0);
	kout << "CGA System loaded" << endl;
	cpu.enable_int();
	kout << "interrupt System enabled" << endl;
	keyboard.plugin();
	kout << "Keyboard enabled" << endl << endl;
	debug.out(0, 3, "Debug enabled");

	/*int x = 1;
	char text[9] = {'A','B','C','D','E','F','g','h','\n'};
	while (x<1) {
		kout.print(text,8,0x02);
		x++;
	}
	kout << 456451239 << " Test\n" << "Next \nline!" << oct << 128 << " - " << hex << 128 << " - " << bin << 128 << " - " << dec << 128 << el;
	kout << endl;
	kout << &x << el;
	kout << endl;*/


	pic.allow(PIC::timer);
	pic.forbid(PIC::timer);

	app.action();

	while (true);//Endlosschleife um System am laufen zu halten. Interrupts passieren trotzde
   return 0;
 }
