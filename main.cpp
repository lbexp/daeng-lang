#include "emitter.h"
#include "lexer.h"
#include "parser.h"
#include <fstream>
#include <sstream>

/**
 * This program will compile a specific source code lang into C code
 *
 * Compiler overview:
 * 1. Read source code
 * 2. Lexer -> produce tokens
 * 3. Parser -> produce program tree
 * 4. Emitter -> produce compiled code
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        throw std::runtime_error("Need argument for the file path");
        return 0;
    }

    if (argc > 2) {
        throw std::runtime_error("Too many arguments");
        return 0;
    }

    std::ifstream file;
    file.open(argv[1]);

    std::stringstream stream;
    stream << file.rdbuf();

    Lexer lexer(stream.str());
    Emitter emitter("output.c");
    Parser parser(&lexer, &emitter);

    parser.program();
    emitter.write();

    return 0;
}
