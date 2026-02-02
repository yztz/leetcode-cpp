#include "lib.h"

using namespace std;

class Solution {
public:
    int getDepth(TreeNode *root, int &ans) {
        if (root == nullptr) return 0;
        int left = getDepth(root->left, ans);
        int right = getDepth(root->right, ans);
        ans = max(ans, right + left);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        getDepth(root, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
