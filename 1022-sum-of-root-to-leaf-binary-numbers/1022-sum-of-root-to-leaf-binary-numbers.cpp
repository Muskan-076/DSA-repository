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
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;
        
        // Shift left (multiply by 2) and add current node value
        current = current * 2 + node->val;
        
        // If leaf node, return the number formed
        if (!node->left && !node->right)
            return current;
        
        // Recurse on left and right subtree
        return dfs(node->left, current) + dfs(node->right, current);
    }
};