#include "matrix.h"
#include <iostream>

float &matrix3d::operator()(int m, int n) {
    return content[m][n];
}

vec3d &matrix3d::operator[](int idx) {
    return *reinterpret_cast<vec3d *>(content.at(idx).data());
}

const float &matrix3d::operator()(int m, int n) const {
    return content[m][n];
}

matrix3d::matrix3d(const vec3d &a, const vec3d &b, const vec3d &c) : content{
        std::array<std::array<float, 3>, 3>{{
            {a.x, a.y, a.z},
            {b.x, b.y, b.z},
            {c.x, c.y, c.z}}
        }} {}


const vec3d &matrix3d::operator[](int idx) const {
    return *reinterpret_cast<const vec3d *>(content.at(idx).data());;
}

matrix3d matrix3d::transposed() const {
    return matrix3d({{
         {content[0][0], content[1][0], content[2][0]},
         {content[0][1], content[1][1], content[2][1]},
         {content[0][2], content[1][2], content[2][2]}
    }});
}

std::ostream &operator<<(std::ostream &output, const matrix3d &m) {
    output << "[" << m[0] << "," << m[1] << "," << m[2] << "]";
    return output;
}

bool operator==(const matrix3d &a, const matrix3d &b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

matrix3d operator+(const matrix3d& a, const matrix3d& b) {
    return matrix3d({{
         {a(0, 0) + b(0, 0), a(0, 1) + b(0, 1), a(0, 2) + b(0, 2)},
         {a(1, 0) + b(1, 0), a(1, 1) + b(1, 1), a(1, 2) + b(1, 2)},
         {a(2, 0) + b(2, 0), a(2, 1) + b(2, 1), a(2, 2) + b(2, 2)}
    }});
}

matrix3d operator-(const matrix3d& a, const matrix3d& b) {
    return matrix3d({{
         {a(0, 0) - b(0, 0), a(0, 1) -  b(0, 1), a(0, 2) - b(0, 2)},
         {a(1, 0) - b(1, 0), a(1, 1) - b(1, 1), a(1, 2) - b(1, 2)},
         {a(2, 0) - b(2, 0), a(2, 1) - b(2, 1), a(2, 2) - b(2, 2)}
    }});
}

matrix3d operator*(const matrix3d& m, float n) {
    return matrix3d({{
             {m(0, 0)*n, m(0, 1)*n, m(0, 2)*n},
             {m(1, 0)*n, m(1, 1)*n, m(1, 2)*n},
             {m(2, 0)*n, m(2, 1)*n, m(2, 2)*n}
    }});
}
