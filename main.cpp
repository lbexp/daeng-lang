#include "lexer.h"
#include "token.h"
#include <iostream>

/**
 * This program will compile a specific source code lang into C code
 *
 * Compiler overview:
 * 1. Read source code
 * 2. Lexer -> produce tokens
 * 3. Parser -> produce program tree
 * 4. Emitter -> produce compiled code
 */
int main() {
    Lexer lexer(">=#adsadad\n>");

    while (lexer.isProcessing) {
        Token token = lexer.getToken();
        std::cout << token.text << " -> " << token.type << std::endl;
    }

    return 0;
}
