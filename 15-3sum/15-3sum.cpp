class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>ans;
        if(nums.size() < 3) return ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int t = (nums[i]+nums[j])*(-1);
                int l = j+1 , r = nums.size()-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(nums[mid]==t){
                        vector<int>temp = { nums[i] , nums[j] , t };
                        ans.push_back(temp);
                        break;
                    }else if(nums[mid] > t){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
            }
        }
        return ans;
    }
};