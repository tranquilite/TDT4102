#include <iostream>
#include "Image.h"
#include "Shape.h"
#include "Line.h"

Line::Line(int x0, int x1, int y0, int y1, Color color) : Shape(color){
	this->xStart = x0;
	this->xSlutt = x1;
	this->yStart = y0;
	this->ySlutt = y1;
}

void Line::draw(Image & i) {
	int y;
	int x;
	double stigningstall = (static_cast<double>(ySlutt - yStart)) / (xSlutt - xStart);
	if (stigningstall >= 1 || stigningstall <= -1) {
		for (int y = yStart; y <= ySlutt; y++) {
			x = static_cast<double>(xSlutt - xStart)/(ySlutt - yStart)* (y - yStart) + xStart;
			i.setPixelColor(x, y, getColor());
		}
	}
	for (int x = xStart; x <= xSlutt; x++) {
			y = stigningstall * (x - xStart) + yStart;
			i.setPixelColor(x, y, getColor());
	}
	
}


