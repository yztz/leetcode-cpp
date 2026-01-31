#include "lib.h"

using namespace std;

class Solution {
public:
    int _decodeString(string &s, int i, string &ret) {
        int n = s.size();
        // stack<int> repeat;
        while (i < n) {
            char c = s[i];
            if (isalpha(c)) {
                ret += c;
            } else if (c == ']') {
                return i;
            } else if (isdigit(c)) {
                int num = c - '0';
                while (s[++i] != '[') {
                    num = num * 10 + s[i] - '0';
                }
                string content;
                i = _decodeString(s, i + 1, content);
                for (int r = 0; r < num; r++) {
                    ret += content;
                }
            }
            i++;
        }
        return i;
    }

    string decodeString(string s) {
        // string content;
        // _decodeString(s, 0, content);
        // return content;

    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
