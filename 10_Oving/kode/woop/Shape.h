#pragma once
#include"Image.h"

class Shape{
private:
	Color color;

public:
	Shape(Color color);
	Color getColor() { return color; };
	virtual void draw(Image &i)=0;
};