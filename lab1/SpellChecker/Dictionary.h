#ifndef SPELLCHECKER_DICTIONARY_H
#define SPELLCHECKER_DICTIONARY_H

#include <unordered_map>
#include <memory>

using namespace std;
struct TrieNode {
    bool is_end;
    unordered_map<char, unique_ptr<TrieNode>> children;
};

class Dictionary {
    unique_ptr<TrieNode> root;
public:
    Dictionary() : root(nullptr) {}

    unique_ptr<TrieNode> getnode();

    bool search_word(const string &word) const;

    void add_word(const string &word);
};

#endif //SPELLCHECKER_DICTIONARY_H
