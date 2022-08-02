class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<vector<pair<int,int>>>graph(n);
        for(auto i : times){
            graph[i[0]-1].push_back({i[2] , i[1]-1});
        }
        
        k-=1;
        // for(auto i : graph[k]){
        //     pq.push(i);
        // }
        pq.push({ 0  , k });
        vector<int>vis(n, -1);
        // vis[k] = 0;
        int res = 0;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            
            int node = p.second;
            if(vis[node]!=-1) continue;
            cout<<node<<"\n";
            int val = p.first;
            vis[node] = val;
            
            for(auto i : graph[node]){
                if(vis[i.second]==-1){
                    pair<int,int>x = { i.first + val , i.second};
                    pq.push(x);
                }
            }
            
        }
        
        for(auto i : vis){
            if(i==-1) return -1;
            res = max(res, i);
        }
        return res;
        
    }
};