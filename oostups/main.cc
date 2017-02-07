/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "device/cgastr.h"
#include "machine/pic.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/plugbox.h"
#include "syscall/guarded_keyboard.h"
#include "machine/keyctrl.h"
#include "user/appl.h"
#include "user/keyapp.h"
#include "guard/guard.h"
#include "user/debug.h"
#include "thread/scheduler.h"
#include "syscall/guarded_scheduler.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "meeting/bellringer.h"
#include "game/invaders.h"

CPU cpu;
CGA_Stream kout;
PIC pic;
Panic panic;
Plugbox plugbox;
Guarded_Keyboard keyboard;
Keyboard_Controller keyctl;
Guard guard;
Debug debug;
Bellringer bellringer; 
Guarded_Organizer organizer; 
Guarded_Semaphore cgasem(1);
Guarded_Semaphore keysem(0, 5);
Random random(1);

char stack1[4096];
Application app1(stack1+4092, 1,10,10);

char stack2[4096];
Application app2(stack2+4092, 2,40,10);

char stack3[4096];
KeyApp app3(stack3+4092);

char stack4[4096];
Invaders appInv(stack4+4092);

int main(){
	guard.enter();

	kout.setpos(0,24);
	kout << endl;
	kout.setpos(0,0);
	kout << "CGA System loaded" << endl;
	keyboard.plugin();
	kout << "Keyboard enabled" << endl;
	Watch watch(10000);
	watch.windup();
	kout << "Watch enabled" << endl;
	cpu.enable_int();
	kout << "interrupt System enabled" << endl << endl;
	debug.out(0, 4, "Debug enabled");
	
	// inizialization
	appInv.initializeGame();

	// organizer.Scheduler::ready(app1);
	// organizer.Scheduler::ready(app2);
	//organizer.Scheduler::ready(app3);
	organizer.Scheduler::ready(appInv);
	
	//app1.nextApp = &app2;
	//app2.nextApp = &app1;
	
	organizer.Scheduler::schedule();

	while (true);
 }
