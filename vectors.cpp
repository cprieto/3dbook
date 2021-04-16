#include <cmath>
#include <stdexcept>
#include "vectors.h"

float& vector3d::operator[](int idx) {
    if (idx < 0 || idx > 2) throw std::out_of_range("idx");
    return ((&x)[idx]);
}

vector3d& vector3d::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;

    return (*this);
}

vector3d& vector3d::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;

    return (*this);
}

bool operator==(const vector3d& a, const vector3d& b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const vector3d& a, const vector3d& b) {
    return !(a == b);
}

float magnitude(const vector3d& v) {
    return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vector3d operator/(const vector3d& v, float scale) {
    return vector3d{v.x/scale, v.y/scale, v.z/scale};
}

std::ostream &operator<<(std::ostream& output, const vector3d& v) {
    output << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return output;
}

vector3d operator*(const vector3d& v, float scale) {
    return vector3d{v.x*scale, v.y*scale, v.z*scale};
}

vector3d operator*(float scale, const vector3d& v) {
    return v*scale;
}

vector3d normal(const vector3d& v) {
    return v / magnitude(v);
}

