#include "Parser.hpp"

Parser::Parser(const std::vector<Token>& tokens):
    tokens{tokens}, nextToken{this->tokens.begin()}, ast{ASTNode{ASTNodeType::Program, ""}}
{
    ast.addChild(parseTerm());
}

Token Parser::consume()
{
    Token t = *nextToken;
    nextToken++;
    return t;
}

std::unique_ptr<Tree<ASTNode>> Parser::parseTerm()
{
    auto leftHandSide = parseProduct();

    switch(nextToken->type)
    {
        case TokenType::ADD:
        {
            consume();
            auto rightHandSide = parseTerm();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ASTNodeType::Addition, ""});
            astnode->addChild(std::move(leftHandSide));
            astnode->addChild(std::move(rightHandSide));
            return astnode;
        }

        case TokenType::END_Program:
        break;

        default:
            throw UnexpectedToken{""};
        break;
    }

    return leftHandSide;
}

std::unique_ptr<Tree<ASTNode>> Parser::parseProduct()
{
    auto leftNumber = std::make_unique<Tree<ASTNode>>(ASTNode{ASTNodeType::Integer_Literal,consume().value});

    switch (nextToken->type)
    {
        case TokenType::MUL:
        {
            consume();
            auto rightNumber = parseProduct();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ASTNodeType::Multiplication, ""});
            astnode->addChild(std::move(leftNumber));
            astnode->addChild(std::move(rightNumber));
            return astnode;
        }
    }
    return leftNumber;
}

const Tree<ASTNode>& Parser::getAst() const
{
    return ast;
}
