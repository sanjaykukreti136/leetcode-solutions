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
    unordered_map<int,int>ump;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int &rootIdx,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        
        int pivot=ump[postorder[rootIdx]];
        rootIdx--;
        TreeNode* node=new TreeNode(inorder[pivot]);
        
        node->right=build(inorder,postorder,rootIdx,pivot+1,right);
        
        node->left=build(inorder,postorder,rootIdx,left,pivot-1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int rootIdx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            ump[inorder[i]]=i;
        }
        
        return build(inorder,postorder, rootIdx, 0,inorder.size()-1);
        
    }
};
// class Solution {
// public:
//     map<int,int>m;
//     int find(vector<int>&in , int s , int e , int v){
//         for(int i=s;i<=e;i++){
//             if(in[i]==v) return i;
//         }
//         return -1;
//     }
//     TreeNode *check(vector<int>&in, vector<int>&post , int &mainidx , int s , int e ){
        
//         if(s > e) return NULL;
//         int pivot = m[post[mainidx]];
//         mainidx--;
//         TreeNode *root = new TreeNode(in[pivot]);    
//         TreeNode *le = check(in , post , mainidx , s , pivot-1);
//         TreeNode *ri = check(in, post , mainidx , pivot +1 , e);
//         root->left = le;
//         root->right = ri;
//         return root;
    
//     }
    
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//          int n = postorder.size()-1;
//         for(int i=0;i<inorder.size();i++){
//             m[inorder[i]] = i;
//         }
//          return check(inorder , postorder , n, 0 , inorder.size()-1);   
//     }
// };