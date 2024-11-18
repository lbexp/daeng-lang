#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    UNDEFINED = 0,
    ENDOF = 1,
    NEWLINE = 2,
    NUMBER = 3,
    INDENT = 4,
    STRING = 5,
    // Keywords
    LABEL = 101,
    GOTO = 102,
    PRINT = 103,
    INPUT = 104,
    LET = 105,
    IF = 106,
    THEN = 107,
    ENDIF = 108,
    WHILE = 109,
    REPEAT = 110,
    ENDWHILE = 111,
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

struct Token {

    std::string text;
    TokenType type;
};

TokenType checkKeyword(std::string_view txt);

#endif
