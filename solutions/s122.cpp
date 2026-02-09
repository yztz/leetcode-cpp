#include "lib.h"

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ldis(n);
        unordered_map<long long, int> prev;
        unordered_map<long long, int> count;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (!prev.count(num)) {
                prev[num] = i; // [1,3,1,1,2]
                count[num]++;
                continue;
            }
            int prev_loc = prev[num];
            ldis[i] = (i - prev_loc) * count[num] + ldis[prev_loc];
            prev[num] = i;
            count[num]++;
        }

        vector<long long> rdis(n);
        prev.clear();
        count.clear();

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            if (!prev.count(num)) {
                prev[num] = i;
                count[num]++;
                continue;
            }
            int prev_loc = prev[num];
            rdis[i] = (prev_loc - i) * count[num] + rdis[prev_loc];
            prev[num] = i;
            count[num]++;
        }

        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = ldis[i] + rdis[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {1,3,1,1,2};
    vector v2 = {38,36,23};
    s.distance(v);
    return 0;
}
