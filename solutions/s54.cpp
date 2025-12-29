#include "lib.h"

using namespace std;

class Solution {
// struct Tree : public unordered_map<char, Tree>{
//     char c;

//     Tree(char _c): c(_c) {};
//     Tree(): c(0) {};
// };
public:
    bool backtrace(string &bottom, unordered_map<char, unordered_map<char, vector<char>>> &t) {
        if (bottom.size() == 1) {
            return true;
        }
        int n = bottom.size() - 1;

        vector<vector<char>> chars(n);
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (t.count(bottom[i]) && t[bottom[i]].count(bottom[i + 1])) {
                chars[i] = t[bottom[i]][bottom[i + 1]];
            } else {
                return false;
            }
        }
        vector<string> bottoms;
        for (char c : chars[0]) {
            string s(1, c);
            bottoms.push_back(std::move(s));
        }
        int current = 1;
        while(!bottoms.empty() && current < n) {
            auto &candidates = chars[current];
            vector<string> new_bottoms;
            // pre
            for (auto &b : bottoms) {
                char pre = b[current - 1];
                if (!t.count(pre)) continue;
                for (char c : candidates) {
                    if (!t[pre].count(c)) continue;
                    new_bottoms.push_back(b + c);
                }
            }
            bottoms = std::move(new_bottoms);
            current++;
        }
        for (auto &b : bottoms) {
            if (backtrace(b, t)) {
                return true;
            }
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Tree root;
        // for (string & word : allowed) {
        //     Tree &t = root;
        //     for (char c : word) {
        //         t[c] = Tree(c);
        //         t = t[c];
        //     }
        // }
        unordered_map<char, unordered_map<char, vector<char>>> t;
        for (string & word : allowed) {
            t[word[0]][word[1]].push_back(word[2]);
        }

        return backtrace(bottom, t);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector<string> v2 = {"BCC","CDE","CEA","FFF"};
    string bottom = "BCD";
    s.pyramidTransition(bottom, v2);

    return 0;
}
