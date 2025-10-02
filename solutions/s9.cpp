#include "lib.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int numDrunk = numBottles;
        int numEmpty = numBottles;

        while(numEmpty >= numExchange) {
            numEmpty-=numExchange-1;
            numExchange++;
            numDrunk++;
        }

        return numDrunk;
    }
};

int main() {
    Solution s;
    return 0;
}
