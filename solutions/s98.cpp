#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(0);
        for (int row = 1; row < numRows; row++) {
            for (int col = 0; col < row + 1; col++) {
                if (col == 0 || col == row) ans[row].push_back(1);
                else ans[row].push_back(row);
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
