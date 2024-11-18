#include "parser.h"

Parser::Parser(Lexer *lxr) {
    lexer = lxr;
    Token token = lexer->getToken();

    curToken = token;
    peekToken = token;

    nextToken();
}

bool Parser::checkToken(TokenType typ) { return typ == curToken.type; };

bool Parser::checkPeek(TokenType typ) { return typ == peekToken.type; };

void Parser::match(TokenType typ) {
    if (!checkToken(typ)) {
        abort((char *)"Token not match!");
    }

    nextToken();
};

void Parser::nextToken() {
    curToken = peekToken;
    peekToken = lexer->getToken();
};

void Parser::abort(char *msg) { throw std::runtime_error(msg); }
