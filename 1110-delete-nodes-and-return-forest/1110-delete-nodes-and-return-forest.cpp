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
    map<int,int>m;
    
    
    void check(TreeNode *root, vector<TreeNode*>&v){
        if(!root) return ;
        
        check(root->left , v);
        check(root->right , v);
        if(root->left && m.find(root->left->val)!=m.end()) root->left = NULL;
        if(root->right && m.find(root->right->val)!=m.end()) root->right = NULL;        
        if(m.find(root->val)!=m.end()){
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
            root->left=  NULL;
            root->right = NULL;
        }

    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i : to_delete){
            m[i] = 1;
        }
        vector<TreeNode *>res;
        check(root , res);
        if(m.find(root->val)==m.end()) res.push_back(root);
        return res;
    }
};