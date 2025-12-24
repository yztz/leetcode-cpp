#include "lib.h"

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        for (int i = happiness.size() - 1; i >= happiness.size() - k; i--) {
            if(happiness.size() - i - 1 >= happiness[i]) break;
            ans += happiness[i] - (happiness.size() - i - 1);
        }   
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {7,50,3};
    vector v2 = {38,36,23};
    auto ret = s.maximumHappinessSum(v, 3);
    printf("%lld\n", ret);
    return 0;
}
