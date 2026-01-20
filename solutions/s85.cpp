#include "lib.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int ans_count = 1;
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num == ans) {
                ans_count++;
            } else {
                if (ans_count == 0) {
                    ans = num;
                    ans_count = 1;
                } else {
                    ans_count--;
                }
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
