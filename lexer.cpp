#include "lexer.h"
#include "token.h"
#include <cctype>
#include <iostream>
#include <string>

// Constructor to initialized variables
Lexer::Lexer(std::string src) {
    source = src;
    curPos = -1;
    isProcessing = true;

    // Initial processing
    nextChar();
}

// Get to the next character
void Lexer::nextChar() {
    curPos += 1;

    if (curPos >= source.length()) {
        isProcessing = false;
        curChar = '\0';

        return;
    }

    curChar = source[curPos];
}

// Peek next character
char Lexer::peek() { return source[curPos + 1]; }

// Get generated token from curChar
Token Lexer::getToken() {
    skipWhitespace();
    skipComment();

    std::string tokenText = "";
    TokenType tokenType = UNDEFINED;

    if (curChar == '+') {
        tokenText.push_back(curChar);
        tokenType = PLUS;
    } else if (curChar == '-') {
        tokenText.push_back(curChar);
        tokenType = MINUS;
    } else if (curChar == '*') {
        tokenText.push_back(curChar);
        tokenType = ASTERISK;
    } else if (curChar == '/') {
        tokenText.push_back(curChar);
        tokenType = SLASH;
    } else if (curChar == '\n') {
        tokenText.push_back(curChar);
        tokenType = NEWLINE;
    } else if (curChar == '\0') {
        tokenText.push_back(curChar);
        tokenType = ENDOF;
    } else if (curChar == '=') {
        tokenText.push_back(curChar);

        if (peek() == '=') {
            nextChar();

            tokenText.push_back(curChar);
            tokenType = EQEQ;
        } else {
            tokenType = EQ;
        }
    } else if (curChar == '>') {
        tokenText.push_back(curChar);

        if (peek() == '=') {
            nextChar();

            tokenText.push_back(curChar);
            tokenType = GTEQ;
        } else {
            tokenType = GT;
        }
    } else if (curChar == '<') {
        tokenText.push_back(curChar);

        if (peek() == '=') {
            nextChar();

            tokenText.push_back(curChar);
            tokenType = LTEQ;
        } else {
            tokenType = LT;
        }
    } else if (curChar == '\"') {
        nextChar();

        while (curChar != '\"') {
            if (curChar == '\r' || curChar == '\n' || curChar == '\t' ||
                curChar == '\\' || curChar == '%') {
                abort((char *)"Invalid character inside string");
            }

            tokenText.push_back(curChar);
            nextChar();
        }

        tokenType = STRING;
    } else if (isdigit(curChar)) {
        tokenText.push_back(curChar);

        while (isdigit(peek())) {
            nextChar();
            tokenText.push_back(curChar);
        }

        if (peek() == '.') {
            nextChar();
            tokenText.push_back(curChar);

            while (isdigit(peek())) {
                nextChar();
                tokenText.push_back(curChar);
            }
        }

        tokenType = NUMBER;
    } else {
        tokenType = UNDEFINED;
    }

    Token token(tokenText, tokenType);
    if (!token.type) {
        std::cout << '\n'
                  << "Token: type -> " << token.type << " , text -> "
                  << token.text << std::endl;
        abort((char *)"Unknown token");
    }

    nextChar();

    return token;
}

// Exit lexer processing
void Lexer::abort(char *msg) { throw std::runtime_error(msg); }

void Lexer::skipWhitespace() {
    while (curChar == ' ' || curChar == '\t') {
        nextChar();
    }
}

void Lexer::skipComment() {
    if (curChar == '#') {
        while (curChar != '\n') {
            nextChar();
        }
    }
}
