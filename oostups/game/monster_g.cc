#include "game/monster_g.h"

	MonsterGreen::MonsterGreen() : Monster(3) {
		moveWaitY = 9;
		moveY = 1;
		moveXCounter = 0;
		moveXDirection = true;
		setPositionRestrictionX(2,2);
		getHitbox()->setSize(4, 3);
		getHitbox()->setOffset(-2, -1);
	}

	void MonsterGreen::updateMonster() {
		if (moveXDirection) {
			moveX = 1;
			moveXCounter++;
			if (moveXCounter > 4) {
				moveXDirection = !moveXDirection;
			}
		} else {
			moveX = -1;
			moveXCounter--;
			if (moveXCounter < -4) {
				moveXDirection = !moveXDirection;
			}
		}
	}

	void MonsterGreen::render() {
		/*
		 * Schema
		 *  ### 
		 * #*#*#
		 *  ### 
		 * #   #



		 ##
		 ##
		/  \


		 */


		renderExplosion();

		if(isAlive()) {
			int styleGreen = wasHit() ? 0xdd : 0xad;
			int styleOuterGreen = wasHit() ? 0xda : 0x0a;
			int styleRed = wasHit() ? 0xdd : 0xcc;

			//Zeile 1
			//kout.preShow(getX1()+0, getY1()+0, ' ', styleGreen);
			kout.preShow(getX1()+1, getY1()+0, '.', styleGreen);
			kout.preShow(getX1()+2, getY1()+0, '.', styleGreen);
			//kout.preShow(getX1()+3, getY1()+0, ' ', styleGreen);
			//kout.preShow(getX1()+4, getY1()+0, ' ', styleGreen);
			//Zeile 2
			kout.preShow(getX1()+0, getY1()+1, '/', styleOuterGreen);
			kout.preShow(getX1()+1, getY1()+1, '<', styleGreen);
			kout.preShow(getX1()+2, getY1()+1, '>', styleGreen);
			kout.preShow(getX1()+3, getY1()+1, '\\', styleOuterGreen);
			// kout.preShow(getX1()+2, getY1()+1, ' ', styleGreen);
			// kout.preShow(getX1()+3, getY1()+1, ' ', styleRed);
			// kout.preShow(getX1()+4, getY1()+1, ' ', styleGreen);
			//Zeile 3
			//kout.preShow(getX1()+0, getY1()+2, ' ', styleGreen);
			kout.preShow(getX1()+0, getY1()+2, '/', styleOuterGreen);
			kout.preShow(getX1()+3, getY1()+2, '\\', styleOuterGreen);
			// kout.preShow(getX1()+3, getY1()+2, ' ', styleGreen);
			//kout.preShow(getX1()+4, getY1()+2, ' ', styleGreen);
			//Zeile 4
			// kout.preShow(getX1()+0, getY1()+3, ' ', styleGreen);
			//kout.preShow(getX1()+1, getY1()+3, ' ', styleGreen);
			//kout.preShow(getX1()+2, getY1()+3, ' ', styleGreen);
			//kout.preShow(getX1()+3, getY1()+3, ' ', styleGreen);
			// kout.preShow(getX1()+4, getY1()+3, ' ', styleGreen);

		}
		
		rendered();
	}
