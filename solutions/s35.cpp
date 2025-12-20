#include "lib.h"

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // unordered_set<int> deleted;
        unordered_set<int> greater;
        int pos = 0;
        int n = strs[0].size();
        int ans = 0;

        while(pos < n && greater.size() != strs.size()) {
            char pre = strs[0][pos];
            vector<int> tmp;
            int i = 1;
            for (i = 1; i < strs.size(); i++) {
                char c = strs[i][pos];
                if (greater.count(i)) {
                    pre = c;
                    continue;
                }
                if (c > pre) {
                    tmp.push_back(i);
                    pre = c;
                } else if (c < pre) {
                    ans++;
                    break;
                }
            }
            if (i == strs.size()) {
                greater.insert(tmp.begin(), tmp.end());
            }
            pos++;
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
