/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
#include "device/cgastr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Stream kout; // = new CGA_Screen();
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */
	kout.setpos(0,24);
	int x = 1;
	char text[9] = {'A','B','C','D','E','F','g','h','\n'};
	while (x<10) {
		kout.print(text,9,0xf);
		x++;
	}
	kout << 10;
	kout << "abcd\n";
	kout.flush();
   return 0;
 }
