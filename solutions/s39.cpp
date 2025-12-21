#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        int cur_pre = 1, cur_suf = 1;
        for (int i = 0; i < n; i++) {
            cur_pre *= nums[i];
            prefix[i] = cur_pre;
            cur_suf *= nums[n - i - 1];
            suffix[n - i - 1] = cur_suf;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans.push_back(suffix[i + 1]);
            } else if (i == n - 1) {
                ans.push_back(prefix[i - 1]);
            } else {
                ans.push_back(prefix[i - 1] * suffix[i + 1]);
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
