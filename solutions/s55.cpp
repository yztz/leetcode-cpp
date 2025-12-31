#include "lib.h"

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int nrow = grid.size();
        int ncol = grid[0].size();
        int row = 0;

        while (row <= nrow - 3) {
            int col = 0;
            
            while (col <= ncol - 3) {
                int prev_row_sum = -1;
                int prev_col_sum = -1;
                int dia1_sum = 0;
                int dia2_sum = 0;
                int bit_map = 0;
                for (int i = 0; i < 3; i++) {
                    int row_sum = 0;
                    int col_sum = 0;
                    dia1_sum += grid[row + i][col + i];
                    dia2_sum += grid[row + i][col + 2 - i];
                    for (int j = 0; j < 3; j++) {
                        int col_num = grid[row + i][col + j];
                        if (col_num > 9 || col_num < 1) {
                            col = col + j;
                            goto next_col;
                        }
                        if (bit_map & (1 << col_num)) {
                            goto next_col;
                        } else {
                            bit_map |= (1 << col_num);
                        }
                        row_sum += col_num;
                        
                        int row_num = grid[row + j][col + i];
                        if (row_num > 9 || row_num < 1) {
                            col = col + i;
                            goto next_col;
                        }
                        col_sum += row_num;
                    }
                    if (prev_row_sum != -1 && prev_row_sum != row_sum ||
                        prev_col_sum != -1 && prev_col_sum != col_sum) {
                        goto next_col;
                    }
                    prev_col_sum = col_sum;
                    prev_row_sum = row_sum;
                }
                if (dia1_sum == dia2_sum && dia1_sum == prev_col_sum && dia1_sum == prev_row_sum) {
                    ans++;
                }

                next_col:col++;
            }
            row++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    /* 
    3,2,9,2,7
    6,1,8,4,2
    7,5,3,2,7
    2,9,4,9,6
    4,3,8,2,5
    */
    vector<vector<int>> v = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    vector v2 = {38,36,23};
    s.numMagicSquaresInside(v);

    return 0;
}
