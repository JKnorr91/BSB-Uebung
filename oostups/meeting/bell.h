/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h"


class Bell : public Chain
{
private:
    Bell(const Bell &copy); // Verhindere Kopieren
public:
    int val;
    Bell() {};
    void wait (int value){val = value;};
    int wait (){return val;};
    void tick (){val--;};
    bool run_down(){return 0 == val;};
    virtual void ring () = 0;
};

#endif
