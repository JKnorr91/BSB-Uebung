/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Locker implementiert eine Sperrvariable, die verwendet wird,   */
/* um kritische Abschnitte zu schuetzen. Die Variable zeigt allerdings nur   */
/* an, ob der kritische Abschnitt frei ist. Ein eventuelles Warten und der   */
/* Schutz der fuer diese Klasse notwendigen Zaehlfunktion muss ausserhalb    */
/* erfolgen.                                                                 */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

#include "machine/cpu.h"
#include "user/debug.h"

class Locker
 {
private:
    Locker(const Locker &copy); // Verhindere Kopieren
	bool free;
public:
	inline
	Locker () {
		free = true;
	}
	
	inline
	void enter () {
		if (!free) {
			debug.out(0, 0, "Locker::enter free == false");
			cpu.halt();
		}
		free = false;
	}

	inline
	void retne () {
		if (free) {
			debug.out(0, 0, "Locker::retne free == true");
			cpu.halt();
		}
		free = true;
	}

	inline
	bool avail () {
		return free;
	}
};
#endif
