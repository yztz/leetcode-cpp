#include "lib.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int idx = 1;
        int pre_num = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != pre_num) {
                ans++;
                pre_num = nums[i];
                swap(nums[i], nums[idx]);
                idx++;
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
