#include <array>

class matrix3d {
    std::array<std::array<float, 3>, 3> content;
    matrix3d() = default;
};