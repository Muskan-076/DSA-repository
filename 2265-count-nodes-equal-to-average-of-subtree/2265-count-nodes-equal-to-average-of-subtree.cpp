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
    int ans = 0;

    // returns {sum of subtree, number of nodes in subtree}
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        // Get information from left and right subtrees
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        // Calculate current subtree's sum and count
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        // floor(sum / count) is automatically done by integer division
        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};