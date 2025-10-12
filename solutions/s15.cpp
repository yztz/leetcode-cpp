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
    unordered_map<uint64_t, int> mem[31];

    int count_k(uint64_t bit_set) {
        int ret = 0;
        while (bit_set) {
            ret += bit_set % 2;
            bit_set /= 2;
        }
        return ret;
    }
    uint64_t dfs(int m, int k, vector<int>& nums, uint64_t bit_set) {
        if (mem[m].count(bit_set)) {
            return mem[m][bit_set];
        }
        int ck = count_k(bit_set);
        if (m == 0) {
            return ck == k ? 1 : 0;
        }

        uint64_t ans = 0;

        if (ck == k) {
            ans = 1;
        }

        int n = nums.size();
        const uint64_t MOD = 1000000000ULL + 7;

        for (int i = 0; i < n; i++) {
            ans = (ans + (nums[i] * dfs(m - 1, k, nums, bit_set + (1 << i))) % MOD) % MOD;
        }


        mem[m][bit_set] = ans % MOD;
        return ans % MOD;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        return dfs(m, k, nums, 0);
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
