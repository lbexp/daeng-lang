#ifndef EMITTER_H
#define EMITTER_H

#include <string>

class Emitter {
  public:
    Emitter(std::string path);

    void write();

  private:
    std::string filePath;
    std::string header;
    std::string code;

    void emit(std::string cd);
    void emitLine(std::string cd);
    void headerLine(std::string cd);
};

#endif
