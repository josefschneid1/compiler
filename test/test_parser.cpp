#include "catch2/catch.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"
#include <string>

TEST_CASE("Parser1", "") {
    std::string program = "5+3*2";
    Lexer lexer{program};
    Parser parser{lexer.getTokens()};
    auto& ast = parser.getAst();
    REQUIRE(ast.getValue().type == ASTNodeType::Program);
    REQUIRE(ast[0].getValue().type == ASTNodeType::Addition);
    REQUIRE(ast[0][0].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0].getValue().value == "5");
    REQUIRE(ast[0][1].getValue().type == ASTNodeType::Multiplication);
    REQUIRE(ast[0][1][0].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1][0].getValue().value == "3");
    REQUIRE(ast[0][1][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1][1].getValue().value == "2");
 }

TEST_CASE("Parser2", "") {
    std::string program = "(5+3)*2";
    Lexer lexer{ program };
    Parser parser{ lexer.getTokens() };
    auto& ast = parser.getAst();
    REQUIRE(ast.getValue().type == ASTNodeType::Program);
    REQUIRE(ast[0].getValue().type == ASTNodeType::Multiplication);
    REQUIRE(ast[0][0].getValue().type == ASTNodeType::Addition);
    REQUIRE(ast[0][0][0].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][0].getValue().value == "5");
    REQUIRE(ast[0][0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][1].getValue().value == "3");
    REQUIRE(ast[0][0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1].getValue().value == "2");
}

TEST_CASE("Parser3", "") {
    std::string program = "1";
    Lexer lexer{ program };
    Parser parser{ lexer.getTokens() };
    auto& ast = parser.getAst();
    REQUIRE(ast.getValue().type == ASTNodeType::Program);
    REQUIRE(ast[0].getValue().type == ASTNodeType::Integer_Literal);
}

TEST_CASE("Parser4", "") {
    std::string program = "1+2+3";
    Lexer lexer{ program };
    Parser parser{ lexer.getTokens() };
    auto& ast = parser.getAst();
    REQUIRE(ast.getValue().type == ASTNodeType::Program);
    REQUIRE(ast[0].getValue().type == ASTNodeType::Addition);
    REQUIRE(ast[0][0].getValue().type == ASTNodeType::Addition);
    REQUIRE(ast[0][0][0].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][0].getValue().value == "1");
    REQUIRE(ast[0][0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][1].getValue().value == "2");
    REQUIRE(ast[0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1].getValue().value == "3");
}

TEST_CASE("Parser5", "") {
    std::string program = "(5+3)/2*4";
    Lexer lexer{ program };
    Parser parser{ lexer.getTokens() };
    auto& ast = parser.getAst();
    REQUIRE(ast.getValue().type == ASTNodeType::Program);
    REQUIRE(ast[0].getValue().type == ASTNodeType::Multiplication);
    REQUIRE(ast[0][0].getValue().type == ASTNodeType::Division);
    REQUIRE(ast[0][0][0].getValue().type == ASTNodeType::Addition);
    REQUIRE(ast[0][0][0][0].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][0][0].getValue().value == "5");
    REQUIRE(ast[0][0][0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][0][1].getValue().value == "3");
    REQUIRE(ast[0][0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][0][1].getValue().value == "2");
    REQUIRE(ast[0][1].getValue().type == ASTNodeType::Integer_Literal);
    REQUIRE(ast[0][1].getValue().value == "4");
}
