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
    TreeNode *getRight(TreeNode *curr , TreeNode *root){
        while(curr->right!=NULL && curr->right!=root){
            curr = curr->right;
        }
        return curr;
    }
    void recoverTree(TreeNode* root) {
        TreeNode *curr = root ;
        TreeNode *pre = NULL;
        TreeNode *a = NULL;
        TreeNode *b = NULL;
        while(curr){
            if(curr->left==NULL){
                if(pre!=NULL && pre->val > curr->val ){
                    if(a==NULL) a = pre;
                    b = curr;
                }
                pre = curr;
                curr = curr->right;
            }
            else{
                TreeNode *temp = getRight(curr->left , curr);
                if(temp->right==NULL){
                    temp->right = curr;
                    curr = curr->left;
                }else{
                    temp->right = NULL;
                    if(pre!=NULL && pre->val > curr->val ){
                    if(a==NULL) a = pre;
                    b = curr;
                }
                pre = curr;
                    curr = curr->right;
                }
            }
            
        }
        swap(a->val , b->val);
    }
};