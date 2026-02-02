#include "lib.h"

using namespace std;

class Solution {
public:
    int max_left = INT_MIN;
    int max_right = INT_MIN;
    int max_root = INT_MIN;
    int maxPathSum_(TreeNode* root) {
        int left = 0;
        int right = 0;
        if (root->left) {
            left = maxPathSum_(root->left);
            max_left = max(max_left, left);
        }
        if (root->right) {
            right = maxPathSum_(root->right);
            max_right = max(max_right, right);
        }
        
        max_root = max(max_root, left + right + root->val);

        return max(max(left, right) + root->val, root->val);
    }

    int maxPathSum(TreeNode* root) {
        int r = maxPathSum_(root);
        return max(max(max(max_left, max_right), max_root), r);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
