class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int s = 0 , i=0 , j=0 , res= INT_MAX;
        while(i<nums.size() && j<nums.size()){
            
            while(i<nums.size() && s<t ){
                s+=nums[i++];
                if(s > t) break;
                // i++;
            }
           if(s>=t) res = min(res, i-j);
            while(j<nums.size() && s>=t){
                s-=nums[j++];
                if(s>=t) res = min(res, i-j);
                // j++;
            }
            
        }
        return res==INT_MAX ? 0 : res;
    }
};