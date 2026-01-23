#include "lib.h"

using namespace std;

class Solution {
public:
    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int pick = l;
        int pivot = nums[pick];
        int idx = l;
        // swap(nums[l], nums[pick]);
        for (int i = l + 1; i <= r; i++) {
            if (pivot > nums[i]) {
                swap(nums[i], nums[idx + 1]);
                idx++;
            }
        }
        swap(nums[idx], nums[l]);
        quick_sort(nums, l, idx);
        quick_sort(nums, idx + 1, r);
        // int i = l - 1;
        // int j = r + 1;
        // while(i < j) {
        //     do i++; while(nums[i] < pivot);
        //     do j--; while(nums[j] > pivot);
        //     if (i < j) swap(nums[i], nums[j]);
        // }

        // quick_sort(nums, l, j);
        // quick_sort(nums, j + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
