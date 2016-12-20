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

class PIT
 {
private:
    PIT(const PIT &copy); // Verhindere Kopieren

    const IO_Port counter0w;
	const IO_Port ctrlw;
    int interval;
public:
    PIT (int us): counter0w(0x40), ctrlw(0x43) {
      interval (us);
    }
    int interval () {
        return interval;
    }
    void interval (int us);
};

#endif
