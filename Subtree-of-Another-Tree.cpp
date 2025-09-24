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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p != nullptr && q == nullptr) || (q != nullptr && p == nullptr))
            return false;
        if (p && q && p->val != q->val)
            return false;
        if (!p && !q)
            return true;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (root->val == subRoot->val) {
            bool result= isSameTree(root,subRoot);
            if (result) return result;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};