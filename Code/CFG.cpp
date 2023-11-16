#include "CFG.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  // For std::setw

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


std::pair<std::vector<int>, std::vector<int>> combined_sequence(int n) {
    std::vector<int> increasing_sequence;
    std::vector<int> decreasing_sequence;

    // Generating increasing sequence
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            increasing_sequence.push_back(j);
        }
    }

    // Generating decreasing sequence
    for (int i = n-1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            decreasing_sequence.push_back(j);
        }
    }
    return {increasing_sequence, decreasing_sequence};
}

void print_table(const std::vector<std::vector<std::set<std::string>>>& table, int n) {
    auto indices = combined_sequence(n);

    // Step 1: Determine the maximum width for each column
    std::vector<int> max_widths(n, 0);
    int incIndex = 0, decIndex = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::ostringstream oss;
            const auto& cell = table[indices.first[incIndex]][indices.second[decIndex]];
            oss << "{";
            for (auto it = cell.begin(); it != cell.end(); ++it) {
                oss << *it;
                if (std::next(it) != cell.end()) {
                    oss << ", ";
                }
            }
            oss << "}";
            max_widths[j] = std::max(max_widths[j], static_cast<int>(oss.str().length()));
            ++incIndex;
            ++decIndex;
        }
    }

    // Step 2: Print the table with padding
    incIndex = 0, decIndex = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::ostringstream oss;
            const auto& cell = table[indices.first[incIndex]][indices.second[decIndex]];
            oss << "{";
            for (auto it = cell.begin(); it != cell.end(); ++it) {
                oss << *it;
                if (std::next(it) != cell.end()) {
                    oss << ", ";
                }
            }
            oss << "}";
            std::cout << "| " << std::left << std::setw(max_widths[j]) << oss.str();
            ++incIndex;
            ++decIndex;
        }
        std::cout << "|" << std::endl;
    }
}


bool CFG::accepts(const std::string& input) const {
    int n = input.size();
    std::vector<std::vector<std::set<std::string>>> table(n, std::vector<std::set<std::string>>(n));

    // Populate the first row
    for (int i = 0; i < n; ++i) {
        for (const auto& prod : P) {
            for (const auto& rhs : prod.second) {
                if (rhs.size() == 1 && rhs[0] == std::string(1, input[i])) {
                    table[i][i].insert(prod.first);
                }
            }
        }
    }

    // Populate the remaining rows
    for (int l = 1; l < n; ++l) {
        for (int i = 0; i < n - l; ++i) {
            int j = i + l;
            for (int k = i; k < j; ++k) {
                for (const auto& prod : P) {
                    for (const auto& rhs : prod.second) {
                        if (rhs.size() == 2 &&
                            table[i][k].count(rhs[0]) > 0 &&
                            table[k + 1][j].count(rhs[1]) > 0) {
                            table[i][j].insert(prod.first);
                        }
                    }
                }
            }
        }
    }

    print_table(table, n); // Print the table

    bool result = table[0][n - 1].count(S) > 0;

    if (result){
        std::cout << "true \n";
    } else {
        std::cout << "false \n";
    }

    // Check if the start symbol is in the top-right cell of the table
    return result;

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
