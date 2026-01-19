#include "lib.h"

using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if (cache.count(n)) return cache[n];
        if (n == 2) return 2;
        if (n == 1) return 1;
        int ans = climbStairs(n - 2) + climbStairs(n - 1);
        cache[n] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
