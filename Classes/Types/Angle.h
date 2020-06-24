//
// Created by MacBook Pro on 6/24/20.
//

#ifndef WORM_ANGLE_H
#define WORM_ANGLE_H

class Angle {
    double internal;
public:
    Angle(double angle) {
        if (angle > 180) internal = 180;
        if (angle < -180) internal = -180;
        internal = angle;
    }

    explicit operator double() const {
        return internal;
    }

    Angle& operator+=(const Angle &rhs) {
        internal += rhs.internal;
        return *this;
    }

    Angle& operator-=(const Angle &rhs) {
        internal -= rhs.internal;
        return *this;
    }

    Angle operator+(const Angle &rhs) const {
        return Angle(internal + rhs.internal);
    }

    bool operator==(const Angle &rhs) const {
        return internal == rhs.internal;
    }

    bool operator<(const Angle &rhs) const {
        return internal < rhs.internal;
    }

    bool operator>(const Angle &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Angle &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Angle &rhs) const {
        return !(*this < rhs);
    }

    bool operator!=(const Angle &rhs) const {
        return !(rhs == *this);
    }
};

#endif //WORM_ANGLE_H
