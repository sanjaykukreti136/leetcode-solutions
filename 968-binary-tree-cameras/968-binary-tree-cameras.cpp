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
    int check(TreeNode *root){
        if(!root) return 0;
        if(!root->left && !root->right) return -1;
        
        int l = check(root->left);
        int r = check(root->right);
        if(l==-1 || r==-1){
            ans+=1;
            return 1;
        }
        if(l==1 || r==1){
            return 0;
        }
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        int x =  check(root);
        if(x==-1) ans+=1;
        return ans;
    }
};