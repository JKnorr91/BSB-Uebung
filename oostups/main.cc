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
#include "thread/scheduler.h"
#include "syscall/guarded_scheduler.h"
#include "guard/secure.h"

CPU cpu;
CGA_Stream kout;
PIC pic;
Panic panic;
Plugbox plugbox;
Keyboard keyboard;
Keyboard_Controller keyctl;
Guard guard;
Debug debug;
Guarded_Scheduler scheduler;

char stack1[4096];
Application app1(stack1+4092, 1,10,10);

char stack2[4096];
Application app2(stack2+4092, 2,40,10);

int main(){
	kout.setpos(0,24);
	kout << endl;
	kout.setpos(0,0);
	kout << "CGA System loaded" << endl;
	keyboard.plugin();
	kout << "Keyboard enabled" << endl;
	cpu.enable_int();
	kout << "interrupt System enabled" << endl << endl;
	debug.out(0, 3, "Debug enabled");

	scheduler.ready(app1);
	scheduler.ready(app2);
	app1.nextApp = &app2;
	app2.nextApp = &app1;
	
	guard.enter();
	scheduler.Scheduler::schedule();

	while (true);
 }
