#pragma once
#include <iostream>
#include "Image.h"
#include "Shape.h"

class Line :public Shape {
private:
	int xStart;
	int xSlutt;
	int yStart;
	int ySlutt;

public:
	Line(int x0,int x1,int y0,int y1, Color color);
	virtual void draw(Image &i);

};