#include "lib.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        
        for (int i = 1; i <= n; i++) {
            if (coins[i - 1] > amount) break;
            dp[i][coins[i - 1]] = 1;
        }

        for (int j = 1; j <= amount; j++) {
            dp[0][j] = INT_MAX;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = INT_MAX;
                int k = 0;
                while (k * coins[i - 1] <= j) {
                    if (dp[i - 1][j - k * coins[i - 1]] != INT_MAX)  
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i - 1]] + k);
                    k++;
                }
            }
            
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
