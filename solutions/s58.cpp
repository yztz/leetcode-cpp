#include "lib.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 1 1 2 3 3 = 10 5
        // 1 2 2 3 = 8 4
        // 3,3,3,4,5 = 18 9
        int n = nums.size();
        if (n == 1) return false; 
        int sum = 0;
        int odd = 0;
        int even = 0;
        for (int num : nums) {
            sum += num;
            if (num % 2) odd++;
            else even++;
        }
        if (sum % 2) return false;
        int c = sum / 2;
        sort(nums.begin(), nums.end());
        if (nums[n - 1] > c) return false;
        vector<vector<bool>> dp(n, vector<bool>(c + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            dp[i][nums[i]] = true;
            for (int j = 1; j <= c; j++) {
                if (nums[i] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i]] | dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][c];
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
