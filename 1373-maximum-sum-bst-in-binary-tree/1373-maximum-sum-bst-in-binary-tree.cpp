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

    struct Info {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };

    Info solve(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check whether current subtree is a BST
        if (left.isBST && right.isBST &&
            left.mx < root->val &&
            root->val < right.mn) {

            int sum = left.sum + right.sum + root->val;

            ans = max(ans, sum);

            return {
                true,
                min(left.mn, root->val),
                max(right.mx, root->val),
                sum
            };
        }

        // Current subtree is NOT a BST
        return {
            false,
            0,
            0,
            0
        };
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};