/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        G U A R D E D _ B U Z Z E R                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Schnittstelle von Anwendungsthreads zu Buzzer-Objekten.                   */
/*****************************************************************************/

/* INCLUDES */

#include "syscall/guarded_buzzer.h"
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
    Guarded_Buzzer::Guarded_Buzzer() {
        val = -1;
    }
    Guarded_Buzzer::~Buzzer(){
        {
            Secure section;
            Buzzer::~Buzzer();
        }
    }
    void Guarded_Buzzer::set (int ms){
        {
            Secure section;
            Buzzer::set(ms);
        }
    }
    void Guarded_Buzzer::sleep (){
        {
            Secure section;
            Buzzer::sleep();
        }
    }