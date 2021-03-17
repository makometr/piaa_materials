#include "includeCatch.hpp"
#include "../source/header.hpp"


TEST_CASE("checkCell empty cells", "[internal algo test]" ) {
    labyrinth = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
    };
    REQUIRE(checkCell({1,0}) == true);
    REQUIRE(checkCell({0,1}) == true);
}


TEST_CASE("checkCell non-empty cells", "[internal algo test]" ) {
    labyrinth = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
    };
    REQUIRE(checkCell({0, 0}) == false);
    REQUIRE(checkCell({1, 1}) == false);
    REQUIRE(checkCell({2, 2}) == false);
}

TEST_CASE("checkCell over-border index", "[internal algo test]" ) {
    labyrinth = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
    };
    REQUIRE(checkCell({-1, 1}) == false);
    REQUIRE(checkCell({1, -1}) == false);
    REQUIRE(checkCell({-10, -10}) == false);
    REQUIRE(checkCell({-100, -100}) == false);

    REQUIRE(checkCell({10, 2}) == false);
    REQUIRE(checkCell({2, 10}) == false);
    REQUIRE(checkCell({10, -2}) == false);
    REQUIRE(checkCell({-2, 10}) == false);
    REQUIRE(checkCell({10, 10}) == false);
}
