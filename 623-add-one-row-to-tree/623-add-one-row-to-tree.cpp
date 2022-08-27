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
    
    void check(TreeNode *root , int v , int d){
        if(!root) return ;
        
        if(d==2){
            
            TreeNode *for_left = new TreeNode(v);
            TreeNode *for_right = new TreeNode(v);
            
            TreeNode *root_left = root->left;
            root->left = for_left;
            for_left->left = root_left;
            
            TreeNode *root_right = root->right;
            root->right = for_right;
            for_right->right = root_right;
            
        }

        check(root->left , v , d-1);
        check(root->right , v , d-1);
        
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==0) return root;
        if(depth==1){
            TreeNode *t = new TreeNode(val);
            t->left = root;
            return t;
        }
        check(root , val , depth);
        
        return root;
    }
};