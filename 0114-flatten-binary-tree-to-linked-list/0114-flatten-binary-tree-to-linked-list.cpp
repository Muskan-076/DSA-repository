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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                
                // Find the rightmost node of left subtree
                TreeNode* pred = curr->left;

                while (pred->right) {
                    pred = pred->right;
                }

                // Attach original right subtree
                pred->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};