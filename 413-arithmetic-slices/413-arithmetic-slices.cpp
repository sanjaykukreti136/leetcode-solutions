class Solution {
public:
    
    int check(vector<int>&nums, int i){
        int c = 0;
        vector<int>v;
        while(i<nums.size()-1){
            v.push_back(nums[i]-nums[i+1]);
            i++;
        }
        if(v.size()==0) return 0;
        int val  = v[0];
        for(auto i : v){
            if(i==val) c++;
            else break;
        }
        if(c<2) return 0;
        else{
            return c-3+2;
        }
        return 0;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c = 0;
        for(int i=0;i<nums.size();i++){
            // if(check(nums , i)) c++;
            c+= check(nums , i);
        }
        return c;
    }
};