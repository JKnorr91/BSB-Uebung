/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "device/cgastr.h"
//#include "machine/pic.h"

int main()
{
	kout.setpos(0,24);
	kout << endl;
	kout.setpos(0,0);
	kout << "CGA System loaded" << endl;
	//PIC pic;
	kout << "interrupt System loaded" << endl;

	int x = 1;
	char text[9] = {'A','B','C','D','E','F','g','h','\n'};
	while (x<1) {
		kout.print(text,8,0x02);
		x++;
	}
	kout << 456451239 << " Test\n" << "Next \nline!" << oct << 128 << " - " << hex << 128 << " - " << bin << 128 << " - " << dec << 128 << el;
	kout << endl;
	kout << &x << el;
	kout << endl;

	//pic.allow(1);
	while (true){

	}
   return 0;
 }
