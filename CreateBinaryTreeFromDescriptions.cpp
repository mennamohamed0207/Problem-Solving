/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *findParent(vector<vector<int>> &descriptions)
    {
        vector<int> parents;
        vector<int> children;
        for (int i = 0; i < descriptions.size(); i++)
        {
            parents.push_back(descriptions[i][0]);
        }
        for (int i = 0; i < descriptions.size(); i++)
        {
            children.push_back(descriptions[i][1]);
        }
    }
    bool Exists(vector<int> Nodes, int val)
    {
        for (int i = 0; i < Nodes.size(); i++)
        {
            if (Nodes[i] == val)
                return true;
        }
        return false;
    }
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        vector<int> Nodes;
        for (int i = 0; i < descriptions.size(); i++)
        {
            if (!Exists(Nodes, descriptions[i][0]))
            {
                TreeNode *node = new TreeNode(descriptions[i][0]);
                Nodes.push_back(descriptions[i][0]);
                TreeNode *nodeChild = new TreeNode(descriptions[i][1]);
                if (descriptions[i][2] == 1)
                {
                    node->left = nodeChild;
                }
                else
                {
                    node->right = nodeChild;
                }
            }
        }
    }
};