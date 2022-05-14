class pair1{
    public:
     int first;
     int second;
     pair1(){}
     pair1(int u, int v){
         first=  u;
         second = v;
     }
};

class compare{
    public :
     bool operator()(pair1 *a , pair1 *b){
         return a->second > b->second;
     }
};

class Solution {
public:
    
    
    
    int ans = INT_MIN;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<times.size();i++){
            int s = times[i][0]-1;
            int d = times[i][1]-1;
            int v = times[i][2];
            graph[s].push_back({d,v});
        }
        vector<bool>vis(n , false);
        priority_queue<pair1*, vector<pair1*>, compare>pq;
        
        pq.push(new pair1(k-1 , 0));
        // vis[k-1]=true;
        int s=0;
        while(!pq.empty()){
            pair1 *p = pq.top();
            pq.pop();
            
            int src = p->first;
            int wt = p->second;
            if(vis[src]==true) continue;
            vis[src] = true;
            // s+=wt;    
            ans = max(ans , wt);
            for(auto i : graph[src]){
                if(vis[i.first]==false){
                    pq.push(new pair1(i.first ,wt + i.second  ));
                }
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==false) return -1;
        }
        return ans;
        
    }
};