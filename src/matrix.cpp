#include "matrix.h"
#include <iostream>

float& matrix3d::operator()(int m, int n) {
    return content[m][n];
}

vector3d& matrix3d::operator[](int idx) {
    return *reinterpret_cast<vector3d*>(content.at(idx).data());
}

const float& matrix3d::operator()(int m, int n) const {
    return content[m][n];
}

matrix3d::matrix3d(const vector3d& a, const vector3d& b, const vector3d& c) {
    content = std::array<std::array<float, 3>, 3>{{ {a.x, a.y, a.z}, {b.x, b.y, b.z}, {c.x, c.y, c.z} }};
}

const vector3d& matrix3d::operator[](int idx) const {
    return *reinterpret_cast<const vector3d*>(content.at(idx).data());;
}

matrix3d matrix3d::transposed() const {
    return matrix3d({{
        {content[0][0], content[1][0], content[2][0]},
        {content[0][1], content[1][1], content[2][1]},
        {content[0][2], content[1][2], content[2][2]}
    }});
}

std::ostream &operator<<(std::ostream& output, const matrix3d& m) {
    output << "[" << m[0] << "," << m[1] << "," << m[2] << "]";
    return output;
}

bool operator==(const matrix3d& a, const matrix3d& b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}
