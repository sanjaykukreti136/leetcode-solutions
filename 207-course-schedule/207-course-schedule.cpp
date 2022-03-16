class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
          vector<vector<int>> v(n);
        vector<int> deg(n, 0), bfs;
        for(int i=0;i<graph.size();i++){
            v[graph[i][1]].push_back(graph[i][0]);
            deg[graph[i][0]]++;
        }
        // vector<int>bfs(n);
        for(int i=0;i<n;i++){
            if(deg[i]==0) bfs.push_back(i);
        }
        
        for(int i=0;i<bfs.size();++i){
            for(auto j : v[bfs[i]]){
                if(--deg[j]==0){
                    bfs.push_back(j);
                }
            }
        }
        return bfs.size()==n;
    }
};