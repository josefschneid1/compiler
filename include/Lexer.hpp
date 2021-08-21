#pragma once
#include <vector>
#include <string>
#include <stdexcept>

class UnkownTokenError : public std::runtime_error
{
public:
    UnkownTokenError(const std::string& token);
};

enum class TokenType
{
    Integer_Literal, ADD, SUB, DIV, MUL,
    Open_Bracket, Closing_Bracket, END_Program
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
    std::vector<Token> tokens;
public:
    Lexer(const std::string& input);
    const std::vector<Token>& getTokens();
};


