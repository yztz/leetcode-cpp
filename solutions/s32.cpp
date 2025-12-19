#include "lib.h"

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs[0].size();
        int rows = strs.size();
        int ans = 0;
        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    ans++;
                    break;
                }
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
