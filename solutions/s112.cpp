#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        if (nums.empty()) {
            return ans; 
        }
        int n = nums.size();
        int i = 0;
        int j = n;

        // 0 2 8 10 24 30
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        if (j >= n || nums[j] != target) {
            return ans;
        }
        ans[0] = j;
        i = j;
        j = n;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        ans[1] = nums[i - 1];
        
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
