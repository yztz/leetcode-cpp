#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int r_bound = n - 1;
        int b_bound = m - 1;
        int l_bound = 0;
        int t_bound = 0;
        int dirs[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        };
        int x = 0;
        int y = 0;
        int dir = 0;
        // 3
        // 2
        while (true) {
            ans.push_back(matrix[x][y]);
    
            if (dir == 0 && y == r_bound) {
                t_bound++;
                dir = 1;
            } else if (dir == 1 && x == b_bound) {
                r_bound--;
                dir = 2;
            } else if (dir == 2 && y == l_bound) {
                b_bound--;
                dir = 3;
            } else if (dir == 3 && x == t_bound) {
                l_bound++;
                dir = 0;
            }

            x = x + dirs[dir][0];
            y = y + dirs[dir][1];

            if (x > b_bound || x < t_bound || y > r_bound || y < l_bound) {
                break;
            }

        }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
