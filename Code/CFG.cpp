#include "CFG.h"
#include <iostream>

CFG::CFG() {
    V = {"BINDIGIT", "S"};
    T = {"0", "1", "a", "b"};
    P = {
            {"BINDIGIT", {"0", "1"}},
            {"S", {"", "a S b BINDIGIT"}}
    };
    S = "S";
}

void CFG::print() {
    std::cout << "V = {";
    for (auto it = V.begin(); it != V.end(); ++it) {
        if (it != V.begin()) std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "}\n";

    std::cout << "T = {";
    for (auto it = T.begin(); it != T.end(); ++it) {
        if (it != T.begin()) std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "}\n";

    std::cout << "P = {\n";
    for (const auto& prod : P) {
        for (const auto& rhs : prod.second) {
            std::cout << "    " << prod.first << " -> ";
            if (rhs.empty()) {
                std::cout << "``\n";  // Using double backticks for an empty string
            } else {
                std::cout << "`" << rhs << "`\n"; // Wrapping in backticks
            }
        }
    }
    std::cout << "}\n";

    std::cout << "S = " << S << "\n";
}
