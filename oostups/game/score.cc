#include "./score.h"

	Score::Score() : Entity(0,0) {
		fullReset();
	}

	void Score::reset() {
		score = 0;
		scoreDisplay = score;
		getHitbox()->setSize(14, 3);
		getHitbox()->setOffset(0, 0);
	}

	bool Score::update() {
		if (scoreDisplay < score) {
			scoreDisplay += 7;
			if (scoreDisplay > score) {
				scoreDisplay = score;
			}
		}
		if (scoreDisplay > score) {
			scoreDisplay -= 7;
			if (scoreDisplay < score) {
				scoreDisplay = score;
			}
		}
        return true;
	}

	void Score::render() {
		int styleBorder = 0x0f;
		kout.preShow(getX1(), getY1()+0, '#', styleBorder);
		kout.preShow(getX1(), getY1()+1, '|', styleBorder);
		kout.preShow(getX1(), getY1()+2, '#', styleBorder);

		kout.preShow(getX2()-1, getY1()+0, '#', styleBorder);
		kout.preShow(getX2()-1, getY1()+1, '|', styleBorder);
		kout.preShow(getX2()-1, getY1()+2, '#', styleBorder);

		for (int i = getX1() + 1; i < getX2()-1; i++) {
			kout.preShow(i, getY1(), '-', styleBorder);
			kout.preShow(i, getY2()-1, '-', styleBorder);
		}

		kout.setpos(getX1()+1, getY1()+1);
		kout << "Score: " << scoreDisplay << el;
		kout.hide();
	}

	int Score::getScore() {
		return score;
	}

	void Score::onMonsterHit(Monster* monster) {
		score += 25;
	}

	void Score::onMonsterDestroyed(Monster* monster) {
		score += 100;
	}

	void Score::onPlayerHit(Player* player) {
		score -= 50;
	}

	void Score::onShotFired(Player* player) {
		score -= 1;
	}
