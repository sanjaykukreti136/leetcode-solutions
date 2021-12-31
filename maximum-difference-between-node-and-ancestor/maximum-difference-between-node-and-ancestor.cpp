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
    
    int ans = INT_MIN;
    
    pair<int,int> check(TreeNode *root){
        if(!root) return {INT_MAX , INT_MIN};
        
        pair<int,int> l = check(root->left);
        pair<int,int> r = check(root->right);
        
        int ret_min = min(min(l.first,r.first) , root->val);
        int ret_max = max(max(l.second, r.second) , root->val);
        if(l.first==INT_MAX && r.first ==INT_MAX){
            
        }
        else if(l.first!=INT_MAX && r.first!=INT_MAX){
            ans = max(ans , abs( root->val - min(l.first , r.first) ) );
        }
            
        else if(l.first==INT_MAX){
            ans = max(ans , abs(root->val- r.first));
        }else if(r.first==INT_MAX){
            ans = max(ans , abs(root->val - l.first) );
        }
        
        
        
        if(l.second==INT_MIN && r.second ==INT_MIN){
            
        }
        else if(l.second!=INT_MIN && r.second!=INT_MIN){
            ans = max(ans , abs( root->val - max(l.second , r.second) ) );
        }
            
        else if(l.second==INT_MIN){
            ans = max(ans , abs(root->val- r.second));
        }else if(r.second==INT_MIN){
            ans = max(ans , abs(root->val - l.second) );
        }
        
        return { ret_min , ret_max };
        
        
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
      // pair<int,int>p =  check(root);
      pair<int,int>p = check(root);
      return ans==INT_MAX ? 0 : ans;
    }
};