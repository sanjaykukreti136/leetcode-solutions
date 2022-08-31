class Solution {
public:
    
    bool lcs(string prev, string curr){
         	int n = prev.size(), m = curr.size();
        
        // as only 1 character can be added to prev to get curr
		if (n+1 != m) {
            return false;
        }

        int i=0, j=0;
		while (j < m) {
			if (prev[i] == curr[j]) {
				i++, j++;
			}
			else j++;
		}

        // if the prev doesn't reach its end then its not predecessor
		return i==n;
    }
    
    static bool cmp(string a , string b){

        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end() , cmp);
        vector<int>dp(words.size() , 0);
        int ans= 0;
        for(int i=0;i<words.size();i++){
            dp[i] = 0;
            for(int j=0;j<i;j++){
                
                if(lcs(words[j],words[i])){
                    dp[i] = max(dp[i], dp[j]);
                }
                
            }
            dp[i]+=1;
            ans= max(ans , dp[i]);
        }
        
        return ans;
    }
};