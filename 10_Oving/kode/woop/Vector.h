#pragma once

#include <iostream>
#include "Matrix.h"

class Vector : public Matrix {

public:
	Vector();
	explicit Vector(int nRows);
	Vector(const Matrix & other);
	void set(int row, double value) {
		at(row,1) = value;
	}
	double get(int row) const {
		return at(row,1);
	}
	double dot(const Vector &rhs);
	double lengthSquared() const;
	double length() const;
};
