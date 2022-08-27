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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        TreeNode *t = new TreeNode(0);
        
        if(n==1) return {t};
        vector<TreeNode *>res;
        for(int i=1;i<=n;i++){
            vector<TreeNode*>l = allPossibleFBT(i-1);
            vector<TreeNode*>r = allPossibleFBT(n-i);
            
            for(auto le  : l){
                for(auto ri : r){
                    if(le && ri){
                    TreeNode *root = new TreeNode(0);
                    root->left = le;
                    root->right = ri;
                     res.push_back(root);   
                  }
                }
            }
        }
        return res;
        
    }
};