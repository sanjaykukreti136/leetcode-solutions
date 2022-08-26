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
        stack<TreeNode*>st;
        st.push(root);
        if(!root) return ;
        while(!st.empty()){
            TreeNode *curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()){
                curr->right = st.top();
                
            }
            curr->left = NULL;
            
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