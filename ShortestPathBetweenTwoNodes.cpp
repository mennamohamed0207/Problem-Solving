// //Educatorial section because idk how to solve it
// Approach 2: LCA + DFS
// Intuition
// A more optimal method exists to solve a tree problem that doesn't involve converting it to a bidirectional graph. Let's try to solve it as a tree this time.

// If we trace paths from the root to the two nodes, we see that these paths share a common segment until a certain point, after which they diverge. This last intersection is the Lowest Common Ancestor (LCA). Since it is the last shared point, any path connecting the two nodes must pass through this LCA. We won't discuss the methods to find the LCA in a binary tree in this article, as it is a separate and popular problem. Here we will be focusing on the application of it. If you are unfamiliar with LCA, check out Lowest Common Ancestor of a Binary Tree.

// Check out how the LCA is a part of the common paths for the start and destination nodes in this image:

// LCA Image

// The path between the start node and the destination node can be divided into two parts: the path from the start node to the LCA and the path from the LCA to the destination node. The path from the start node to the LCA consists only of the direction 'U' since all moves are from a child node to a parent node.

// To find these paths, we use depth-first search starting from the LCA and moving towards the target nodes. Initially, we explore the left subtree appending 'L' to the path. Upon finding the target node, we return immediately. If not found, we backtrack by replacing 'L' with 'R' to explore the right subtree. If the target node isn't found in either subtree, we backtrack to the parent node. This recursive process continues until the target node is located.

// Check out this slideshow to better understand how to find the path for a node:

// Current

// Now that we have the directions to both the start and destination nodes from the LCA, we can piece together the full path. We transform the path from the LCA to the start node by replacing all directions with "U" and prepend it to the path to the destination node. The resulting sequence gives the step-by-step directions from the start node to the end node in the binary tree

// Algorithm
// Main method getDirections:

// Find the lowestCommonAncestor of startValue and destValue using the findLowestCommonAncestor method.
// Initialize pathToStart and pathToDest to store paths from the LCA to the start and destination nodes, respectively.
// Call findPath to determine these paths.
// Initialize directions to store the final result.
// Add "U" for each step in pathToStart.
// Append pathToDest to directions.
// Return directions, which contains the step-by-step directions from the start node to the destination node.
// Helper method findLowestCommonAncestor:

// Define findLowestCommonAncestor with parameters: node, value1, and value2.
// If node is null, return null.
// If node's value matches value1 or value2, return node.
// Recursively search for the LCA in the left and right subtrees, storing results in leftLCA and rightLCA.
// If leftLCA is null, return rightLCA.
// If rightLCA is null, return leftLCA.
// If both leftLCA and rightLCA contain nodes, the current node is the lowest common ancestor. Return node.
// Helper method findPath:

// Define findPath with parameters: node, targetValue, and path.
// If node is null, return false.
// If node's value matches targetValue, return true.
// Append "L" to path and search the left subtree. If the target node is found, return true.
// If not found, remove the last character from path.
// Append "R" to path and search the right subtree. If the target node is found, return true.
// If not found, remove the last character from path.
// Return false if the target node is not found in either subtree.
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
    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (node == nullptr) return false;

        if (node->val == targetValue) return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        if (!node)
            return nullptr;
        if (node->val == value1 || node->val == value2)
            return node;
        TreeNode* leftLCA =
            findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA =
            findLowestCommonAncestor(node->right, value1, value2);
        if (leftLCA == nullptr) {
            return rightLCA;
        } else if (rightLCA == nullptr) {
            return leftLCA;
        } else
            return node;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowestCommonAncestor =
            findLowestCommonAncestor(root, startValue, destValue);
        string pathToStart;
        string pathToDest;

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;
        // Add "U" for each step to go up from start to LCA
        directions.append(pathToStart.length(), 'U');

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions;
    }
};