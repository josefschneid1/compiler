#include "Lexer.hpp"
#include <sstream>
#include <exception>

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_space(char c)
{
    return c == ' ' || c == '\n' || c == '\t';
}

Lexer::Lexer(const std::string& input)
{
    for(int i = 0; i < input.size(); ++i)
    {
        if(is_space(input[i]))
        {
            continue;
        }
        else if(input[i] == '(')
        {
            tokens.push_back(Token{TokenType::Open_Bracket, ""});
        }
        else if(input[i] == ')')
        {
            tokens.push_back(Token{TokenType::Closing_Bracket, ""});
        }
        else if(input[i] == '+')
        {
            tokens.push_back(Token{TokenType::ADD, ""});
        }
        else if(input[i] == '-')
        {
            tokens.push_back(Token{TokenType::SUB, ""});
        }
        else if(input[i] == '*')
        {
            tokens.push_back(Token{TokenType::MUL, ""});
        }
        else if(input[i] == '/')
        {
            tokens.push_back(Token{TokenType::DIV, ""});
        }
        else if(is_digit(input[i]))
        {
            int j = i+1;
            while(j < input.size() && is_digit(input[j]))
            {
                ++j;
            }
            auto digit_str = input.substr(i,j-i);          
            std::stringstream ss{digit_str};
            int n;
            ss >> n;
            i = j - 1;
            tokens.push_back(Token{TokenType::Integer_Literal, digit_str});
        }
        else
        {
            throw UnkownTokenError{""};
        }
    }
    //tokens.push_back(Token{TokenType::END_Program, ""});
}

const std::vector<Token>& Lexer::getTokens()
{
    return tokens;
}


UnkownTokenError::UnkownTokenError(const std::string& token):
    std::runtime_error("Unkown Token: " + token)
    {}
