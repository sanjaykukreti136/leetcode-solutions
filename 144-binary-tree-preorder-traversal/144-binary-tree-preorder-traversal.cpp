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
    vector<int>res;
    
    TreeNode *check(TreeNode *l , TreeNode *curr){
        while(l->right!=NULL && l->right!=curr){
            l = l->right;
        }
        return l;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode *curr = root;
        while(curr){
            TreeNode *leftNode = curr->left;
            if(leftNode == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }else{
                
                TreeNode *t = check(leftNode , curr);
                
                if(t->right == NULL){
                    t->right = curr;
                    res.push_back(curr->val);
                    curr = curr->left;
                }else{
                    t->right = NULL;

                    curr = curr->right;
                }
                
            }
        }
        return res;
        
    }
};