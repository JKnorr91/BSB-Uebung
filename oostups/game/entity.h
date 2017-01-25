/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __Entity_include__
#define __Entity_include__

#include "device/cgastr.h"
#include "object/chain.h"
#include "machine/key.h"

class Invaders;

class Entity : public Chain {

private:
    Entity (const Entity &copy); // Verhindere Kopieren

protected:
	int posX;
	int posY;

public:
	Entity();
	Entity(int initialX, int initialY);
	virtual bool update(Key nowPressed) = 0;
	virtual void render() = 0;
	int getPosX();
	int getPosY();
	void setPos(int x, int y);
 };
#endif
