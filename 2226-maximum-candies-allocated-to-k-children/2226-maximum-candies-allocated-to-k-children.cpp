class Solution {
public:
    
    bool check(long long  v , vector<int>&candies , long long k){
        long long c = 0;
        // cout<<v<<"\n";
        for(auto i : candies){
            c+=(i/v);
        }
        return c>=k;
    }
    
    long long sumof(vector<int>&v){
        int  s = 0;
        for(auto i : v){
            s = max(s , i);
        }
        return (long long)s;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long  s = INT_MAX , e = sumof(candies);
        
        s=1;
        int ans =0 ;
        while(s<=e){
            long long  mid = s + (e -s)/2;
            if(check(mid , candies , k)){
                ans = max(ans , (int)mid);
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};