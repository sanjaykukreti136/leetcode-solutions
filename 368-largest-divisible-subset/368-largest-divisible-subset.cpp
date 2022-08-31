class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  n = nums.size();
        vector<int>hash(n , -1);
        vector<int>dp(n,0);
        int ans = INT_MIN;
        int id = -1;
        for(int i=0;i<nums.size();i++){
            int idx = -1;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0) || (nums[j]%nums[i]==0) ){
                    if(dp[j] > dp[i]){
                        dp[i]= dp[j];
                        idx= j;
                    }
                }
            }
            if(dp[i]==0){
                dp[i] = 1;
                hash[i] = i;
            }else{
                dp[i]+=1;
                hash[i] = idx;
            }
            if(dp[i] > ans){
                ans = dp[i];
                id = i;
            }
        }
        vector<int>res;
        while(id!=hash[id]){
            res.push_back(nums[id]);
            id  = hash[id];
        }
        res.push_back(nums[id]);
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};