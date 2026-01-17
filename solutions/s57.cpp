#include "lib.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, INT_MAX);
        // dp[0] = 0;
        // // for (int i = 0; i < n; i++) {
        // //     dp[i][i] = 0;
        // // }
        // // for (int i = 1; i <= nums[0]; i++) {
        // //     dp[0][i] = 1;
        // // }
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (dp[j] != INT_MAX && j + nums[j] >= i) {
        //             dp[i] = min(dp[i], dp[j] + 1);
        //         }
        //     }
        // }

        // return dp[n - 1];

        // [2,3,1,1,4]
        int n = nums.size();
        int ans = 0;
        int cur = 0;
        int max_right = 0;
        while(cur < n - 1) {
            if (cur + nums[cur] >= n - 1) return ans + 1;
            int next = cur;
            for (int i = cur; i <= min(cur + nums[cur], n - 1); i++) {
                if (max_right <= i + nums[i]) {
                    max_right = i + nums[i];
                    next = i;
                }
            }
            cur = next;
            ans++;
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
