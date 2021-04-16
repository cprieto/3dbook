#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "vectors.h"

TEST_CASE("Vector initialization", "[vectors]") {
    SECTION("Initializing empty vector") {
        vector3d v{};

        REQUIRE(v.x == 0);
        REQUIRE(v.y == 0);
        REQUIRE(v.z == 0);
    }

    SECTION("Initializing non empty vector") {
        vector3d v{1, 2, 3};

        REQUIRE(v.x == 1);
        REQUIRE(v.y == 2);
        REQUIRE(v.z == 3);
    }

    vector3d v{4, 5, 6};

    SECTION("Vector components can be access as array") {
        REQUIRE(v[0] == v.x);
        REQUIRE(v[1] == v.y);
        REQUIRE(v[2] == v.z);
    }

    SECTION("Vector components can be set as array") {
        v[0] = -1;
        v[1] = -2;
        v[2] = -3;

        REQUIRE(v.x == -1);
        REQUIRE(v.y == -2);
        REQUIRE(v.z == -3);
    }

    SECTION("Vector components are only 3") {
        REQUIRE_THROWS_AS(v[-1], std::out_of_range);
        REQUIRE_THROWS_AS(v[4], std::out_of_range);
    }

    SECTION("Equal vectors") {
        REQUIRE(v == v);
        REQUIRE(v == vector3d{4, 5, 6});
        REQUIRE(v != vector3d{1, 2, 3});
    }

    // This requires C++17
    SECTION("Vector supports structured binding") {
        const auto& [x, y, z] = v;

        REQUIRE(x == v.x);
        REQUIRE(y == v.y);
        REQUIRE(z == v.z);
    }
}

TEST_CASE("Vector basic operations", "[vectors]") {
    vector3d v{1, 2, 3};

    SECTION("We can calculate the magnitude") {
        REQUIRE(magnitude(v) == 3.74166f);
    }
}