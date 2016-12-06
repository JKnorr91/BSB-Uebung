/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Funktion zum Starten einer Koroutine.                                     */
/* Da diese Funktion nicht wirklich aufgerufen, sondern nur durch eine       */
/* geschickte Initialisierung des Stacks der Koroutine angesprungen wird,    */
/* darf sie nie terminieren. Anderenfalls wuerde ein sinnloser Wert als      */
/* Ruecksprungadresse interpretiert werden und der Rechner abstuerzen.       */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/coroutine.h"

/*TODO Hinweis
Da diese Funktion nicht wirklich aufgerufen, sondern nur durch eine geschickte
Initialisierung des Stacks der Koroutine angesprungen wird, darf sie nie terminieren.
Anderenfalls würde ein sinnloser Wert als Rücksprungadresse interpretiert werden und
der Rechner abstürzen.
*/

void kickoff (Coroutine *object){
	object->action();
	while (true) {}
}
