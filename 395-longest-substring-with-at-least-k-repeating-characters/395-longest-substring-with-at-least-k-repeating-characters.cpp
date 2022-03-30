class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int ans = 0;
        for(int h=1;h<=26;h++){
            vector<int>a(26 , 0);
            
            int i=0,j=0, ele = 0 , toK = 0;
            while(j<s.size()){
                if(ele <= h){
                    int idx = s[j]-'a';
                    
                    if(a[idx]==0) ele++;
                    a[idx]++;
                    if(a[idx]==k) toK++;
                    j++;
                }else{
                    int idx = s[i]-'a';
                    if(a[idx] == k ) toK--;
                    a[idx]--;
                    if(a[idx]==0){
                        ele--;
                    }
                    i++;
                }
                if(ele == h && ele==toK){
                ans = max(ans , j-i);
            }
            }
            
        }
        return ans;
    }
};