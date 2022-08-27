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
    int s=  0;
    
    int check(TreeNode *root , int val){
        if(!root) return 0 ;
        int maxv = max(val , root->val);
        if(root->val >= val){
            return check(root->left , maxv) + check(root->right , maxv) + 1;
        }
        return check(root->left , maxv ) + check(root->right, maxv);
    }
    
    int goodNodes(TreeNode* root) {
      return  check(root , INT_MIN);
        // return s;
    }
};