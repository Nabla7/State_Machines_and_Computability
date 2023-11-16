#include <iostream>
#include "CFG.h"


using namespace std;


#include "CFG.h"

using namespace std;

int main() {
    CFG cfg("input-cyk1.json");
    cfg.print();
    cfg.accepts("baaba");
    cfg.accepts("abba");
    return 0;
}
/*
int main() {
    CFG cfg("input.json");
    cfg.print();
    return 0;
}

//  Json Tests
#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;

using json = nlohmann::json;

int main(){
    // inlezen uit file
    ifstream input("input.json");

    json j;

    input >> j;
    // tonen op het scherm
    cout << setw(4) << j << endl;

    // manueel aanmaken
    json j2;
    j2["Variables"] = {"A", "B"};
    cout << setw(4) << j2 << endl;
    return 0;
}*/