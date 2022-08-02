class Solution {
public:
    vector<string>ans;
    
    bool check(string src , int c , vector<vector<string>>& tickets , vector<bool>&vis ,vector<string>res ){
        
        if(c == 0){
            // res.push_back(src) ;
            ans = res;
            return true;
        }
        
        set<pair<string,int>>st;
        for(int i=0;i<tickets.size();i++){
            if(tickets[i][0]==src && vis[i]==false ){
                st.insert({tickets[i][1] , i});
            }
        }
        
        for(auto i : st){
            if(vis[i.second]==false){
                vis[i.second] = true;
                res.push_back(i.first);
                if(check(i.first , c-1 , tickets , vis , res)) return true;
                vis[i.second] = false;
                res.pop_back();
            }
        }
        
        return false;
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        set<pair<string,int>>st;
        
        for(int i=0;i<tickets.size();i++){
            if(tickets[i][0]=="JFK"){
                st.insert({tickets[i][1] , i});
            }
        }
        int n = tickets.size();
        vector<bool>vis(n, false);
        vector<string>res;
        res.push_back("JFK");
        for(auto i : st){
            vis[i.second] = true;
            res.push_back(i.first);
            if( check(i.first , n-1 , tickets , vis, res ) ){
                return ans;
            }
            res.pop_back();
            vis[i.second] = false;
            
        }
        return ans;
        
        
        
        
    }
};