#include "lib.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push(c);
                break;
                case ')':
                if (st.empty() || st.top() != '(') return false;
                st.pop();
                break;
                case ']':
                if (st.empty() || st.top() != '[') return false;
                st.pop();
                break;
                case '}':
                if (st.empty() || st.top() != '{') return false;
                st.pop();
                break;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
