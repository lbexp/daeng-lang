#include "lexer.h"
#include <iostream>
#include <stdexcept>

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

    char curChars[2] = "";
    curChars[0] = curChar;

    if (peek() == '=') {
        nextChar();
        curChars[1] = curChar;
    }

    Token token(curChars);
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
