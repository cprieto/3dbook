struct vector3d {
    float x, y, z;
    vector3d() = default;
    vector3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    float& operator[](int);
};
