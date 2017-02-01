#ifndef __Hitbox_include__
#define __Hitbox_include__

class Hitbox {
protected:
	int x;
	int y;
	int w;
	int h;
	int ox;
	int oy;
public:
	Hitbox();
	int getOriginX();
	int getOriginY();
	int getOffsetX();
	int getOffsetY();
	int getWidth();
	int getHeight();
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	void setX(int value);
	void setY(int value);
	void setWidth(int value);
	void setHeight(int value);
	void setOffsetX(int value);
	void setOffsetY(int value);
	void setPos(int posX, int posY);
	void setSize(int sizeX, int sizeY);
	void setOffset(int offsetX, int offsetY);
	bool contains(int x, int y);
	bool intersects(int x1, int y1, int x2, int y2);
	bool intersects(Hitbox* other);
 };
#endif
