#include "lib.h"

using namespace std;

class Solution {
public:
    void backtrace(vector<string> &ans, string &cur, int nest, int n) {
        if (n == 0) {
            int tmp = nest;
            while(tmp) {
                cur.push_back(')');
                tmp--;
            }
            ans.push_back(cur);
            tmp = nest;
            while(tmp) {
                cur.pop_back();
                tmp--;
            }
            return;
        
        }
        cur += '(';
        backtrace(ans, cur, nest + 1, n - 1);
        
        if (nest > 0) {
            cur.back() = ')';
            backtrace(ans, cur, nest - 1, n);
        }
        cur.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrace(ans, cur, 0, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
