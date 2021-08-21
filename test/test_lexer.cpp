#include "Lexer.hpp"
#include "catch2/catch.hpp"
#include <string>

TEST_CASE("Lexer1", "") {
    std::string program
    {
        "5+5+5"
    };
    Lexer lexer{program};
    auto tokens = lexer.getTokens();
    
    REQUIRE((tokens[0].type == TokenType::Integer_Literal
        && tokens[0].value == "5")
    );
    REQUIRE(tokens[1].type == TokenType::ADD);

    REQUIRE((tokens[2].type == TokenType::Integer_Literal
        && tokens[2].value == "5")
    );

    REQUIRE(tokens[3].type == TokenType::ADD);

    REQUIRE((tokens[4].type == TokenType::Integer_Literal
        && tokens[4].value == "5")
    );
}

TEST_CASE("Lexer2", "") {
    std::string program
    {
        "33*5/123"
    };
    Lexer lexer{program};
    auto tokens = lexer.getTokens();
    
    REQUIRE((tokens[0].type == TokenType::Integer_Literal
        && tokens[0].value == "33")
    );
    REQUIRE(tokens[1].type == TokenType::MUL);

    REQUIRE((tokens[2].type == TokenType::Integer_Literal
        && tokens[2].value == "5")
    );

    REQUIRE(tokens[3].type == TokenType::DIV);

    REQUIRE((tokens[4].type == TokenType::Integer_Literal
        && tokens[4].value == "123")
    );
}

TEST_CASE("Lexer3", "") {
    std::string program
    {
        "33  *  5/123"
    };
    Lexer lexer{program};
    auto tokens = lexer.getTokens();
    
    REQUIRE((tokens[0].type == TokenType::Integer_Literal
        && tokens[0].value == "33")
    );
    REQUIRE(tokens[1].type == TokenType::MUL);

    REQUIRE((tokens[2].type == TokenType::Integer_Literal
        && tokens[2].value == "5")
    );

    REQUIRE(tokens[3].type == TokenType::DIV);

    REQUIRE((tokens[4].type == TokenType::Integer_Literal
        && tokens[4].value == "123")
    );
}

TEST_CASE("Lexer4", "") {
    std::string program
    {
        "3?3*5/123"
    };
    REQUIRE_THROWS_AS(Lexer{program}, UnkownTokenError);
}