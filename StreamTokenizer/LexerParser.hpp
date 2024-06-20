#ifndef LEXER_PARSER_HPP
#define LEXER_PARSER_HPP

#include <string>
#include <list>

enum states {
    H,
    OUT_OP,
    STR,
    ID,
    DLM,
    ERR
};

enum token_type {
    fn_name,  // std::cout
    str,      // quoted strings
    ident,    // identifiers
    delim,    // separator
    output_op,// output operator <<
    end       // ;
};

struct token {
    std::string value;
    token_type type;
};

bool is_name(const std::string& s);

bool is_ident_part(const char& c);

bool is_delimeter(const char& c);

std::list<token> lexer(const std::string& s);

void advance(std::list<token>::iterator& it, std::list<token>& tokens);

void parser(std::list<token> tokens);


#endif // LEXER_PARSER_HPP
