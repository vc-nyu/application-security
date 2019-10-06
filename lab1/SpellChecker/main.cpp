#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Dictionary.h"

using namespace std;

int main() {
    Dictionary dictionary;
    vector<string> errors;
    string term;
    ifstream in;
    ofstream out;
    in.open("data/words.txt");
    if (!in)
        cout << "error while opening words file" << endl;
    while (in >> term) {
        transform(term.begin(), term.end(), term.begin(), ::tolower);
        dictionary.add_word(term);
    }
    in.close();
    in.open("data/test.txt");
    if (!in)
        cout << "error while opening test file" << endl;
    while (in >> term) {
        transform(term.begin(), term.end(), term.begin(), ::tolower);
        char last_letter = term.back();
        if (!isalnum(last_letter))
            term = term.substr(0, term.size() - 1);
        if (!dictionary.search_word(term))
            errors.push_back(term);
    }
    in.close();
    out.open("data/result.txt");
    if (!out)
        cout << "error while opening results file" << endl;
    if (errors.empty())
        out << "NO Spelling mistakes found" << endl;
    else {
        out << "Spelling mistakes found:" << endl;
        for (string error : errors)
            out << error << endl;
    }
    out.close();
    return 0;
}