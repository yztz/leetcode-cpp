#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int> &a, const vector<int> & b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        vector<int> &pre = intervals[0];
        // int pre_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> &cur = intervals[i];
            if (cur[0] <= pre[1]) {
                // ans.push_back({pre[0], max(pre[1], cur[1])});
                pre[1] = max(pre[1], cur[1]);
            } else {
                ans.push_back(pre);
                pre = cur;
            }
        }
        ans.push_back(pre);
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
