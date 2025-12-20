#include "lib.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int cur = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         cur += nums[j];
        //         if (cur == k) ans++;
        //     }
        // }
        int ans = 0;
        vector<int> pre;
        unordered_map<int, int> table;
        table[0] = 1;
        pre.push_back(0);
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            pre.push_back(cur);
            int target = cur - k;
            ans += table[target];
            table[cur]++;
        }
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j <= nums.size(); j++) {
        //         if (pre[j] - pre[i] == k) ans++;
        //     }
        // }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
