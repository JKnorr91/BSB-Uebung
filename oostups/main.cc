/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */
#include "machine/cgascr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
int main()
{
	CGA_Screen kout; // = new CGA_Screen();
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
	char text[8] = {'A','B','C','D','E','F','g','h'};
	kout.show(70, 20, 'A', 0x0f);
	kout.print(text,8,0xf);
   return 0;
 }
