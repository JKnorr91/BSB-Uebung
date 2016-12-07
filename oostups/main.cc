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
Guard guard;
Debug debug;

char stack1[1024];
Application app1(stack1+1020, 1,10,10);

char stack2[1024];
Application app2(stack2+1020, 2,40,10);

int main()
{
	kout.setpos(0,24);
	kout << endl;
	kout.setpos(0,0);
	kout << "CGA System loaded" << endl;
	keyboard.plugin();
	kout << "Keyboard enabled" << endl;
	cpu.enable_int();
	kout << "interrupt System enabled" << endl << endl;
	debug.out(0, 3, "Debug enabled");

	/*kout<< " -"<< (void*)stack1 << "-      -" << (void*)(stack1+1023)<<"-" <<endl;

	int** ebp = (int**) app1.getregs()->ebp;
	kout<< "-"<< ebp <<endl;;
	*/
	//pic.allow(PIC::timer);
	//pic.forbid(PIC::timer);
	
	kout << &app1 <<"   " << &app2 << endl;

	 app1.next =&app2;
	 app2.next =&app1;
	app1.go();
	//app2.go();

	while (true);//Endlosschleife um System am laufen zu halten. Interrupts passieren trotzde
   return 0;
 }
