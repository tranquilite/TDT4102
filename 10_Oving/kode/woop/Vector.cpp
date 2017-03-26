#include<cmath>

#include"Matrix.h"
#include"Vector.h"

Vector::Vector() : Matrix(){ }

Vector::Vector(int nRows) : Matrix(nRows, 1, 0.0) { }

Vector::Vector(const Matrix & other) {
	if (other.getColumns() == 1 && other.isValid()) {
		Matrix::operator = (other);
	}
	else {
		Matrix temp = Matrix(other);
		temp.invalidate();
		Matrix::operator =(temp);
	}
}

double Vector::dot(const Vector &rhs) {
	Vector lhs = *this;
        double dotProduct = 0;
	if (lhs.getRows() != rhs.getRows() || lhs.isValid() == false || rhs.isValid()) {
		return nan("");
	}
	else {
		for (int i = 0; i < lhs.getRows(); i++) {
			dotProduct += lhs.get(i) * rhs.get(i);
		}
	}
    return dotProduct;
}

double Vector::lengthSquared() const {
	Vector lhs = *this; //cp
	return lhs.dot(lhs);
}

double Vector::length() const {
	return sqrt(this->lengthSquared());
}
