#include "catch2/catch.hpp"
#include "Tree.hpp"
#include <sstream>

TEST_CASE("Tree1", "") {
    Tree<int> t{0};
    t.addChild(1);
    t.addChild(2);
    t.addChild(3);

    std::stringstream ss;

    for(const auto& e : t)
    {
        ss << e;
    }
    REQUIRE((ss.str() == "0123"));
}

TEST_CASE("Tree2", "") {
    Tree<int> t{0};
    t.addChild(1);
    t.addChild(2);
    t.addChild(3);

    t[0].addChild(4);
    t[1].addChild(5);

    t[0][0];

    std::stringstream ss;

    for(const auto& e : t)
    {
        ss << e;
    }
    REQUIRE((ss.str() == "014253"));
}