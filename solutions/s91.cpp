#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrace(vector<int> &current, unordered_set<int> &unused, vector<int>& nums) {
        if (unused.empty()) {
            ans.push_back(current);
            return;
        }
        for (int num : nums) {
            if (unused.count(num)) {
                unused.erase(num);
                current.push_back(num);
                backtrace(current, unused, nums);
                current.pop_back();
                unused.insert(num);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> current;
        unordered_set<int> unused;
        for (int num : nums) {
            unused.insert(num);
        }
        backtrace(current, unused, nums);
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
