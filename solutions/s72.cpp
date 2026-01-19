#include "lib.h"

using namespace std;

class Solution {
public:
    // int visual_level = 0;
    // void traverse(TreeNode *root, vector<int> &ans, int level) {
    //     if(root == nullptr) return;
    //     if (level >= visual_level) {
    //         visual_level++;
    //         ans.push_back(root->val);
    //     }
    //     traverse(root->right, ans, level + 1);
    //     traverse(root->left, ans, level + 1);
    // }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        // traverse(root, ans, 0);

        int current_depth = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            if (item.second >= current_depth) {
                current_depth++;
                ans.push_back(item.first->val);
            }
            if(item.first->right) q.push({item.first->right, item.second + 1});
            if(item.first->left) q.push({item.first->left, item.second + 1});
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
