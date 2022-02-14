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
    
    TreeNode *check( TreeNode *curr , int limit , int sum){
        if(!curr) return NULL;
        if(!curr->left && !curr->right){
            if(sum+curr->val < limit) return NULL;
            cout<<sum+curr->val<<"\n";
            return curr;
        }
        
        curr->left = check( curr->left , limit , sum+curr->val );
        curr->right = check(curr->right , limit , sum+curr->val);
        if(!curr->left && !curr->right) return NULL;
        return curr;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
       return  check( root , limit , 0);
    }
};