#include "lib.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_marker = -1;
        int col_marker = -1;
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!found && matrix[i][j] == 0) {
                    row_marker = i;
                    col_marker = j;
                    found = true;
                    for (int k = 0; k < m; k++) {
                        if (matrix[k][col_marker] != 0) {
                            matrix[k][col_marker] = 1;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        if (matrix[row_marker][k] != 0) {
                            matrix[row_marker][k] = 1;
                        }
                    }
                } else if (matrix[i][j] == 0) {
                    matrix[row_marker][j] = 0;
                    matrix[i][col_marker] = 0;
                }
            }
        }
        if (!found) {
            return;
        }
        for (int i = 0; i < m; i++) {
            if (i == row_marker) continue;
            if (matrix[i][col_marker] == 0) {
                std::fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == col_marker) continue;
            if (matrix[row_marker][i] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int k = 0; k < m; k++) {
            matrix[k][col_marker] = 0;
        }
        for (int k = 0; k < n; k++) {
            matrix[row_marker][k] = 0;
        }
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
