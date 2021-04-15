#include <stdexcept>
#include "vectors.h"

float& vector3d::operator[](int idx) {
    if (idx < 0 || idx > 2) throw std::out_of_range("idx");
    return ((&x)[idx]);
}
