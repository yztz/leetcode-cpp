#include "lib.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cur = matrix[0][0];
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1 - j][i];
                matrix[n - i - 1 - j][i] = matrix[n - i - 1][n - i - 1 - j];
                matrix[n - i - 1][n - i - 1 - j] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
        
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
