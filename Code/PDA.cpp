#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include "json.hpp"
using json = nlohmann::json;

class PDA {
public:
    struct Transition {
        std::string from;
        std::string to;
        std::string input;
        std::string stacktop;
        std::vector<std::string> replacement;
    };

    PDA(const std::string& filename) {
        std::ifstream input(filename);
        if (!input.is_open()) {
            std::cerr << "Failed to open " << filename << std::endl;
            return;
        }
        json j;
        input >> j;
        parseJSON(j);
    }

private:
    std::vector<Transition> transitions;
    std::string startState;
    std::string startStack;
    std::set<std::string> states;
    std::set<std::string> alphabet;
    std::set<std::string> stackAlphabet;

    void parseJSON(const json& j) {
        startState = j["StartState"].get<std::string>();
        startStack = j["StartStack"].get<std::string>();
        for (const auto& state : j["States"]) {
            states.insert(state.get<std::string>());
        }
        for (const auto& sym : j["Alphabet"]) {
            alphabet.insert(sym.get<std::string>());
        }
        for (const auto& stackSym : j["StackAlphabet"]) {
            stackAlphabet.insert(stackSym.get<std::string>());
        }
        for (const auto& trans : j["Transitions"]) {
            Transition t;
            t.from = trans["from"].get<std::string>();
            t.to = trans["to"].get<std::string>();
            t.input = trans["input"].get<std::string>();
            t.stacktop = trans["stacktop"].get<std::string>();
            t.replacement = trans["replacement"].get<std::vector<std::string>>();
            transitions.push_back(t);
        }
    }
};

// Rest of the CFG class definition...

int main() {
    PDA pda("input-pda2cfg.json");
    pda.toCFG().print();
    return 0;
}
