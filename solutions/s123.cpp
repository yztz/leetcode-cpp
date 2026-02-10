#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> layer;
            while (n-- > 0) {
                TreeNode *node = q.front(); q.pop();
                layer.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.emplace_back(std::move(layer));
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
