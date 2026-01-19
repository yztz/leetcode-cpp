#include "lib.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (tails.empty() || num > tails.back()) {
                tails.push_back(num);
            } else {
                int l = 0;
                int r = tails.size();
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (tails[mid] < num) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                tails[r] = num;
            }
        }
        return tails.size();
        // vector<int> dp(n);
        // for (int i = 0; i < n; i++) {
        //     dp[i] = 1;
        // }

        // for (int i = 1; i < n; i++) {
        //     int num = nums[i];
        //     for (int j = i - 1; j >= 0; j--) {
        //         if (num > nums[j]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // int ans = 1;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, dp[i]);
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
