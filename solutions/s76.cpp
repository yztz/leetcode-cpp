#include "lib.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < n - i; j++) {
        //         if (nums[j] > nums[j + 1]) {
        //             swap(nums[j], nums[j + 1]);
        //         }
        //     }
        // }
        
        int i = 0;
        int j = -1;
        int k = n - 1;
        while (i <= k) {
            if (nums[i] == 0) { // red
                if (j != -1) {
                    swap(nums[i], nums[j]);
                    i = j + 1;
                    j = -1;
                } else {
                    i++;
                }
            } else if (nums[i] == 1) { // white
                if (j == -1) j = i;
                i++;
            } else { // blue
                swap(nums[i], nums[k]);
                k--;
            }
        }
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
