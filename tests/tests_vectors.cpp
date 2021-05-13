#include <catch2/catch.hpp>
#include <sstream>
#include "vectors.h"

using vec3d = fged::vector<3>;

TEST_CASE("Destructuring") {
    vec3d v{1, 2, 3};
    auto [x, y, z] = v;

    REQUIRE(x == 1);
    REQUIRE(y == 2);
    REQUIRE(z == 3);
}

TEST_CASE("Indexing vector") {
    vec3d v{1, 2, 3};

    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

//TEST_CASE("Equality") {
//    vec3d v1{1, 2, 3};
//    vec3d v2{1, 2, 3};
//    vec3d v3{4, 5, 6};
//
//    REQUIRE(v1 == v2);
//    REQUIRE_FALSE(v1 == v3);
//}

TEST_CASE("String conversion") {
    vec3d v{1, 2, 3};

    std::stringstream out;
    out << v;
    REQUIRE(out.str() == "(1, 2, 3)");
}