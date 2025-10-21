#include "lib.h"

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 1;
        int n = nums.size();
        unordered_map<int, int> count;
        for (auto num : nums) {
            if (count.count(num)) {
                count[num]++;
            } else {
                count[num] = 1;
            }
        }

        sort(nums.begin(), nums.end());
        auto lower_bound = [&](int num) -> int {
            int i = 0;
            int j = nums.size();
            while (i < j) {
                int mid = i + (j - i) / 2;
                if (nums[mid] + k >= num) {
                    j = mid; 
                } else {
                    i = mid + 1;
                }
            }
            return j;
        };

        auto upper_bound = [&](int num) -> int {
            int i = 0;
            int j = nums.size() - 1;
            while (i < j) {
                int mid = i + (j - i) / 2;
                if (nums[mid] - k <= num) {
                    i = mid;
                } else {
                    j = mid - 1;
                }
            }
            return i;
        };

        for (int cur = nums.front(); cur <= nums.back(); cur++) {
            int left = lower_bound(cur);
            int right = min(upper_bound(cur), n - 1);

            if (count.count(cur)) {
                ans = max(ans, min(numOperations + count[cur], right - left + 1));
            } else {
                ans = max(ans, min(numOperations, right - left + 1));
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
