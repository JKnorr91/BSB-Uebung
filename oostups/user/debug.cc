
#include "user/debug.h"
#include "device/cgastr.h"

	Debug::Debug() {}

	void Debug::out (int x, int y, char* text)
 	{
		while (*text != 0) {
			char c = *text;
			kout.show(x, y, c, 0x20);
			x++;
			if (x >= 80) {
				x = 0;
				y++;
				if (y >= 25) {
					y = 0;
				}
			}
			text++;
		}
 	}
