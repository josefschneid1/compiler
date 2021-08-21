#pragma once
#include <vector>
#include "Lexer.hpp"
#include "Tree.hpp"
#include <string>
#include <memory>
#include <exception>

class UnexpectedToken : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

enum class ASTNodeType
{
    Addition, Subtraction, Multiplication, Division, Integer_Literal, Program
};

struct ASTNode
{
    ASTNodeType type;
    std::string value;
};

class Parser
{
    Tree<ASTNode> ast;
    std::vector<Token> tokens;
    std::vector<Token>::iterator nextToken;
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Tree<ASTNode>> parseTerm();
    std::unique_ptr<Tree<ASTNode>> parseProduct();
    Token consume();
    const Tree<ASTNode>& getAst() const;
};