#include "lib.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> target;
        unordered_map<char, int> window;
        vector<int> loc;
        for (char c : t) {
            target[c]++;
        }
        for (int i = 0; i < m; i++) {
            if (target.count(s[i])) loc.push_back(i);
        }

        int ans_idx = -1;
        int ans_n;
        int l_idx = 0;
        int r_idx = -1;
        int pair = 0;
        while (r_idx < (int)loc.size()) {
            if (pair < target.size()) {
                r_idx++;
                if(r_idx == loc.size()) break;
                char rc = s[loc[r_idx]];
                window[rc]++;
                if (window[rc] == target[rc]) pair++;
            } else {
                int len = loc[r_idx] - loc[l_idx] + 1;
                if(ans_idx == -1 || len < ans_n) {
                    ans_n = len;
                    ans_idx = loc[l_idx];
                }
                char lc = s[loc[l_idx]];
                if (window[lc] == target[lc]) pair--;
                window[lc]--;
                l_idx++;
            }
        }

        return ans_idx == -1 ? "" : s.substr(ans_idx, ans_n);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    s.minWindow("a", "a");

    return 0;
}
