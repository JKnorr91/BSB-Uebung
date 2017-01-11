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

/* Hier muesst ihr selbst Code vervollstaendigen */ 

class Bell : public Chain
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 {
private:
    Bell(const Bell &copy); // Verhindere Kopieren
public:
    Bell() {}
    void wait (int value);
    int wait ();
    void tick ();
    bool run_down();
    virtual void ring () = 0;
/* Hier muesst ihr selbst Code vervollstaendigen */ 

};

#endif
