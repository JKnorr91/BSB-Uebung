/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "object/o_stream.h"
        
int main()
{
	CGA_Stream kout; // = new CGA_Screen();
	kout.setpos(0,24);

	int x = 1;
	char text[9] = {'A','B','C','D','E','F','g','h','\n'};
	while (x<1) {
		kout.print(text,8,0x02);
		x++;
	}
	kout << 456451239 << " Test\n" << "Next line!" << oct << 128 << " - " << dec << 128 << " - " << bin << 128 << " - " << hex << 128 << el;
   return 0;
 }
