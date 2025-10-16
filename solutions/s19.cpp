#include "lib.h"

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int mex = 0;
        vector<int> cnt(value, 0);

        for (int num : nums) {
            cnt[(num % value + value) % value]++;
        }

        int min = INT_MAX;
        int min_idx = 0;
        for (int i = 0; i < value; i++) {
            if (cnt[i] < min) {
                min = cnt[i];
                min_idx = i;
            }
        }
        

        return min * value + min_idx;
    }
};

int main() {
    Solution s;
    vector v = {1,-10,7,13,6,8};
    vector v2 = {38,36,23};
    cout << s.findSmallestInteger(v, 7) << endl;
    return 0;
}
