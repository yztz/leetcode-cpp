#include "lib.h"

using namespace std;

class Solution {
public:
// class Trie {
//     public:
//     Trie *children[27];
//     int idx = -1;
//     unordered_set<int> fail;
//     void add(string &word, int idx) {
//         Trie* cur = this;
//         for (char c : word) {
//             if (!cur->children[c - 'a']) {
//                 cur->children[c - 'a'] = new Trie();
//             }
//             cur = cur->children[c - 'a'];
//         }
//         cur->idx = idx;
//     }
// };
//     bool backtrace(Trie *root, Trie *cur, string &s, int i) {
//         if (cur->fail.count(i)) return false;
//         if (i == s.size()) return cur->idx != -1;
//         int idx = s[i] - 'a';
//         Trie *next = cur->children[idx];
//         bool ret = false;
//         if (next) {
//             if (next->idx != -1) {
//                 ret = backtrace(root, next, s, i + 1) || backtrace(root, root, s, i + 1);
//             } else {
//                 ret = backtrace(root, next, s, i + 1);
//             }
//         }
//         if (!ret) {
//             cur->fail.insert(i);
//         }
//         return ret;
//     }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = dp[i] || dp[j] && dict.count(s.substr(j, i - j));
                if (dp[i]) break;
            }
        }

        return dp[n];
        // Trie t;
        // for (int i = 0; i < wordDict.size(); i++) {
        //     t.add(wordDict[i], i);
        // }
        // return backtrace(&t, &t, s, 0);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
