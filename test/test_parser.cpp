#include "catch2/catch.hpp"
#include "Parser.hpp"
#include "Lexer.hpp"
#include <string>

TEST_CASE("Parser1", "") {
    std::string program = "5+3*2";
    Lexer lexer{program};
    Parser parser{lexer.getTokens()};
    //auto& ast = parser.getAst();
    //REQUIRE(ast[0].getValue().type == ASTNodeType::Program);
    //REQUIRE(ast[0][0].getValue().type == ASTNodeType::Addition);

}