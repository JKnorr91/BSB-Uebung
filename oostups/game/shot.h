#ifndef __Shot_include__
#define __Shot_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/entity.h"	


class Shot : public Entity {
private:
    Shot (const Shot &copy); // Verhindere Kopieren
public:
	Shot();
	Shot(int initialX, int initialY);
	bool update();
	void render();
 };
#endif
