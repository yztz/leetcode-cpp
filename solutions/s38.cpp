#include "lib.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if (nums.size() == 1) return nums[0];
        // vector<int> prefix_add;
        int cur = 0;
        int cmin = 0;
        // int cmax = INT_MIN;
        int ans = INT_MIN;
        for (int num : nums) {
            cur += num;
            ans = max(ans, cur - cmin);
            cmin = min(cmin, cur);
            // cmax = max(cmax, cur);
            // prefix_add.push_back(cur);
            // ans = max(ans, num);
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
