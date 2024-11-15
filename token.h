#ifndef TOKEN_H
#define TOKEN_H

#include <cstring>
#include <string>

enum TokenType {
    UNDEFINED = 0,
    ENDOF = 1,
    NEWLINE = 2,
    NUMBER = 3,
    INDENT = 4,
    STRING = 5,
    // Keywords
    INE = 105,
    BEMANA = 106,
    BEMANAKALO = 107,
    BEGITUJI = 108,
    KALO = 109,
    ITUJI = 111,
    // Operators
    EQ = 201,
    PLUS = 202,
    MINUS = 203,
    ASTERISK = 204,
    SLASH = 205,
    EQEQ = 206,
    NOTEQ = 207,
    LT = 208,
    LTEQ = 209,
    GT = 210,
    GTEQ = 211,
};

class Token {
  public:
    Token(std::string txt, TokenType typ) {
        text = txt;
        type = typ;
    }

    std::string text;
    TokenType type;
};

#endif
