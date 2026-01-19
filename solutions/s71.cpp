#include "lib.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;

        long long neg = 0;
        long long prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            long long num = nums[i];
            ans = max(ans, num);
            prefix *= num;
            if (prefix > 0) {
                ans = max(ans, prefix);
            } else if(prefix < 0) {
                if (neg == 0) neg = prefix;
                else ans = max(ans, prefix / neg);
            } else {
                neg = 0;
                prefix = 1;
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
