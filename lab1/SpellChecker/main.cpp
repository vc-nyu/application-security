#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    Dictionary dictionary;
    vector<string> errors;
    string term;
    ifstream in;
    ofstream out;
    in.open(argv[1]);
    if (!in)
        cout << "error while opening words file" << endl;
    while (in >> term) {
        transform(term.begin(), term.end(), term.begin(), ::tolower);
        dictionary.add_word(term);
    }
    in.close();
    in.open(argv[2]);
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
    out.open(argv[3], ios::out);
    if (!out)
        cout << "error while opening results file" << endl;
    if (errors.empty())
        out << "NO Spelling mistakes found" << endl;
    else {
        out << "Spelling mistakes found:" << endl;
        cout << "Spelling mistakes found:" << endl;
        for (const string &error : errors) {
            out << error << endl;
            cout << error << endl;
        }

    }
    out.close();
    return 0;
}