class Solution {
    int findshortestdistance(vector<vector<int>>& graph){
        int s=size(graph);
        int allvis=(1<<s)-1;                 // all nodes in the graph from 0 to (s-1) marked as 1(visited)
        queue<pair<int,pair<int,int>>> mq;  // pair<node,pair<distance,mask>>
        set<pair<int,int>> Hash;           // pair<node,mask>
        
        for(int i=0;i<s;i++){ // try all nodes as src, hence push all nodes marked as starting point(dis=0)
            int mask=1<<i;   // for node i, ith bit will be set (marked as visited)
            mq.push(make_pair(i,make_pair(0,mask)));
            Hash.insert(make_pair(i,mask));
        }
        
        while(not mq.empty()){
            auto front=mq.front();
            mq.pop();
            int node=front.first;
            int dis=front.second.first;
            int mask=front.second.second;
            
            for(auto x:graph[node]){
                int newmask=mask bitor (1<<x);
                if(newmask == allvis)
                    return dis+1;
                else if(Hash.count(make_pair(x,newmask))>0)
                    continue;
                Hash.insert(make_pair(x,newmask));
                mq.push(make_pair(x,make_pair(dis+1,newmask)));
            }
        }
        
        return 0;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(size(graph)==1) return 0;
        
        return findshortestdistance(graph);
    }
};
