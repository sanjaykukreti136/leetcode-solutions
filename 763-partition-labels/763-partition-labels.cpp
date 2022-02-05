class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]] = i;
        }
        vector<int>ans ; 
        int prev = -1;
        int c = 0;
        for(int i=0;i<s.size();i++){
            c = max(c , m[s[i]]);
            if(c == i){
                ans.push_back(c-prev);
                prev = i;
            }
        }
        return ans;
    }
};