#ifndef TOKEN_H
#define TOKEN_H

enum TokenType {
    EOF = -1,
    NEWLINE = 0,
    NUMBER = 1,
    INDENT = 2,
    STRING = 3,
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
    Token(char txt) {
        if (txt == '+') {
            type = PLUS;
        } else if (txt == '-') {
            type = MINUS;
        } else if (txt == '*') {
            type = ASTERISK;
        } else if (txt == '/') {
            type = SLASH;
        } else if (txt == '\n') {
            type = NEWLINE;
        } else if (txt == '\0') {
            type = EOF;
        } else {
            // Do nothing
            return;
        }

        text = txt;
    }

    char text;
    TokenType type;
};

#endif
