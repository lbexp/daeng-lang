#include "parser.h"
#include "token.h"
#include <iostream>

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

void Parser::program() {
    std::cout << "PROGRAM" << std::endl;
    while (!checkToken(ENDOF)) {
        statement();
    }
}

void Parser::statement() {
    if (checkToken(PRINT)) {
        std::cout << "STATEMENT PRINT" << std::endl;
        nextToken();

        if (checkToken(STRING)) {
            nextToken();
        } else {
            expression();
        }
    }
}

void Parser::expression() { std::cout << "EXPRESSION" << std::endl; }

void Parser::newline() { std::cout << "NEW LINE" << std::endl; }

void Parser::abort(char *msg) { throw std::runtime_error(msg); }
