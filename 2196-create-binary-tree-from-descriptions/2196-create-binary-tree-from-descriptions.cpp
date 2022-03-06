class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // map<int,TreeNode*>m;
        TreeNode *m[100007] ={ NULL };
        int a[100007] = {0};
        int x = INT_MIN;
        for(auto i : descriptions){
            int par = i[0];
            int child = i[1];
            a[child]= 1;
            int ind = i[2];
            x = max(x , max(child, par));
            TreeNode *ch= NULL;
            if(m[child]==NULL)  ch = new TreeNode(child);
            else ch = m[child];
            
            TreeNode *pa  =NULL;
            if(m[par]==NULL) pa= new TreeNode(par);
            else pa = m[par];
            
            if(ind ==1 ){
                pa->left = ch;
            }else{
                pa->right = ch;
            }
            m[child] = ch;
            m[par] = pa;
        }
        for(int i=1;i<=x;i++){
            if(m[i]!=NULL && a[m[i]->val]==0) return m[i];
        }
        return NULL;
    }
};