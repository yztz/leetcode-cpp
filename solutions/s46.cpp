#include "lib.h"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        nums.insert(nums.end(), nums.begin(), nums.begin() + n - k);
        nums.erase(nums.begin(), nums.begin() + n - k);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
