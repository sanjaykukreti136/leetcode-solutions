class Solution {
public:
    
    vector<int>check(vector<int>a){
        if(a.size()==1) return a;
        vector<int>ans;
        for(int i=1;i<a.size();i++){
             a[i-1] =  ((a[i]+a[i-1])%10);
        }
        a.pop_back();
        return a;
    }
    
    int triangularSum(vector<int>& nums) {
        
        while(true){
            nums = check(nums);
            
            if(nums.size()==1){
                return nums[0];
            }
        }
        
    }
};