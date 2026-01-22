#include "lib.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = matrix[0][mid];
            if (num == target) return true;
            else if (num < target) l = mid + 1;
            else r = mid;
        }
        int col = r - 1;
        if (col < 0) return false;
        l = 0;
        r = m;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = matrix[mid][0];
            if (num == target) return true;
            else if (num < target) l = mid + 1;
            else r = mid;
        }
        int row = r - 1;
        if (row < 0) return false;
        for (int i = 1; i <= row; i++) {
            l = 1;
            r = col + 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                int num = matrix[i][mid];
                if (num == target) return true;
                else if (num < target) l = mid + 1;
                else r = mid;
            }
        }
        
        return false;
    }
};

int main() {
    Solution s;
    // vector v = {15,8,19};
    // vector v2 = {38,36,23};
    vector<vector<int>> ret = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    s.searchMatrix(ret, 5);

    return 0;
}
