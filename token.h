#ifndef TOKEN_H
#define TOKEN_H

#include <cstring>

enum TokenType {
    UNDEFINED = 0,
    EOF = 1,
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
    Token(char txt[2]) {
        if (txt[0] == '+') {
            type = PLUS;
        } else if (txt[0] == '-') {
            type = MINUS;
        } else if (txt[0] == '*') {
            type = ASTERISK;
        } else if (txt[0] == '/') {
            type = SLASH;
        } else if (txt[0] == '\n') {
            type = NEWLINE;
        } else if (txt[0] == '\0') {
            type = EOF;
        } else if (txt[0] == '=') {
            if (txt[1] == '=') {
                type = EQEQ;
            } else {
                type = EQ;
            }
        } else if (txt[0] == '>') {
            if (txt[1] == '=') {
                type = GTEQ;
            } else {
                type = GT;
            }
        } else if (txt[0] == '<') {
            if (txt[1] == '=') {
                type = LTEQ;
            } else {
                type = LT;
            }
        } else {
            type = UNDEFINED;
            return;
        }

        strncpy(text, txt, 2);
    }

    char text[2];
    TokenType type;
};

#endif
