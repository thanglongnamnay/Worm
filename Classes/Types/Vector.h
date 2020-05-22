//
// Created by long on 22/05/2020.
//

#ifndef WORM_VECTOR_H
#define WORM_VECTOR_H

#include "type_safe/integer.hpp"

template <typename T>
struct Vector {
    T const x, y;

    Vector(T x, T y) : x(x), y(y) {}

    Vector plus(Vector v) const {
        return {x + v.x, y + v.y};
    }
};

#endif //WORM_VECTOR_H
