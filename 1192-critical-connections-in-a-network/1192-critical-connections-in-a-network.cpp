class Solution {
public:
    vector<vector<int>>ans;
    vector<int>low,time,vis;
    int t = 1;
    
    void dfs(vector<vector<int>>&graph , int src , int parent = -1){
        
        vis[src] = true;
        low[src] = time[src] = t++;
        for(auto i : graph[src]){
            if(i==parent) continue;
            
            if(!vis[i])
                dfs(graph , i , src);
            
            low[src] = min(low[src] , low[i]);
            if(time[src] < low[i]){
                vector<int>t = { src  , i };
                ans.push_back(t);
            }
            
        }
        
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low.resize(n);
        time.resize(n);
        vis.resize(n,0);
        vector<vector<int>>graph(n);
        for(auto i : connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        dfs(graph , 0);
        
        return ans;
        
        
    }
};