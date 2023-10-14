#ifndef CFG_H
#define CFG_H

#include <set>
#include <map>
#include <string>

class CFG {
public:
    CFG();  // Default constructor with hardcoded values
    void print();

private:
    std::set<std::string> V; // Variables
    std::set<std::string> T; // Terminals
    std::map<std::string, std::set<std::string>> P; // Productions
    std::string S; // Start Symbol
};

#endif // CFG_H
