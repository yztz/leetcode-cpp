#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur || !st.empty()) {
            if (cur) {
                if (cur->right) st.push(cur->right);
                st.push(value_type &&x)
            } else {
                cur = st.top(); st.pop();
                ans.push_back(cur->val);
            }
            cur = cur->right;
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
