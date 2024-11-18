#include "lexer.h"
#include "parser.h"

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
    Lexer lexer(">=#adsadad\n>\"yo\"=2=1.23kalo");
    Parser parser(&lexer);

    parser.program();

    return 0;
}
