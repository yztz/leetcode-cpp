#include "lib.h"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();  
        int i = 0;
        int j = 0;
        do {
            i = nums[i];
            j = nums[nums[j]];
        } while (i != j);
        i = 0;
        while (i != j) {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};

int main() {
    // Solution s;
    // auto ptr = make_shared<Solution>();
    // vector v = {15,8,19};
    // vector v2 = {38,36,23};

    return 0;
}
