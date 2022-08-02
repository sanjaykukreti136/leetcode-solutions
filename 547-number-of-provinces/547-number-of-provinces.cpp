class Solution {
public:
    
    void check(vector<bool>&vis , int src , vector<vector<int>>&v){
        
        // if(vis[src]) return ;
        vis[src] = true;
        for(auto i : v[src]){
            if(vis[i]==false){
                vis[i]=true;
                check(vis , i  , v);
            }
        }
        
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        
        vector<vector<int>>v(n);
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
                }
            }
        }
        
        vector<bool>vis(n ,false);
        int c = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                c++;
                // vis[i] = true;
                check(vis , i , v );
            }
        }
        return c;
        
    }
};