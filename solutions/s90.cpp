#include "lib.h"

using namespace std;

class Solution {
public:
class Trie {
    vector<Trie *> children;
    bool is_word = false;

public:
    Trie(): children(26) { }
    
    void insert(string word) {
        Trie *t = this;
        for (char c : word) {
            c = c - 'a';
            if (t->children[c]) {
                t = t->children[c];
            } else {
                t = t->children[c] = new Trie();
            }
        }
        t->is_word = true;
    }
    
    bool search(string word) {
        Trie *t = this;
        for (char c : word) {
            c = c - 'a';
            if (t->children[c]) {
                t = t->children[c];
            } else {
                return false;
            }
        }
        return t->is_word == true;
    }
    
    bool startsWith(string prefix) {
        Trie *t = this;
        for (char c : prefix) {
            c = c - 'a';
            if (t->children[c]) {
                t = t->children[c];
            } else {
                return false;
            }
        }
        return true;
    }
};
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
