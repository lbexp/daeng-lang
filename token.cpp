#include "token.h"

TokenType tok::checkKeyword(std::string_view txt) {
    if (txt == "ine") {
        return LET;
    } else if (txt == "pigi") {
        return GOTO;
    } else if (txt == "cetak") {
        return PRINT;
    } else if (txt == "ambi") {
        return INPUT;
    } else if (txt == "ine") {
        return LET;
    } else if (txt == "bemana") {
        return IF;
    } else if (txt == "bemanakalo") {
        return THEN;
    } else if (txt == "begitumo") {
        return ENDIF;
    } else if (txt == "kalo") {
        return WHILE;
    } else if (txt == "ulangi") {
        return REPEAT;
    } else if (txt == "ituji") {
        return ENDWHILE;
    }

    return UNDEFINED;
}
