#include "Dictionary.h"

unique_ptr<TrieNode> Dictionary::getnode() {
    auto node = make_unique<TrieNode>();
    node->is_end = false;
    return node;
}

void Dictionary::add_word(string word) {
    if (root == nullptr) {
        root = getnode();
    }
    auto ptr = root.get();
    for (char letter : word) {
        auto it = ptr->children.find(letter);
        if (it == ptr->children.end()) {
            ptr->children[letter] = getnode();
        }
        ptr = ptr->children[letter].get();
    }
    ptr->is_end = true;
}

bool Dictionary::search_word(string word) {
    if (root == nullptr) {
        return false;
    }
    auto ptr = root.get();
    for (char letter : word) {
        if (ptr->children[letter] == nullptr) {
            return false;
        }
        ptr = ptr->children[letter].get();
    }
    if (ptr->is_end)
        return true;
    return false;
}