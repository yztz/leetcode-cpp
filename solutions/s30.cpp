#include "lib.h"

using namespace std;

class Solution {
public:
    //  0 0 0 1 1 1
    //  1 1 1 1 1 1
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const int k_2 = k / 2;
        long long ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            ans += strategy[i] * prices[i];
        }
        long long pre_old = 0;
        long long pre_new = 0;
        long long delta = 0;
        for (int i = 0; i < prices.size() - k + 1; i++) {
            int j = i + k - 1;
            int m = i + k / 2 - 1;
            if (i == 0) {
                for (int t = 0; t < k; t++) {
                    pre_old = pre_old + prices[t] * strategy[t];
                    if(t >= k / 2) pre_new = pre_new + prices[t];
                }
            } else {
                pre_old = pre_old + prices[j] * strategy[j] - prices[i - 1] * strategy[i - 1];
                pre_new = pre_new + prices[j] - prices[m];
            }
            delta = std::max(delta, pre_new - pre_old);
        }

        return ans + delta;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
