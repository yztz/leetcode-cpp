#include "lib.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root, int &max_val, int &min_val) {
        if (root == nullptr) return true;
        if (root->left && root->val < root->left->val) return false;
        if (root->right && root->val > root->right->val) return false;
        
        int tmp_min = root->val;
        int tmp_max = root->val;

        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);

        return  isValidBST(root->left, tmp_max, min_val) 
                && (root->left == nullptr || tmp_max < root->val)  
                && isValidBST(root->right, max_val, tmp_min) 
                && (root->right == nullptr || tmp_min > root->val);
    }

    bool isValidBST(TreeNode* root) {
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        return isValidBST(root, max_val, min_val);
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
