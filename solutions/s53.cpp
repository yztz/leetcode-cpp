#include "lib.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            if (nums[i] < 0) nums[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
