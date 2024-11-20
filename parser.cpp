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
        std::cout << "STATEMENT-PRINT" << std::endl;
        nextToken();

        if (checkToken(STRING)) {
            nextToken();
        } else {
            expression();
        }
    } else if (checkToken(IF)) {
        std::cout << "STATEMENT-IF" << std::endl;
        nextToken();
        comparison();
        match(THEN);
        newline();

        while (!checkToken(ENDIF)) {
            statement();
        }

        match(ENDIF);
    } else if (checkToken(WHILE)) {
        std::cout << "STATEMENT-WHILE" << std::endl;
        nextToken();
        comparison();
        newline();

        while (!checkToken(ENDWHILE)) {
            statement();
        }

        match(ENDWHILE);
    } else if (checkToken(LABEL)) {
        std::cout << "STATEMENT-LABEL" << std::endl;
        nextToken();
        match(IDENT);
    } else if (checkToken(GOTO)) {
        std::cout << "STATEMENT-GOTO" << std::endl;
        nextToken();
        match(IDENT);
    } else if (checkToken(LET)) {
        std::cout << "STATEMENT-LET" << std::endl;
        nextToken();
        match(IDENT);
        match(EQ);
        statement();
    } else if (checkToken(INPUT)) {
        std::cout << "STATEMENT-INPUT" << std::endl;
        nextToken();
        match(IDENT);
    } else {
        abort((char *)"Invalid statement");
    }

    newline();
}

void Parser::expression() { std::cout << "EXPRESSION" << std::endl; }

void Parser::comparison() { std::cout << "COMPARISON" << std::endl; }

void Parser::newline() { std::cout << "NEWLINE" << std::endl; }

void Parser::abort(char *msg) { throw std::runtime_error(msg); }
