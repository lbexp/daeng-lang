#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "token.h"

class Parser {
  public:
    Parser(Lexer lexer);

  private:
    bool checkToken(Token token);
    bool checkPeek(Token token);
    void match();
    void nextToken();
    void abort();
};

#endif
