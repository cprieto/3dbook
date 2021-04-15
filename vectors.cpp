#include <cmath>
#include "vectors.h"

float& vector3d::operator[](int idx) {
    return ((&x)[idx]);
}
