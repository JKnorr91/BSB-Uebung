/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Screen kout;

	char test[3];
	test[0] = 'A';
	test[1] = 'B';
	test[2] = 'C';

	kout.print(test,3,0x0f);

	kout.shiftline();
  	return 0;
 }
