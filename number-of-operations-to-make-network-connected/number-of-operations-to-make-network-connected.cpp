class Solution {
public:
    
    void check(vector<vector<int>>&ans, int src , vector<int>&vis, int lev){
        vis[src] = lev;
        
        for(auto i : ans[src]){
            if(vis[i]==0){
                check(ans , i , vis , lev);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& graph) {
        vector<int>vis(n , 0);
        vector<vector<int>>ans(n);
        vector<vector<int>>ans1(n);
        for(auto i : graph){
            ans[i[0]].push_back(i[1]);
            ans[i[1]].push_back(i[0]);
            ans1[i[0]].push_back(i[1]);
        }
        int c= 0;
        int redun = 0;
        int level=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                check(ans , i , vis , level);
                
                c++;
                
                ////
                int count = 0 ;
                int child = 0;
                for(int j=0;j<vis.size();j++){
                    if(vis[j]==level){
                        child+=ans1[j].size();
                        count++;
                    }
                }
                redun+=child-(count-1);
                cout<<redun<<" - "<<i<<"\n";
               level+=1;    
            }
            
        }

        if(c==1){
            return 0;
        }
        if(redun < c-1 ){
            return -1;
        }else{
            return c-1;
        }
        // detect cycle in graph
        
        
        
    }
};