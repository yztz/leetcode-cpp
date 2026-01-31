#include "lib.h"

using namespace std;

class Solution {
public:
    bool huiwen(string &s, int i, int j) {
        while(i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i >= j;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        
        // int ans_i = 0;
        // int ans_n = 1;
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j + i < n; j++) {
        //         if (huiwen(s, j, j + i)) {
        //             ans_i = j;
        //             ans_n = i;
        //             break;
        //         }
        //     }
        // }
        // return s.substr(ans_i, ans_n);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
