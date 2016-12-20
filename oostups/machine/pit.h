/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

class PIT
 {
private:
    PIT(const PIT &copy); // Verhindere Kopieren

    const IO_Port counter0w;
	const IO_Port ctrlw;
    int currentInterval;
public:
    PIT (int us): counter0w(0x40), ctrlw(0x43) {
      interval (us);
    }
    int interval () {
        return currentInterval;
    }
    void interval (int us);
};

#endif
