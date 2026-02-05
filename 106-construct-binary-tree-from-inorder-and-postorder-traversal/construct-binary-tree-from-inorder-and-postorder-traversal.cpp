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

 
 // leetcode 106.
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> hm;
        for(int i =0; i< inorder.size(); i++){
            hm[inorder[i]] = i ;
        }
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, hm);
    }
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int> &hm){
        if(ps>pe || is>ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inroot = hm[postorder[pe]];
        int numsleft = inroot - is;

        root -> left = buildTreePostIn(inorder, is , inroot -1, postorder, ps, ps+numsleft -1, hm);
        root-> right = buildTreePostIn(inorder, inroot+1, ie, postorder,ps+numsleft, pe-1, hm);
        return root;
    }
};