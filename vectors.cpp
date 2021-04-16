#include <stdexcept>
#include "vectors.h"

float& vector3d::operator[](int idx) {
    if (idx < 0 || idx > 2) throw std::out_of_range("idx");
    return ((&x)[idx]);
}

float magnitude(vector3d v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

bool operator==(const vector3d& a, const vector3d& b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const vector3d& a, const vector3d& b) {
    return !(a == b);
}
