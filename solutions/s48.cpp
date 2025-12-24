#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> t;
        for (int i = 0; i < nums.size(); i++) {
            t.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); i++) {
            if (t.count(target - nums[i]) && t[target - nums[i]] != i) {
                return {i, t[target - nums[i]]};
            }
        }
        return {};
    }
    
};

int main() {
    Solution s;
    vector v = {-100,-70,-60,110,120,130,160};
    vector v2 = {38,36,23};

    return 0;   
}
