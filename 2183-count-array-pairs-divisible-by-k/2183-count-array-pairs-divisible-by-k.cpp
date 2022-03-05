class Solution {
public:
    long long countPairs(vector<int>& nums, int k) { 
        long long ans = 0;
        map<long long , long long >mp;
        for(auto &i : nums){
            long long gc = __gcd(i, k);
            
            for(auto j : mp){
                if((j.first*gc)%k==0){
                    ans+= j.second;
                }
            }
            mp[gc]++;
        }
        return ans;
    }
};