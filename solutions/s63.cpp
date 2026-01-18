#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int np = p.size();
        int ns = s.size();
        vector<int> ans;

        if (ns < np) return ans;
        int l = 0;
        int r = -1;
        int target[26] = {0};
        int cur[26] = {0};
        for (int i = 0; i < np; i++) {
            target[p[i] - 'a']++;
        }

        while (r + 1 < ns) {
            r++;
            if (r - l + 1 > np) {
                int idx_l = s[l] - 'a';
                cur[idx_l]--;
                l++;
            }
            // int idx_l = s[l] - 'a';
            int idx_r = s[r] - 'a';
            // cur[idx_l]++;
            cur[idx_r]++;
            int i;
            for (i = 0; i < 26; i++) {
                if (cur[i] != target[i]) {
                    break;
                }
            }
            if (i == 26) {
                ans.push_back(l);
            }
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
