/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void check(TreeNode* t, TreeNode* c, TreeNode* &ans){
        if(c==NULL) return ;
        if(t->val==c->val){
            ans= c;
        }
        if(c->left) check(t, c->left, ans);
        if(c->right) check(t, c->right, ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans=NULL;  
        if(cloned->val== target->val ) return cloned;
        check(target, cloned, ans);
        return ans;
    }
};