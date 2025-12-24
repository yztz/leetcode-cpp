#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> t;
        for (int num: nums) {
            t[num]++;
        }

        for (auto it1 = t.begin(); it1 != t.end(); ++it1) {
            int n1 = it1->first;
            int n1_cnt = it1->second;
            if (n1_cnt >= 2) {
                if (n1 == 0 && n1_cnt >= 3) ans.push_back({0, 0, 0});
                if (-2*n1 > n1 && t.count(-2*n1)) ans.push_back({n1, n1, -2*n1});
            }
            for (auto it2 = t.begin(); it2 != it1; ++it2) {
                int n2 = it2->first;
                if (n2 >= 0) break;
                if (-n2-n1 == n1 && n1_cnt >= 2) ans.push_back({n1, n1, n2});
                if (-n2-n1 > n1 && t.count(-n2-n1)) ans.push_back({n1, n2, -n2-n1});
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector v = {1,1,-2};
    vector v2 = {38,36,23};
    s.threeSum(v);
    return 0;
}
