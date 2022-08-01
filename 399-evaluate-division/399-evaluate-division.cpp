class Solution {
public:
    
    
    double check(string src , string des , unordered_map<string,vector<pair<string,double>>>mp){
        
        if(mp.find(src)==mp.end()) return -1;
        if(mp.find(des)==mp.end()) return -1;
        
        queue<pair<string,double>>q;
        set<string>st;
        st.insert(src);
        q.push({src , 1});
        while(!q.empty()){
            
            pair<string,double>p = q.front();
            q.pop();
            string point = p.first;
            double curr= p.second;
            if(point == des){
                return curr;
            }
            
            for(auto i : mp[point]){
                
                if(st.find(i.first)==st.end()){
                    st.insert(i.first);
                    q.push({i.first , curr*i.second});
                }
                
            }
            
            
            
        }
        return -1;
        
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>>mp;
        int k = 0;
        for(auto i : equations){
            string start = i[0];
            string end = i[1];
            double value = values[k++];
            mp[start].push_back({end , value});
            mp[end].push_back({start , 1/value});
        }
        
        vector<double>ans;
        
        for(auto i : queries ){
            string src = i[0];
            string des = i[1];
            
            ans.push_back(check(src  , des , mp));
            
        }
        return ans;
        
        
        
    }
};