class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res= "";
        vector<int>v(26 , 0);
        vector<bool>vis(26 , false);
        
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            v[ch-'a']--;
            if(res.empty()){
                res.push_back(s[i]);
                vis[ch-'a'] = true;
                continue;
            }
            if(vis[ch-'a']) continue;
            while(ch < res.back() && !res.empty() && v[res.back()-'a']>0 ){
                
                vis[res.back()-'a'] = false;
                res.pop_back();
            }
            
            res.push_back(ch);
            vis[ch-'a']= true;
        }
        return res;
    }
};