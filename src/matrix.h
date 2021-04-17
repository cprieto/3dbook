#include <array>
#include "vectors.h"

class matrix3d {
    std::array<std::array<float, 3>, 3> content;
public:
    matrix3d() = default;
    matrix3d(std::array<std::array<float, 3>, 3> content): content{content} {}
    matrix3d(const vector3d&, const vector3d&, const vector3d&);

    float& operator()(int, int);
    const float& operator()(int, int) const;
    vector3d& operator[](int);
    const vector3d& operator[](int) const;
};

std::ostream& operator<<(std::ostream&, const matrix3d&);
bool operator==(const matrix3d&, const matrix3d&);