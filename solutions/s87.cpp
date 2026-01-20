#include "lib.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int l = 0;
        int r = n -1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;

        // vector<vector<int>> dp(n, vector<int>(n));
        // vector<int> dp2(n);

        // for (int i = 0; i < n - 1; i++) {
        //     // dp[i][i] = 0;
        //     dp2[i] = 0;
        // }
        // int ans = 0;
        // for (int step = 1; step < n; step++) {
        //     for (int i = 0; i + step < n; i++) {
        //         // dp[i][i + step] = max(min(height[i], height[i + step]) * step, dp[i][i+step-1]);
        //         // ans = max(ans, dp[i][i + step]); 
        //         dp2[i] = max(min(height[i], height[i + step]) * step, dp2[i]);
        //         ans = max(ans, dp2[i]);
        //     }
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
