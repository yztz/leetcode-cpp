#include "lib.h"

using namespace std;

class Solution {
public:
    unordered_map<int, int> sums = {{0, 1}};
    unsigned long long pre = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        pre += root->val;
        int ans = sums[pre - targetSum];
        sums[pre]++;
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        sums[pre]--;
        pre -= root->val;
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
