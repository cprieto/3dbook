#include <catch2/catch.hpp>
#include <array>
#include <sstream>
#include "matrix.h"

TEST_CASE("We can create a 3d matrix", "[matrix]") {
    SECTION("Create a matrix from arrays") {
        matrix3d m({{{5, 8, 2}, {8, 3, 1}, {5, 3, 9}}});
    }

    SECTION("Create a matrix from vectors") {
        matrix3d m(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});
    }
}

TEST_CASE("We can access members from a 3d matrix", "[matrix]") {
    matrix3d m({{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}});

    SECTION("Access individual elements") {
        REQUIRE(m(1, 2) == 6);
        REQUIRE(m(0, 0) == 1);
        REQUIRE(m(2, 2) == 9);
    }

    SECTION("Access a row as vector") {
        REQUIRE(m[1] == vector3d(4, 5, 6));
        REQUIRE(m[0] == vector3d(1, 2, 3));
    }

    SECTION("Change a given row and column") {
        m(1, 2) = 12;
        REQUIRE(m(1, 2) == 12);
    }

    SECTION("Change a given row from a vector") {
        m[1] = vector3d(10, 11, 12);
        REQUIRE(m[1] == vector3d(10, 11, 12));
    }
}


TEST_CASE("Show a matrix as text", "[matrix]") {
    matrix3d m(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});

    std::stringstream out;
    out << m;
    REQUIRE("[{1, 2, 3}, {4, 5, 6}, {7, 8, 9}]");
}

TEST_CASE("Matrix equality", "[matrix]") {
    matrix3d m(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});

    SECTION("Two matrices with the same components are equal") {
        matrix3d n(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});

        REQUIRE(m == n);
        REQUIRE(m == m);
    }
}

TEST_CASE("Transpose matrix", "[matrix]") {
    matrix3d m(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});

    SECTION("We can transpose a matrix") {
        auto t = m.transposed();

        REQUIRE(t[0] == vector3d(1, 4, 7));
        REQUIRE(t[1] == vector3d(2, 5, 8));
        REQUIRE(t[2] == vector3d(3, 6, 9));
    }
}

TEST_CASE("Matrix addition, subtraction and scalar multiplication", "[matrix]") {
    matrix3d a(vector3d{1, 2, 3}, vector3d{4, 5, 6}, vector3d{7, 8, 9});
    matrix3d b(vector3d{10, 20, 30}, vector3d{40, 50, 60}, vector3d{70, 80, 90});

    SECTION("Addition") {
        matrix3d result({{
            {11, 22, 33},
            {44, 55, 66},
            {77, 88, 99}}
        });

        REQUIRE(a + b == result);
    }

    SECTION("Subtraction") {
        matrix3d result({{
                 {-9, -18, -27},
                 {-36, -45, -54},
                 {-63, -72, -81}}
        });

        REQUIRE(a - b == result);
    }

    SECTION("Scalar multiplication") {
        matrix3d result({{
                 {2, 4, 6},
                 {8, 10, 12},
                 {14, 16, 18}}
        });

        REQUIRE(a*2 == result);
    }
}

