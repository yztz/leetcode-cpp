#include "lib.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; 
        for (int num : nums) {
            ans ^= num;
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
