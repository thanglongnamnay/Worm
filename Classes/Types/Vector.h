//
// Created by long on 22/05/2020.
//

#ifndef WORM_VECTOR_H
#define WORM_VECTOR_H

namespace type {
template<typename T>
struct Vector {
	T const x, y;

	Vector(T x = 0, T y = 0)
			:x(x), y(y) { }

	friend Vector operator+(const Vector& lhs, const Vector& rhs) {
		return Vector<T>(lhs.x+rhs.x, lhs.y+rhs.y);
	}
	Vector operator-() const {
		return Vector(-x, -y);
	}
	friend Vector operator-(const Vector& lhs, const Vector& rhs) {
		return lhs+ -rhs;
	}
	Vector operator*(double k) const {
		return Vector(x*k, y*k);
	}
};
}

#endif //WORM_VECTOR_H
