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
    
    vector<TreeNode *>check(int s , int e){
        
        vector<TreeNode *>res;
        if(s > e) return {NULL};
        for(int i=s;i<=e;i++){
            vector<TreeNode *>left = check(s , i-1);
            vector<TreeNode *>right = check(i+1 , e);
            
            for(auto  l : left){
                for(auto r : right){
                    TreeNode *root = new TreeNode(i);
                    root->left = l ;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
       return  check(1 , n);
    }
};