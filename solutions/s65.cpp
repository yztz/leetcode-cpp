#include "lib.h"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp[c]
        // dp[c] = min(c, dp[c - j] + dp[j])

        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= 100; i++) {
            if (i * i > n) break;
            dp[i * i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
            }
        }
        return dp[n];

        // if (sq_cache.count(n)) return sq_cache[n];
        // int ans = n;
        // for (int c : complete) {
        //     if (c > n) break;
        //     ans = min(ans, numSquares(n - c) + 1);
        // }

        // sq_cache[n] = ans;
        // return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
