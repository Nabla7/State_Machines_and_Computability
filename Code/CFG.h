#ifndef CFG_H
#define CFG_H

#include <set>
#include <map>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

class CFG {
public:
    CFG(std::set<std::string> Variables,
        std::set<std::string> Terminals,
        std::map<std::string, std::vector<std::vector<std::string>>> Productions,
        std::string StartSymbol)
            : V(Variables), T(Terminals), P(Productions), S(StartSymbol) {}
    CFG(const std::string& filename);
    void print();
private:
    std::set<std::string> V; // Variables
    std::set<std::string> T; // Terminals
    std::map<std::string, std::vector<std::vector<std::string>>> P; // Productions
    std::string S; // Start Symbol
};

#endif // CFG_H
