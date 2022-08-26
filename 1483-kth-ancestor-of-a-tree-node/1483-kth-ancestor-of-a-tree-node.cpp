class TreeAncestor {
public:
    
    vector<vector<int>>dp;
    
    TreeAncestor(int n, vector<int>& parent) {
         dp.resize(20, vector<int>(n , -1));
         for(int i=0;i<n;i++){
             dp[0][i] = parent[i];
         }   
         
         for(int i=1;i<20;i++){
             for(int j=0;j<n;j++){
                if(dp[i-1][j]!=-1) dp[i][j] = dp[i-1][dp[i-1][j]];
             }
         }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            int mask = (1<<i);
            if((mask&k)>0){
                node = dp[i][node];
                if(node ==-1) return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */