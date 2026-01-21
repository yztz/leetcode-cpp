#include "lib.h"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            swap(node->left, node->right);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return root;

        // if (root == nullptr) return root;
        // invertTree(root->left);
        // invertTree(root->right);
        // swap(root->left, root->right);
        // return root;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
