#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "token.h"

class Parser {
  public:
    Parser(Lexer *lxr);
    void program();

  private:
    Token curToken;
    Token peekToken;
    Lexer *lexer;

    bool checkToken(TokenType typ);
    bool checkPeek(TokenType typ);

    void match(TokenType typ);
    void nextToken();

    void statement();
    void expression();
    void comparison();
    void newline();

    void abort(char *msg);
};

#endif
