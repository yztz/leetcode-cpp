#include "lib.h"

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev_cnt = 0;
        int cur_cnt = 1;
        int n = nums.size();
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur_cnt++;
            } else {
                ans = max(ans, min(cur_cnt, prev_cnt));
                ans = max(ans, cur_cnt / 2);
                prev_cnt = cur_cnt;
                cur_cnt = 1;
            }
        }
        ans = max(ans, min(cur_cnt, prev_cnt));
        ans = max(ans, cur_cnt / 2);

        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
