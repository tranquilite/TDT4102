#include <iostream>

#include "Image.h"
#include "Matrix.h"
#include "Vector.h"
#include "Line.h"

using namespace std;

int main() {

    Matrix testMatrise(4, 4, 8);
	Vector testVector(4);
	testVector.set(0, 5), testVector.set(1, 5), testVector.set(2, 5), testVector.set(3, 5);
	cout << testMatrise*testVector;

	
	Image fylltBildeTest(10, 10);
	fylltBildeTest.fill(Color(193, 84, 193));
	saveImage(fylltBildeTest, "ensidigTest.bmp");
	loadImage("ensidigTest.bmp");

	Image prikkTest(100, 100);
	prikkTest.fill(Color(0, 0, 0));
	prikkTest.setPixelColor(50, 50, Color(255, 0, 0));
	saveImage(prikkTest, "prikkTest.bmp");
	loadImage("prikkTest.bmp");
/*
	Image fylltBildeTest2(300, 300);
	fylltBildeTest2.fill(Color(0,0,0));
	Line strek1(0, 100, 0, 50, Color(255, 255, 255));
	strek1.draw(fylltBildeTest2);
	saveImage(fylltBildeTest2, "strek1");
        // ehA*/
	Image BILDE2(300, 300);
	Line strek2(0, 100, 0, 200, Color(255,255,255));
	strek2.draw(BILDE2);
	saveImage(BILDE2, "strek4.bmp");
	
	
	
return 0;
}
