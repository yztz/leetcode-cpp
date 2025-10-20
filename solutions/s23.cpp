#include "lib.h"

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string &op: operations) {
            if (op[0] == '+' || op[op.size() - 1] == '+') {
                x++;
            } else {
                x--;
            }
        }   

        return x;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
