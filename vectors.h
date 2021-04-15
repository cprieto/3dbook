struct vector3d {
    float x, y, z;
    vector3d() = default;
    vector3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    float& operator[](int);
};

inline float magnitude(vector3d v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
};