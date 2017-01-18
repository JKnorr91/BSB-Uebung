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

/* INCLUDES */
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include"meeting/buzzer.h"

    Buzzer::Buzzer (){
        val = -1;
    }
    virtual Buzzer::~Buzzer(){
        Customer *c = (Customer*) dequeue();
        while(c){
            organizer.wakeup(*c);
            c =  (Customer*) dequeue();
        }
        bellringer.chancel(*this);
    }
    virtual void Buzzer::ring(){
        Customer *c = (Customer*) dequeue();
        if (c){
            organizer.wakeup(*c);
        }
    }
    void Buzzer::set (int ms){
        val = ms;
    }
    void Buzzer::sleep (){
        Customer *c = (Customer*) organizer.active();
        enqueue(c);
        organizer.block(*c,*this);
    }