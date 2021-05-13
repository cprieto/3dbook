#include <array>
#include <iostream>

template<std::size_t N, typename... T>
using vector_ctor_t = std::enable_if_t<sizeof...(T) == N && std::conjunction_v<std::is_convertible<T, float>...>>;

namespace fged {
    template<std::size_t N>
    class vector {
        std::array<float, N> elements;
    public:
        vector(): elements{0} {}

        template<typename... Args, vector_ctor_t<N, Args...>* = nullptr>
        vector(Args... args): elements{static_cast<float>(args)...}{} // NOLINT(google-explicit-constructor)

        template <std::size_t Idx>
        [[nodiscard]] float get() const {
            return elements.at(Idx);
        }

        float operator[](int idx) const {
            return elements.at(idx);
        }
    };
}

template<std::size_t N>
struct std::tuple_size<fged::vector<N>>: std::integral_constant<std::size_t, N> {};

template<std::size_t Idx, std::size_t N>
struct std::tuple_element<Idx, fged::vector<N>> {
    using type = float;
};

template<std::size_t N>
bool operator==(const fged::vector<N>&, const fged::vector<N>&);

template<std::size_t N>
bool operator!=(const fged::vector<N>& a, const fged::vector<N>& b) {
    return true;
}

template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const fged::vector<N>& v) {
    out << "(";
    for (int i = 0; i < N; ++i) {
        out << v[i];
        if (i < N - 1) out << ", ";
    }
    out << ")";

    return out;
}

struct vector3d {
    float x, y, z;
    vector3d() = default;
    vector3d(float x, float y, float z): x{x}, y{y}, z{z} {}

    [[nodiscard]] float magnitude() const;
    static vector3d normal(const vector3d&);
};

