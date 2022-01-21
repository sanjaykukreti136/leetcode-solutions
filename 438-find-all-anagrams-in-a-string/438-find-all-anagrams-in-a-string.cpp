class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(s.length() < p.length()) return ans;
        vector<int>st(26 , 0);
        vector<int>pt(26,0);
        for(auto i : p)  pt[i-'a']++;
        int i=0, j=0;
        while(j<s.length()){
            char ch = s[j];
            st[ch-'a']++;
            while(st[ch-'a'] > pt[ch-'a']){
                st[s[i]-'a']--;
                i++;
            }
            if(j-i+1 == p.length()){
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};