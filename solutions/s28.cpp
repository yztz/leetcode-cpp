#include "lib.h"

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const unsigned long long MOD = pow(10, 9) + 7;
        int count_s = 0;
        int count_p = 0;
        int pre_s = -1;
        vector<int> between_p;

        for (int i = 0; i < corridor.size(); i++) {
            char c = corridor[i];
            if (c == 'S') {
                count_s = count_s + 1;
                pre_s = i;
                if (count_s == 2) {
                    if (count_p > 0) {
                        between_p.push_back(count_p);
                        count_p = 0;
                    }
                    count_s = 0;
                }
            } else {
                if (pre_s != -1 && count_s == 0) count_p++;
            }
        }
        if (count_s != 0 || pre_s == -1) {
            return 0;
        }
        unsigned long long ans = 1;
        for (int p : between_p) {
            ans = (ans * (p + 1)) % MOD;
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
