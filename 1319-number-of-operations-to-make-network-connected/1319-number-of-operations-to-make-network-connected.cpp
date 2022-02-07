class Solution {
public:
    int findParent(int node,vector<int>&parent)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    
    void _union( int u,int v,vector<vector<int>>&graph,vector<int>&parent, vector<int>&rank)
    {
        u=findParent(u, parent);
        v=findParent(v, parent);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[u]==rank[v])
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& graph) {
        vector<int> parent(n, 0), rank(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        int cnt=0;
        for(int i=0;i<graph.size();i++)
        {
            int a=graph[i][0];
            int b=graph[i][1];
            
            if(findParent(a, parent)==findParent(b,parent)) continue;
            else
            {
                _union(a,b,graph,parent,rank);
                cnt++;
            }
        }
       return graph.size() < n-1 ? -1 : n-1-cnt;

    }
};