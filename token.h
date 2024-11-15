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

class Token {
  public:
    Token(std::string txt, TokenType typ) {
        text = txt;
        type = typ;
    }

    static TokenType checkKeyword(std::string_view txt) {
        if (txt == "ine") {
            return LET;
        } else if (txt == "cetak") {
            return PRINT;
        } else if (txt == "ambi") {
            return INPUT;
        } else if (txt == "ine") {
            return LET;
        } else if (txt == "bemana") {
            return IF;
        } else if (txt == "bemanakalo") {
            return THEN;
        } else if (txt == "begitumo") {
            return ENDIF;
        } else if (txt == "kalo") {
            return WHILE;
        } else if (txt == "ulangi") {
            return REPEAT;
        } else if (txt == "ituji") {
            return ENDWHILE;
        }

        return UNDEFINED;
    }

    std::string text;
    TokenType type;
};

#endif
