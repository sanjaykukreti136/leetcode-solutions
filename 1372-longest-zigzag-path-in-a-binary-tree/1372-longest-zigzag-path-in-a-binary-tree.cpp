class Solution {
public:
    int longestpath(TreeNode *root,int d,int &maxi){
       if(!root)  return +0;
        
        int longestrightint_left=longestpath(root->left,1,maxi);  //left subtree m right node k right
        int longestleftpath=longestrightint_left+1;   //root s lkr
        
        int longestleftint_right=longestpath(root->right,0,maxi);  //right subtree m left
        int longestrightpath=1+longestleftint_right; //root s lkr
        
        maxi=max({longestleftpath,longestrightpath,maxi});
        
        if(d==0)  return longestleftpath;
         return longestrightpath;
            
    }
    
    int longestZigZag(TreeNode* root) {
        int maxi=0;
        longestpath(root,0,maxi);
        return maxi-1;
    }
};