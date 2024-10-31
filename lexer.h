#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>

class Lexer {
  public:
    Lexer(std::string src);

    char curChar;
    bool isProcessing;

    void nextChar();
    Token getToken();

  private:
    std::string source;
    int curPos;

    char peek();
    void skip();
    void abort(char *txt);
};

#endif
