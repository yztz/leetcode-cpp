#include "lib.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto nonzero_it = nums.begin();
        auto it = nums.begin();
        while(it != nums.end()) {
            if (*it != 0) {
                iter_swap(it, nonzero_it);
                ++nonzero_it;
            }
            ++it;
        }
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
