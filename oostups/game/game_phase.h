#ifndef __GamePhase_include__
#define __GamePhase_include__


class GamePhase {
private:
    GamePhase (const GamePhase &copy) {}
public:
	GamePhase() {}
	virtual void start()=0;
	virtual void update()=0;
	virtual void render()=0;
 };
#endif
