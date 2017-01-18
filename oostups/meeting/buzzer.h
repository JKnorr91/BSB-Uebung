/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__
#include"meeting/bell.h"
#include"meeting/waitingroom.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 

class Buzzer: public Waitingroom, public Bell
/* Hier muesst ihr selbst Code vervollstaendigen */ 
{
private:
    Buzzer(const Buzzer &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
public:
    Buzzer ();
    virtual ~Buzzer();
    virtual void ring();
    void set (int ms);
    void sleep ();
};

#endif