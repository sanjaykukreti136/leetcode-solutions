class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int si=0;
        int ei=0;
        int prev = 0;
        int count = 0;
        while(ei < nums.size()){
            if(nums[ei] >=left && nums[ei]<=right){
                prev = ei-si+1;
                count+= prev;
            }
            else if(nums[ei] < left){
                count+= prev;
            }
            else if(nums[ei] > right){
                prev = 0;
                si = ei+1; 
            
            }
            ei++;
        }
        return count;
    }
};