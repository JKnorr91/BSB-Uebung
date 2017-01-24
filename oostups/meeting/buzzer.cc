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
        sleepTime = -1;
    }

     Buzzer::~Buzzer(){
        Customer *c = (Customer*) dequeue();
        while(c){
            organizer.wakeup(*c);
            c =  (Customer*) dequeue();
        }
        bellringer.cancel(this);
    }

     void Buzzer::ring(){
        Customer *c = (Customer*) dequeue();
        while (c){
            organizer.wakeup(*c);
			c = (Customer*) dequeue();
        }
    }

    void Buzzer::set (int ms){
        sleepTime = ms;
    }

    void Buzzer::sleep (){
        Customer *c = (Customer*) organizer.active();
        enqueue(c);
        bellringer.job(this, sleepTime);
        organizer.block(*c,*this);
    }
