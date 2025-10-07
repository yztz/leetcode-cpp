#include "lib.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> next(n, -1);
        unordered_map<int, int> rained;
        vector<int> slots;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int target = rains[i];
            if (target == 0) {
                ans.push_back(1);
                slots.push_back(i);
            } else {
                ans.push_back(-1);
                if (rained.count(target)) {
                    if (slots.empty()) {
                        return vector<int>();
                    } else {
                        int prev_rain_day = rained[target];
                        int i = 0, j = slots.size() - 1;
                        while (i <= j) {
                            int mid = i + (j - i) / 2;
                            if (slots[mid] < prev_rain_day) {
                                i = mid + 1;
                            } else if (slots[mid] > prev_rain_day) {
                                j = mid - 1;
                            }
                        }
                        // printf("i=%d j=%d\n", i, j);
                        if (i >= n || slots[i] < prev_rain_day) {
                            return vector<int>();
                        }
                        int loc = slots[i];
                        slots.erase(slots.begin() + i);
                        ans[loc] = target;
                        rained.erase(target);
                    }
                }
                rained.insert({target, i});
            }
            
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {1,2,0,0,2,1};
    s.avoidFlood(v);
    // std::cout <<  << endl;
    return 0;
}
