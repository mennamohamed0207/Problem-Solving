/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int max = 0;
    void dfs(int maximum, TreeNode* root) {
        if (root == nullptr)
            return;
        if (maximum > max)
            max = maximum;
        dfs(maximum+1 , root->left);
        dfs(maximum+1, root->right);
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(1, root);

        return max;
    }
};