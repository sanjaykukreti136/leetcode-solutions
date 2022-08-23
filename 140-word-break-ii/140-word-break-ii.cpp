class Solution {
public:
    vector<string>ans;
    unordered_map<int,bool>vis;
    bool check(string s , int idx , unordered_map<string,bool>&mp , string t){
        
        if(idx==s.size()){
            string t1 = t.substr(1);
            ans.push_back(t1);
            return true;
        }
        
        for(int i=idx;i<s.size();i++){
           
            string temp = s.substr(idx  , i-idx+1);
            if(mp.find(temp)!=mp.end()){
                
                // if(vis.find(idx)==vis.end() || vis[idx]==true){
                    
                    if(check(s , i+1 , mp , t+" "+temp)){
                        vis[idx] = true;
                    }
                    
                // }
                
            }
                
        }
        
        if(vis.find(idx)==vis.end()){
            vis[idx] = false;
        }
        return false;
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string , bool>mp;
        for(auto i : wordDict){
            mp[i] = true;
        }
        
        check(s , 0 , mp , "");
        return ans;
    }
};