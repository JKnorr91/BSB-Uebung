#ifndef __Monster_b_include__
#define __Monster_b_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/entity.h"

class Domain;

class Monster_b : public Entity {

private:
    Monster_b (const Monster_b &copy); // Verhindere Kopieren
	int life;
	int cooldown;
	Domain* domain;
public:
	Monster_b();
	Monster_b(int initialX, int initialY);
	void setDomain(Domain* domain);
	bool update();
	void render();
 };
#endif