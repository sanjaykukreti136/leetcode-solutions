class Solution {
public:
    
    bool check(vector<int>candies , long long k , long long val){
        long long c=0;
        for(auto i : candies){
            c+=i/val;
            if(c>=k) return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long  long  l =0 , h = *max_element(candies.begin(), candies.end());
        long  long  ans = 0;
        while(l<=h){
            long long mid = (l+h)/2;
            if(mid==0 || check(candies , k , mid)){
                l = mid+1;
                ans = mid;
            }else{
                h  = mid-1;
            }
        }
        return ans;
    }
};