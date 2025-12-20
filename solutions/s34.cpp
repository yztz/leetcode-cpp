#include "lib.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> loc;
        vector<int> pre; //todo
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (loc.count(c)) {
                pre.push_back(loc[c]);
            } else {
                pre.push_back(-1);
            }
            loc[c] = i;
        }
        // ...x....x...
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_set<char> dict;
        while (j < s.size()) {
            if (dict.count(s[j]) && pre[j] >= i) {
                for (int k = i; k < pre[j]; k++) {
                    dict.erase(s[k]);
                }
                i = pre[j] + 1;
            } else {
                dict.insert(s[j]);
            }
            ans = max(ans, (int)dict.size());
            j++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
