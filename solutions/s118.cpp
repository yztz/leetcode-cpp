#include "lib.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n);
        // dp[0] = nums[0];
        int dp = nums[0];
        int ans = dp;
        for (int i = 1; i < n; i++) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
        // vector<int> prefix;
        // prefix.push_back(nums[0]);
        // for (int i = 1; i < n; i++) {
        //     prefix.push_back(prefix.back() + nums[i]);
        // }
        // int ans = nums[0];
        // int min_p = 0;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, prefix[i] - min_p);
        //     min_p = min(min_p, prefix[i]);
        // }
        // return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
