class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int , double>>>graph(n);
        vector<pair<int,double>>v;
        for(int i=0;i<n;i++){
            graph.push_back(v);
        }
        int k = 0;
        for(auto i : edges){
            graph[i[0]].push_back({i[1] , succProb[k]});
            graph[i[1]].push_back({i[0] , succProb[k++]});
        }
        queue<int>q;
        vector<double>vis(n , 0.0);
        vis[start]  = 1.0;
        q.push(start);
        while(!q.empty()){
            int next = q.front();
            q.pop();
            for(auto i : graph[next]){
                if(vis[i.first] < vis[next]*i.second){
                    q.push(i.first);
                    vis[i.first] = vis[next]*i.second;
                }
            }
        }
        return vis[end];
    }
};