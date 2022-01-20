class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
        for(auto i : t) m[i]++;
        int s1 =0, e =0, d = INT_MAX , h= 0;
        int c = m.size();
        while(e < s.length()){
            m[s[e]]-=1;
            if(m[s[e++]]==0) c--;
            while(c == 0){
                if(d > e-s1) d = e-(h = s1);
                if(m[s[s1++]]++==0) c++;
            }
        }
        
        return d==INT_MAX ? "" : s.substr(h , d);
    }
};