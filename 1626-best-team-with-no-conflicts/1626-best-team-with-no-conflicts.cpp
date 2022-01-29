class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        for(int i=0;i<ages.size();i++){
            
            v.push_back({ages[i], scores[i]});
        }
        int n = ages.size();
        vector<int>dp(n , 0);
        int ans = 0;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            dp[i] = v[i].second;
            for(int j=i-1;j>=0;j--){
                if(v[i].second>=v[j].second){
                    dp[i] = max(dp[i] , dp[j] + v[i].second);
                }
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};