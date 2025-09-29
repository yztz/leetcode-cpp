#include "lib.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector f(n, vector<int>(n));
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                f[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + v[i] * v[j] * v[k]);
                }
            }
        }
        return f[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> v({1,3,1,4,1,5});
    printf("%d\n", s.minScoreTriangulation(v));
    return 0;
}
