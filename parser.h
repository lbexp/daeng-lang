#ifndef PARSER_H
#define PARSER_H

#include "emitter.h"
#include "lexer.h"
#include "token.h"

class Parser {
  public:
    Parser(Lexer *lxr, Emitter *emtr);
    void program();

  private:
    Token curToken;
    Token peekToken;
    Lexer *lexer;
    Emitter *emitter;

    bool checkToken(TokenType typ);
    bool checkPeek(TokenType typ);

    void match(TokenType typ);
    void nextToken();

    void statement();
    void expression();
    void comparison();
    void term();
    void unary();
    void primary();

    bool isComparisonOperator();

    void newline();

    void abort(char *msg);
};

#endif
