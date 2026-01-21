#include "lib.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& loc, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l == pre_r) return new TreeNode(preorder[pre_l]);
        if (pre_l > pre_r) return nullptr;

        int val = preorder[pre_l];
        TreeNode *root = new TreeNode(val);
        int in_root = loc[val];

        int left_size = in_root - in_l;
        root->left = buildTree(preorder, inorder, loc, pre_l + 1, pre_l + left_size, in_l, in_root - 1);
        root->right = buildTree(preorder, inorder, loc, pre_l + left_size + 1, pre_r, in_root + 1, in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> loc;
        for (int i = 0; i < inorder.size(); i++) {
            loc[inorder[i]] = i;
        }
        int n = preorder.size();
        return buildTree(preorder, inorder, loc, 0, n - 1, 0, n - 1);
        // int cur = 0;
        // TreeNode *root = new TreeNode();
        // stack<pair<TreeNode*, int>> st;
        // int pre = n;
        // st.push({root, 0});
        // while (!st.empty()) {
        //     auto p = st.top(); st.pop();
        //     TreeNode *cur = p.first;
        //     int pre_loc = p.second;
        //     cur->val = preorder[pre_loc];
        //     int in_loc = loc[cur->val];

        //     int l_loc = pre_loc + 1;
        //     if (l_loc < n && loc[preorder[l_loc]] < in_loc) {
        //         TreeNode *left = new TreeNode();
        //         cur->left = left;
        //         st.push({left, l_loc});
        //     }
        //     int r_loc = pre_loc + 1;
        //     while(r_loc < n && loc[preorder[r_loc]] <= loc) r_loc++;
        //     if (r_loc < n) {
        //         TreeNode *right = new TreeNode();
        //         cur->right = right;
        //         st.push({right, r_loc});
        //     }
        //     pre = cur->val;
        // }

        // return root;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
