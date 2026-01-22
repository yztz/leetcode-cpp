#include "lib.h"

using namespace std;

class Solution {
public:
class MinStack {
private:
    stack<int> min_st;
    stack<int> st;
public:
    
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if (val <= min_st.top()) {
            min_st.push(val);
        } else {
            min_st.push(min_st.top());
        }
    }

    void pop() {
        min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
