class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> count , match;
        for(auto i : words) count[i]++;
        int n = s.size();
        int l = words.size();
        int len = words[0].size();
        vector<int>ans;
        for(int i=0;i<(n-len*l+1);i++){
            
            for(int j=i;j<(i+l*len);j+=len){
                string temp  = s.substr(j , len);
                match[temp]++;
            }
            bool flag = 1;
            for(auto i : count){
                if(match[i.first]!=count[i.first]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag) ans.push_back(i);
            match.clear();
            
        }
        return ans;
    }
};