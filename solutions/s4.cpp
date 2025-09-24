#include "lib.h"
#include <algorithm>
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
    string fractionToDecimal(int _numerator, int _denominator) {
        if (_numerator == 0) return "0";
        bool minus = ((_numerator ^ _denominator) & (1 << 31)) != 0;
        long numerator = _numerator;
        long denominator = _denominator;
        numerator = numerator < 0 ? -numerator : numerator;
        denominator = denominator < 0 ? -denominator : denominator;

        string ans = to_string(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0) {
            return minus ? "-" + ans : ans;
        }
        ans += ".";
        unordered_map<int, int> parttern;

        while (numerator != 0) {
            numerator *= 10;
            int c = numerator / denominator;
            numerator %= denominator;
            ans += to_string(c);

            if (parttern.find(numerator) != parttern.end()) {
                int loc = parttern[numerator];
                ans = ans.substr(0, loc) + "(" + ans.substr(loc, ans.size() - loc) + ")";
                return minus ? "-" + ans : ans;
            } else {
                parttern[numerator] = ans.size(); 
            }
        }

        return minus ? "-" + ans : ans;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(1, -1) << endl;
    return 0;
}
