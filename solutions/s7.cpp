#include "lib.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = n - 1; k > 1; k--) {
            for (int i = k - 2; i >= 0; i--) {
                if (nums[i] + nums[k-1] > nums[k]) {
                    return nums[i] + nums[k-1] + nums[k];
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    return 0;
}
