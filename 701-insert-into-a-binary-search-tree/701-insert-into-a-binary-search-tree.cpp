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
    void check(TreeNode *root , int v , TreeNode *pre){
        if(!root){
            if(pre == NULL){
                // return new TreeNode(v);
                root = new TreeNode(v);
                return ;
            }
            else{
                if(v < pre->val){
                    pre->left = new TreeNode(v);
                }
                else{
                    pre->right = new TreeNode(v);
                }
            }
            return ;
        }
        
        if(root->val < v){
            check(root->right , v , root);
        }
        else{
            check(root->left , v , root);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        check(root , val , NULL);
        return root;
        
    }
};