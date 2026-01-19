#include "lib.h"

using namespace std;

class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>{}(p.first) ^ hash<int>{}(p.second);
        }
    };
    unordered_map<pair<int, int>, int, pair_hash> cache;
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        auto loc = make_pair(m, n);
        if (cache.count(loc)) return cache[loc];
        int ans = 0;
        if (m != 1) ans += uniquePaths(m - 1, n);
        if (n != 1) ans += uniquePaths(m, n - 1);
        cache[loc] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
