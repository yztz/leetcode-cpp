#include "lib.h"

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int pre = prices[0];
        int n = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == pre - 1) {
                n++;
            } else {
                for (int j = 1; j <= n; j++) {
                    ans += n - j + 1;
                }
                n = 1;
            }
            pre = prices[i];
        }
        for (int j = 1; j <= n; j++) {
            ans += n - j + 1;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector v = {3,2,1,4};
    vector v2 = {38,36,23};
    s.getDescentPeriods(v);
    return 0;
}
