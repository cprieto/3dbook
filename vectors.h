struct vector3d {
    float x, y, z;
    vector3d() = default;
    vector3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    float& operator[](int);
};

float magnitude(vector3d v);
bool operator==(const vector3d&, const vector3d&);
bool operator!=(const vector3d&, const vector3d&);