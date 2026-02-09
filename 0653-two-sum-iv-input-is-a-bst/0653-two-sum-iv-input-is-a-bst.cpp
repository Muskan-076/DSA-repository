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
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse = true;
public: 
    BSTIterator(TreeNode* root, bool isreverse){
        reverse = isreverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* tmpnode = st.top();
        st.pop();
        if(!reverse) pushAll(tmpnode-> right);
        else pushAll(tmpnode-> left);
        return tmpnode-> val;
    }
private:
    void pushAll(TreeNode* node){
        for(;node != NULL; ){
            st.push(node);
            if(reverse == true){
                node = node-> right;
            }
            else{
                node = node-> left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k ) i= l.next();
            else j = r.next();
        }
        return false;
        
    }
};