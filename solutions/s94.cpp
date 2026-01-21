#include "lib.h"

using namespace std;

class Solution {
public:
    // [3,2,1,5,6,4] k = 2
    // 
    int quick_sort(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        // int pick = start + rand() % (end - start);
        int pick = left;
        int pivot = nums[pick];
        int l = left - 1;
        int r = right + 1;
        while(l < r) {
            do l++; while(pivot < nums[l]);
            do r--; while(pivot > nums[r]);
            if (l < r) swap(nums[l], nums[r]);
        }

        if (k <= r - left + 1) {
            return quick_sort(nums, left, r, k);
        } else {
            return quick_sort(nums, r + 1, right, k - (r - left + 1));
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k);
    }
};

int main() {
    Solution s;
    vector v = {3,2,1,5,6,4};
    vector v2 = {38,36,23};
    s.findKthLargest(v, 2);
    return 0;
}
