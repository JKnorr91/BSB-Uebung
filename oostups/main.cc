/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Screen kout;

	kout.shiftline();
	kout.setpos(0,23);

	int bs = 81;
	char test2[bs];
	for(int i = 0; i < bs; i++) {
		test2[i] = 'B';
	}
	kout.print(test2,bs,0x2f);

	/*char br[1];
	br[0] = '\n';
	kout.print(br,1,0x00);*/

	int as = 95;
	char test[as];
	for(int i = 0; i < as; i++) {
		test[i] = 'A';
	}
	kout.print(test,as,0x4f);

	// kout.shiftline();
	// kout.shiftline();
  	return 0;
 }
