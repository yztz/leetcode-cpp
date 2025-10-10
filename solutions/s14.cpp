#include "lib.h"
#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <numeric>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = 0; i < k; i++) {
            int current = i;
            int tmp = 0;
            while (current < n) {
                if (tmp < 0) {
                    tmp = std::max(energy[current], tmp + energy[current]);
                } else {
                    tmp += energy[current];
                }
                current = current + k;
            }
            ans = std::max(ans, tmp);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    // auto ans = s.successfulPairs(v,v2, 328);
    // s.avoidFlood(v);
    // std::cout <<  << endl;
    return 0;
}
