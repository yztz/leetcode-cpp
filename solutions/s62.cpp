#include "lib.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 2 4 3 1
        // 3 4 1 2
        int n = nums.size();
        int pos = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] >= nums[i - 1]) {
                for (int j = i; j < n; j++) {
                    if (nums[i - 1] <= nums[j]) {
                        pos = j;
                    }
                }
                swap(nums[pos], nums[i - 1]);
                pos = i - 1;
                break;
            }
        }
        sort(nums.begin() + pos, nums.end());

        // if (pos == 0) {
        //     reverse(nums.begin(), nums.end());
        // } else
        // while(pos < n - 1 && nums[pos] > nums[pos + 1]) {
        //     swap(nums[pos], nums[pos + 1]);
        //     pos++;
        // }
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
