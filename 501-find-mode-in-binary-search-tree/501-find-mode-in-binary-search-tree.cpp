class Solution {
public:
    void travo(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL) return;
        travo(root->left,vec);
        vec.push_back(root->val);
        travo(root->right,vec);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> vec;
        travo(root,vec);
        unordered_map<int,int> mp;
        for(int i=0;i<vec.size();i++) mp[vec[i]]++;
        vec.clear();
        int maxo=-100002;    
		
        for(auto i:mp)
            if(i.second>maxo) 
                maxo=i.second;
    
        for(auto i:mp)
            if(i.second==maxo) 
                vec.push_back(i.first);
        return vec;
    }
};