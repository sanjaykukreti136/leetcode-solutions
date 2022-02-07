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
    vector<int>  findRedundantConnection(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> parent(n,0), rank(n,0);
        for(int i=0;i<n;i++) 
            parent[i]=i;
        
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(findParent(graph[i][0]-1, parent)==findParent(graph[i][1]-1, parent))
            {
                res.push_back(graph[i][0]);
                res.push_back(graph[i][1]);
                break;
            }
            else
                _union(graph[i][0]-1, graph[i][1]-1, graph, parent,rank);
        }
        return res;
    }
};