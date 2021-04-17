#include <array>
#include <iostream>

struct vector3d {
    float x, y, z;
    vector3d() = default;
    vector3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    float& operator[](int);
    vector3d& operator*=(float);
    vector3d& operator/=(float);
    vector3d& operator+=(const vector3d&);
    vector3d& operator-=(const vector3d&);

    [[nodiscard]] float magnitude() const;
    static vector3d normal(const vector3d&);
};

bool operator==(const vector3d&, const vector3d&);
bool operator!=(const vector3d&, const vector3d&);
vector3d operator*(const vector3d&, float);
vector3d operator*(float, const vector3d&);
std::ostream& operator<<(std::ostream&, const vector3d&);
vector3d operator/(const vector3d&, float);
vector3d operator+(const vector3d&, const vector3d&);
vector3d operator-(const vector3d&, const vector3d&);
