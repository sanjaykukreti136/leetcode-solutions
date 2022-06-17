
class Solution {
public:
    
    //   O  -  It indicates that the root is covered by another camera
    //   -1 -  It indiactes that the root required camera
    //   1  -  It indicates that root has camera 
    
    int c=0;  ///  counter for cameras
    int check(TreeNode *root){
        if(root==NULL) return 0;   // if root is NULL it means it is covered 
        if(!root->left && !root->right ) return -1;  /// Worst position for installing camera is leaf node , beacuse it will cover only parent node , thats why it will always need cover by another camera
        
        int l = check(root->left);  
        int r = check(root->right);
        
        if(l==-1 || r==-1 ){  /// if any  side needs camera , so here we have to install camera and return 1 bcz we have camera
            c++;
            return 1;
        }
        else if(l == 1 || r==1) return 0;  /// if none of side need camera , and any side has camera so it means i can covered by that camera 
        return -1;   /// else return -1 , bcz i am not either covered or not have camera
    }
    int minCameraCover(TreeNode* root) {
       if(!root->left && !root->right) return 1;
       int y=  check(root);  /// here we have also check for the top node requirements 
        if(y==-1) c++;
        return c;
    }
};