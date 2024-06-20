#include "LexerParser.hpp"
#include <sstream>
#include <cctype>
#include <stdexcept>



bool is_name(const std::string& s) {
    return (s == "std::cout");
}

bool is_ident_part(const char& c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

bool is_delimeter(const char& c) {
    return (c == ';' || c == '[' || c == ']' || c == '.');
}

std::list<token> lexer(const std::string& s) {
    std::list<token> tokens;
    
    return tokens;
}

void advance(std::list<token>::iterator& it, std::list<token>& tokens) {
    
}

void parser(std::list<token> tokens) {
   
}
