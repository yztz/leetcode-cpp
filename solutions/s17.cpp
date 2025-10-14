#include "lib.h"

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0;
        while (cur <= n - 2 * k) {
            int i;
            for (i = cur + 1; i < cur + k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    break;
                }
            }
            if (i != cur + k) {
                cur = i;
                continue;
            }
            for (i = i + 1; i < cur + 2 * k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    break;
                }
            }
            if (i != cur + 2 * k) {
                cur = i - k;
                continue;
            }
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
