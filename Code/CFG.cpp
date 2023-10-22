#include "CFG.h"
#include <iostream>
#include <fstream>

CFG::CFG(const std::string& filename) {
    json j;
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    input >> j;

    V = j["Variables"].get<std::set<std::string>>();
    T = j["Terminals"].get<std::set<std::string>>();
    S = j["Start"].get<std::string>();

    for (const auto& prod : j["Productions"]) {
        std::string key = prod["head"];
        std::vector<std::string> value = prod["body"].get<std::vector<std::string>>();

        P[key].push_back(value);
    }
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
        // Sort the productions based on their length
        std::vector<std::vector<std::string>> sorted_rhs = prod.second;
        std::sort(sorted_rhs.begin(), sorted_rhs.end(),
                  [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
                      return a.size() < b.size();
                  });

        for (const auto& rhs : sorted_rhs) {
            std::cout << "    " << prod.first << " -> ";
            if (rhs.empty()) {
                std::cout << "``\n";
            } else {
                std::cout << "`";
                for (size_t i = 0; i < rhs.size(); ++i) {
                    std::cout << rhs[i];
                    if (i != rhs.size() - 1) std::cout << " ";
                }
                std::cout << "`\n";
            }
        }
    }
    std::cout << "}\n";


    std::cout << "S = " << S << "\n";
}
