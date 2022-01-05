class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        m['a']=0;
        m['b']=0;
        m['c']=0;
        int l =0, r=0 , ans =0;
        m[s[0]]=1;
        int n = s.length();
        while(r < s.length()){
            if(m['a'] && m['b'] && m['c'] ){
                ans += n-r;
                m[s[l++]]--;
                
            }else{
                r++;
                m[s[r]]++;
                // r++;
            }
        }
        return ans;
    }
};