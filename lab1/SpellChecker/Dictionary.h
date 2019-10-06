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
    Dictionary() : root(make_unique<TrieNode>()) {}

    unique_ptr<TrieNode> getnode();

    bool search_word(string word);

    void add_word(string word);
};

#endif //SPELLCHECKER_DICTIONARY_H
