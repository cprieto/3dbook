#include <array>
#include "vectors.h"

class matrix3d {
    std::array<std::array<float, 3>, 3> content;
public:
    matrix3d() = default;
    matrix3d(const vector3d&, const vector3d&, const vector3d&);
    explicit matrix3d(std::array<std::array<float, 3>, 3> content): content{content} {}

    float& operator()(int, int);
    const float& operator()(int, int) const;
    vector3d& operator[](int);
    const vector3d& operator[](int) const;

    [[nodiscard]] matrix3d transposed() const;
};

std::ostream& operator<<(std::ostream&, const matrix3d&);
bool operator==(const matrix3d&, const matrix3d&);
matrix3d operator+(const matrix3d&, const matrix3d&);
matrix3d operator-(const matrix3d&, const matrix3d&);
matrix3d operator*(const matrix3d&, float);
