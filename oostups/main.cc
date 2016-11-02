/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Screen kout;

	char test[97];

	for(int i = 0; i < 97; i++) {
		test[i] = 'A';
	}

	kout.print(test,97,0x2f);

	char test2[95];

	for(int i = 0; i < 95; i++) {
		test2[i] = 'B';
	}

	kout.print(test2,95,0xf0);

	//kout.shiftline();
  	return 0;
 }
