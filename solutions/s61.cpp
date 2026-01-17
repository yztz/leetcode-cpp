#include "lib.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_r = nums[0];
        int from = 0;
        int n = nums.size();

        while(max_r < n - 1) {
            bool flag = false;
            for (int i = from + 1; i <= from + nums[from] && i < n; i++) {
                if (i + nums[i] >= max_r) {
                    max_r = i + nums[i];
                    flag = true;
                    from = i;
                    break;
                }
            }
            if (!flag) break;
        }

        return max_r >= n - 1;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
