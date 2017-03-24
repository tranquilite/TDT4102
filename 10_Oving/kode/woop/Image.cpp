#include<vector>

#include"Image.h"

using namespace std;

Image::Image( int width, int height ) {
	data = new Color[width*height];
	this->width = width;
	this->height = height;
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
}

int Image::getWidth() const {
   return width;
}

int Image::getHeight() const  {
   return height;
}

const Pixel * Image::getScanLine(int line) const  {
   return &data[width*line];
}

Pixel * Image::getScanLine(int line) {
   return &data[width*line];
}

Color Image::getPixelColor( int x, int y ) const {
   return Color(data[width*y + x]);
}

void Image::setPixelColor( int x, int y, const Color &color ) {
	data[width * y + x] = color;
}

void Image::fill( const Color &color ) {
	int size = width*height;
	for (int i = 0; i < size; i++) {
		data[i] = color;
	}
}
