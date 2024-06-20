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
    states state = H;
    token _token;
    std::list<token> tokens;
    size_t idx = 0;

    while (idx < s.size()) {
        switch (state) {
        case H: {
            while (isspace(s[idx]) && idx < s.size()) ++idx;

            if (is_ident_part(s[idx]) || (s[idx] == ':' && s[idx + 1] == ':')) state = ID;
            else if (s[idx] == '"') state = STR;
            else if (s[idx] == '<' && s[idx + 1] == '<') {
                state = OUT_OP;
                idx++;
            }
            else if (is_delimeter(s[idx])) state = DLM;
            else state = ERR;

            break;
        }

        case OUT_OP: {
            _token.type = output_op;
            _token.value = "<<";
            tokens.push_back(_token);
            ++idx;
            state = H;
            break;
        }

        case STR: {
            std::string tmp = "\"";
            ++idx;
            while (s[idx] != '"' && idx < s.size())
                tmp += s[idx++];
            ++idx;
            tmp += "\"";

            _token.type = str;
            _token.value = tmp;
            tokens.push_back(_token);
            state = H;
            break;
        }

        case ID: {
            std::string tmp;
            while ((is_ident_part(s[idx]) || s[idx] == ':' || s[idx] == '[' || s[idx] == ']') && idx < s.size()) {
                tmp += s[idx++];
                if (s[idx - 1] == ':' && s[idx] == ':') {
                    tmp += s[idx++];
                }
            }

            if (is_name(tmp)) _token.type = fn_name;
            else {
                if (isdigit(tmp[0])) throw std::runtime_error("Variable name cannot start with digit");
                _token.type = ident;
            }

            _token.value = tmp;
            tokens.push_back(_token);
            state = H;
            break;
        }

        case DLM: {
            if (s[idx] == ';') _token.type = end;
            else _token.type = delim;
            _token.value = s[idx++];
            tokens.push_back(_token);
            state = H;
            break;
        }

        case ERR: {
            std::ostringstream o("Unknown character in position ", std::ios::app);
            o << idx + 1;
            throw std::runtime_error(o.str());
            break;
        }
        }
    }

    return tokens;
}

void advance(std::list<token>::iterator& it, std::list<token>& tokens) {
    std::advance(it, 1);
    if (it == tokens.end()) throw std::runtime_error("String is incomplete!");
}

void parser(std::list<token> tokens) {
    if (tokens.empty()) throw std::runtime_error("Empty string!");

    std::list<token>::iterator it = tokens.begin();

    if (it->type != fn_name) throw std::runtime_error("Expected std::cout instead " + it->value);

    advance(it, tokens);

    if (it->type != output_op) throw std::runtime_error("Expected << instead " + it->value);

    advance(it, tokens);

    if (!(it->type == str || it->type == ident)) throw std::runtime_error("Parameter value must be a string or a variable");

    advance(it, tokens);

    while (it != tokens.end() && it->type == output_op) {
        advance(it, tokens);
        if (!(it->type == str || it->type == ident)) throw std::runtime_error("Parameter value must be a string or a variable");
        advance(it, tokens);
    }

    if (it == tokens.end() || it->type != end) throw std::runtime_error("Expected ; at the end");
}
