#include "lib.h"

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1 + low % 2) / 2;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    printf("%d %d %d %d\n",
        s.countOdds(3, 7),
        s.countOdds(8, 10),
        s.countOdds(1, 1),
        s.countOdds(2, 2)
    );
    return 0;
}
