class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>v;
        for(int i=0;i<routes.size();i++){
            for(auto  j : routes[i]){
                v[j].push_back(i);
            }
        }
        
        map<int,int>bus_stand;
        map<int,int>bus;
        queue<pair<int,int>>q;
        q.push({source, 0});
        int dis = 0;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int src = q.front().first;
                int di = q.front().second;
                q.pop();
                if(src==target) return di;
                for(auto i : v[src]){
                    if(bus_stand.find(i)==bus_stand.end()){
                        bus_stand[i] = 1;
                        
                        for(auto j : routes[i]){
                            if(bus.find(j)==bus.end()){
                                bus[j]  =1;
                                q.push({j , di+1});
                            }
                        }
                    }
                }
                
            }
        }
        return -1;
    }
};