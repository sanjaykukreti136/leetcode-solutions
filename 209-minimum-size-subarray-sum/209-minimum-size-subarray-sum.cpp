class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        map<int,int>m;
        int s =0 ;
        int i = 0 , j = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            s+=nums[j++];
            while(s>=t){
                ans = min(ans , j-i);
                s-=nums[i];
                i++;
            }
            // j++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};