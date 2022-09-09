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
    
    void check(TreeNode *root , int val , int d){
        
        if(!root) return ;
        if(d==2){
            TreeNode *newnode = new TreeNode(val);
            TreeNode *newnode1 = new TreeNode(val);
            
            newnode->left = root->left;
            root->left = newnode;
            newnode1->right = root->right;
            root->right = newnode1;
            return ;
        }
        check(root->left , val , d-1);
        check(root->right , val , d-1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newnode = new TreeNode(val);
            newnode->left= root;
            return newnode;
        }
        check(root , val , depth);
        return root;
    }
};