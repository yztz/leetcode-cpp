#include "lib.h"
#include <algorithm>
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        // sort(potions.begin(), potions.end());
        // for (auto spell : spells) {
        //     long long target = success / spell + (success % spell != 0);
        //     int left = 0, right = potions.size();
        //     while (left < right) {
        //         int mid = left + (right - left) / 2;
        //         if (potions[mid] >= target) {
        //             right = mid;
        //         } else {
        //             left = mid + 1;
        //         }
        //     }
        //     ans.push_back(potions.size() - left);
        // }
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
        });
        sort(spells.begin(), spells.end());
        sort(potions.begin(), potions.end());
        int j = potions.size() - 1;
        int i;
        for (i = 0; i < spells.size(); i++) {
            int p = idx[i];
            while (j >= 0 && (long long)spells[i] * potions[j] >= success) {
                j--;
            }
            ans[p] = potions.size() - j - 1;
        }


        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    auto ans = s.successfulPairs(v,v2, 328);
    // s.avoidFlood(v);
    // std::cout <<  << endl;
    return 0;
}
