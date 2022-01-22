class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<map<char,int> , vector<string>>m;
        
        for(auto i : s){
            map<char,int>temp;
            for(auto j : i){
                temp[j]++;
            }
            if(m.find(temp)==m.end()){
                vector<string>t;
                t.push_back(i);
                m[temp] = t;
            }else{
                m[temp].push_back(i);
            }
        }
        
        vector<vector<string>>ans;
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
        
        
    }
};