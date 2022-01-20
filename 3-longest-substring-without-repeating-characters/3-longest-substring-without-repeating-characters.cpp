class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans = 0;
        int start = 0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=i;
                ans = max(ans , i-start+1);
            }else{
                start = max(start , m[s[i]]+1 );
                ans = max(ans , i-start+1);
                m[s[i]] = i;
            }
        }
        // ans = max(ans , s.length()-start);
        return ans;
    }
};