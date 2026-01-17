#include "lib.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;

        const int dir[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };

        queue<pair<int, int>> bad;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    bad.push(make_pair(i, j));
                }
            }
        }

        while(!bad.empty() && fresh > 0) {
            int count = bad.size();
            while (count > 0) {
                auto pos = bad.front();
                bad.pop();
                for (int i = 0; i < 4; i++) {
                    int newx = pos.first + dir[i][0];
                    int newy = pos.second + dir[i][1];
                    if (newx >= 0 && newx < m && newy >= 0 && newy <= n) {
                        if (grid[newx][newy] == 1) {
                            grid[newx][newy] = 2;
                            fresh--;
                            bad.push(make_pair(newx, newy));
                        }
                    }
                }
                count--;
            }

            if (fresh == 0) return ans;

            ans++;
        }

        return fresh > 0 ? -1 : ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
