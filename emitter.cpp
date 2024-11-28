#include "emitter.h"

Emitter::Emitter(std::string path) {
    filePath = path;
    header = "";
    code = "";
}

void Emitter::emit(std::string cd) { code += cd; }

void Emitter::emitLine(std::string cd) { code += '\n'; }

void Emitter::headerLine(std::string cd) { header += '\n'; }

void Emitter::write() {
    // TODO: Add logic for outputing to file
}
