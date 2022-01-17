class Solution {
public:
    
    void check(vector<vector<int>>&graph, int s , int d, int n , vector<int>&bfs ){
        
        queue<int>q;
        q.push(0);
        int l = 0;

        vector<bool>vis(n , false);
        vis[0] = true;
        while(!q.empty()){
            int x = q.size();
            for(int i=0;i<x;i++ ){
                int y = q.front();
                q.pop();
                // if(y==d) return l;
                bfs[y] = l;
                for(auto j : graph[y] ){
                    if(vis[j]==false){
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
            l++;
        }
        // return l;
    }
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        // int n = edges.siz
        int n = p.size();
        vector<vector<int>>graph(n);
        for(auto i : edges ){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int>bfs(n, 0);
        check(graph,0 , 0 , n , bfs);
        
        int ans = 0;
        
        for(int i=1;i<n;i++){
            int dist = bfs[i];
            int time= p[i];
            int ft = dist*2;
            int wt = ft-1;
            int resend = wt/time;
            int x = ft + resend*time;
            ans = max(ans , x);
        }
        return ans+1;
        
        
    }
};