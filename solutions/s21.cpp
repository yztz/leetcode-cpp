#include "lib.h"

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        int ans = 1;
        int min = pre - k;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                if (min < nums[i] + k) {
                    min++;
                    ans++;
                }
            } else {
                min = std::max(min + 1, nums[i] - k);
                ans++;
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
