#include <catch2/catch.hpp>
#include <sstream>
#include "vectors.h"

using namespace Catch::literals;
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

TEST_CASE("Equality operators") {
    vec3d v1{1, 2, 3};
    vec3d v2{1, 2, 3};
    vec3d v3{4, 5, 6};

    SECTION("Equality") {
        REQUIRE(v1 == v2);
        REQUIRE_FALSE(v1 == v3);
    }

    SECTION("Inequality") {
        REQUIRE(v1 != v3);
        REQUIRE_FALSE(v1 != v2);
    }
}

TEST_CASE("String conversion") {
    vec3d v{1, 2, 3};

    std::stringstream out;
    out << v;
    REQUIRE(out.str() == "(1, 2, 3)");
}

TEST_CASE("Vector arithmetic") {
    vec3d v1{1, 2, 3};

    SECTION("Adding two positive vectors") {
        const auto result = v1 + v1;

        REQUIRE(result[0] == 2);
        REQUIRE(result[1] == 4);
        REQUIRE(result[2] == 6);
    }

    SECTION("Adding positive and negative vectors") {
        const auto result = v1 + vec3d{-2, -3, -4};

        REQUIRE(result[0] == -1);
        REQUIRE(result[1] == -1);
        REQUIRE(result[2] == -1);
    }

    SECTION("Subtracting two vectors") {
        const auto result = v1 - v1;

        REQUIRE(result[0] == 0);
        REQUIRE(result[1] == 0);
        REQUIRE(result[2] == 0);
    }

    SECTION("Subtracting a positive and negative vector") {
        const auto result = v1 - vec3d{-1, -2, -3};

        REQUIRE(result[0] == 2);
        REQUIRE(result[1] == 4);
        REQUIRE(result[2] == 6);
    }

    SECTION("Scaling a vector, lhs") {
        const auto result = v1 * 3;

        REQUIRE(result[0] == 3);
        REQUIRE(result[1] == 6);
        REQUIRE(result[2] == 9);
    }

    SECTION("Scaling a vector, rhs") {
        const auto result = 2 * v1;

        REQUIRE(result[0] == 2);
        REQUIRE(result[1] == 4);
        REQUIRE(result[2] == 6);
    }

    SECTION("Descaling a vector") {
        const auto result = v1 / 3;

        REQUIRE(result[0] == 0.33333_a);
        REQUIRE(result[1] == 0.66667_a);
        REQUIRE(result[2] == 1);
    }
}