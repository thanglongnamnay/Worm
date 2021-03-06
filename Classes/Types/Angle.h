//
// Created by MacBook Pro on 6/24/20.
//

#ifndef WORM_ANGLE_H
#define WORM_ANGLE_H
class Angle;

class Angle {
    double internal;
    void check(double angle) {
        if (angle > 180) internal = 180;
        else if (angle < 0) internal = 0;
        else internal = angle;
    }
public:
    Angle(double angle) {
        check(angle);
    }
    explicit operator double() const {
        return internal;
    }
	explicit operator int() const {
		return internal;
	}
    Angle& operator+=(double t) {
        check(internal + t);
        return *this;
    }
    Angle& operator-=(double t) {
        check(internal - t);
        return *this;
    }
	Angle operator-(const Angle& rhs) const {
    	return Angle(internal - rhs.internal);
    }
	Angle operator+(const Angle& rhs) const {
		return Angle(internal + rhs.internal);
	}
	bool operator<(const Angle& rhs) const {
		return internal < rhs.internal;
	}
	bool operator>(const Angle& rhs) const {
		return rhs < *this;
	}
	bool operator<=(const Angle& rhs) const {
		return !(rhs < *this);
	}
	bool operator>=(const Angle& rhs) const {
		return !(*this < rhs);
	}
	static const Angle RIGHT_ANGLE;
};

#endif //WORM_ANGLE_H
