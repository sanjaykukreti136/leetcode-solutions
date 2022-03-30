class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int count = 0;
            unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp[s[j]] == k) count++;
                if(count == mp.size()) ans = max(ans,j-i+1);
            }
        }      
        return ans;
    }
};