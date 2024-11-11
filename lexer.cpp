#include "lexer.h"
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

    char curChars[2] = "";
    curChars[0] = curChar;

    if (peek() == '=') {
        nextChar();
        curChars[1] = curChar;
    }

    Token token(curChars);
    if (!token.type) {
        abort((char *)"Unknown token");
    }

    nextChar();

    return token;
}

void Lexer::abort(char *msg) { throw std::runtime_error(msg); }

void Lexer::skipWhitespace() {
    while (curChar == ' ' || curChar == '\t') {
        nextChar();
    }
}
