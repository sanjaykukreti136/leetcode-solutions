class Solution {
public:
    
    void check(string src , string des , set<string>&v , map<string,vector<pair<string,double>>>&mp , double &ans , double temp ){
        
        if(v.find(src)!=v.end()) return ;
        
        if(src == des){
            ans = temp;
            return ;
        }
        v.insert(src);
        for(auto i : mp[src]){
            
            check(i.first , des , v , mp , ans , temp*i.second);
            
        }
        
        
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>>mp;
        int k =0;
        for(auto i : e){
            mp[i[0]].push_back({ i[1] , v[k] });
            mp[i[1]].push_back({ i[0] , 1/v[k++] });
        }
        
        vector<double>res;
        
        for(auto i : q){
            string src = i[0];
            string des = i[1];
            double ans = -1.0 , temp = 1.0;
            set<string>v;
            if(mp.find(src)!=mp.end())
            check(src , des , v , mp , ans , temp );
            res.push_back(ans);
            
        }
        return res;
        
    }
};