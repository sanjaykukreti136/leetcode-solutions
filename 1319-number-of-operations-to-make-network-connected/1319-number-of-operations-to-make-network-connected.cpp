class Solution {
public:
    int parent[100005];
    int rank[100005];
    
    int find_par(int a){
        if(a == parent[a]) return a;
        return parent[a] = find_par(parent[a]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        
        for(auto i : connections){
            int a = i[0];
            int b = i[1];
            a = find_par(a);
            b = find_par(b);
            if(a!=b){
                
                if(rank[a]  < rank[b] ){
                    rank[a]+=rank[b];
                    parent[b] = a;
                }else{
                    rank[b]+=rank[a];
                    parent[a] = b;
                }
                
            }
        }
        int c = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) c++;
        }
        if(connections.size() < n-1) return -1;
        return c-1;
        
        
    }
};