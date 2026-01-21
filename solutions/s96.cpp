#include "lib.h"

using namespace std;

class Solution {
public:
    // TreeNode *flattenSub(TreeNode* root) {
    //     if (root->left) {
    //         TreeNode *left_end = flattenSub(root->left);
    //         if (root->right) {
    //             left_end->right = root->right;
    //             root->right = root->left;
    //             root->left = nullptr;
    //             return flattenSub(left_end->right);
    //         } else {
    //             root->right = root->left;
    //             root->left = nullptr;
    //             return left_end;
    //         }
    //     } else if (root->right) {
    //         return flattenSub(root->right);
    //     } else {
    //         return root;
    //     }
    // }
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        // flattenSub(root);
        TreeNode *cur = root;
        while(cur->left || cur->right) {
            auto left = cur->left;
            auto right = cur->right;
            if (left) {
                while (left->right) {
                    left = left->right;
                }
                left->right = right;
                cur->right = cur->left;
                cur->left = nullptr;
            }

            cur = cur->right;
        }
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
