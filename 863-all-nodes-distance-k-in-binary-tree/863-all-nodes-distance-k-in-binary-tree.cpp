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
    vector<int>res;
    
    void check1(TreeNode *root , TreeNode *block , int d){
        if(!root || root==block) return;
        if(d==0) res.push_back(root->val);
        check1(root->left , block , d-1);
        check1(root->right , block , d-1);
        
    }
    
    int check(TreeNode *root , TreeNode *target , int k){
        if(!root) return 0;
        
        if(root==target){
            check1(root , NULL , k);
            return 1;
        }
        
        int x = check(root->left , target , k);
        if(x > 0){
            check1(root , root->left , k-x);
            return x+1;
        }
        int y = check(root->right , target , k);
        if(y > 0){
            check1(root, root->right , k-y);
            return y+1;
        }
        return 0; 
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        check(root , target , k);
        return res;
    }
};