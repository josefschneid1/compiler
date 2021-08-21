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

Token Parser::consume(TokenType type)
{
    if (nextToken->type != type)
        throw UnexpectedToken{""};
    Token t = *nextToken;
    nextToken++;
    return t;
}

std::unique_ptr<Tree<ASTNode>> Parser::parseTerm()
{
    auto leftOperand = parseProduct();

    switch(nextToken->type)
    {
        case TokenType::ADD:
        {
            consume();
            auto rightOperand = parseTerm();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ASTNodeType::Addition, ""});
            astnode->addChild(std::move(leftOperand));
            astnode->addChild(std::move(rightOperand));
            return astnode;
        }

        case TokenType::SUB:
        {
            consume();
            auto rightOperand = parseTerm();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ ASTNodeType::Subtraction, "" });
            astnode->addChild(std::move(leftOperand));
            astnode->addChild(std::move(rightOperand));
            return astnode;
        }

        default:
        break;
    }

    return leftOperand;
}

std::unique_ptr<Tree<ASTNode>> Parser::parseProduct()
{
    
    std::unique_ptr<Tree<ASTNode>> leftOperand;

    if (nextToken->type == TokenType::Open_Bracket)
    {
        consume();

        leftOperand = parseTerm();

        consume(TokenType::Closing_Bracket);
    }
    else
    {
        leftOperand = std::make_unique<Tree<ASTNode>>(ASTNode{ ASTNodeType::Integer_Literal,consume(TokenType::Integer_Literal).value });
    }

    switch (nextToken->type)
    {
        case TokenType::MUL:
        {
            consume();
            auto rightOperand = parseProduct();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ASTNodeType::Multiplication, ""});
            astnode->addChild(std::move(leftOperand));
            astnode->addChild(std::move(rightOperand));
            return astnode;
        }

        case TokenType::DIV:
        {
            consume();
            auto rightOperand = parseProduct();
            auto astnode = std::make_unique<Tree<ASTNode>>(ASTNode{ ASTNodeType::Division, "" });
            astnode->addChild(std::move(leftOperand));
            astnode->addChild(std::move(rightOperand));
            return astnode;
        }

        default:
            break;
    }
    return leftOperand;
}

const Tree<ASTNode>& Parser::getAst() const
{
    return ast;
}
