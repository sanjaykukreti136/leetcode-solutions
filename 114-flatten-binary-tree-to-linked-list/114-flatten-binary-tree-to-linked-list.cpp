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
    void flatten(TreeNode *root){
        TreeNode *curr= root;
        while(curr){
            
            if(curr->left){
                TreeNode *temp = curr->left;
                while(temp->right){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left  = NULL;
            }
            curr = curr->right;
            
        }
    }
//     TreeNode *check(TreeNode *root){
//         if(!root) return NULL;
        
//         TreeNode *l = check(root->left);
//         TreeNode *r = check(root->right);
        
//         TreeNode *t = l;
//         if(t){
//             while(t->right){
//                 t = t->right;
//             }
//             t->right = r;
//             root->right = l;
//         }else{
//             root->right = r;
//         }
//         root->left = NULL;
//         return root;
//     }
    
//     void flatten(TreeNode* root) {
//         check(root);
//     }
};