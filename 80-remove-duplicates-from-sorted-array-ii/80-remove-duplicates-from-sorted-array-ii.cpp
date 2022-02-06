class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s =1;
        int temp =1;
        int prevValue = nums[0];
        for(int i=1;i<nums.size();i++){
            if(prevValue == nums[i]){
                temp++;
                prevValue = nums[i];
                if(temp <= 2){
                    swap(nums[s], nums[i]);
                    s++;
                }
            } else {
                prevValue = nums[i];
                swap(nums[s], nums[i]);
                s++;
                temp=1;
            }
            if(i == nums.size()-1){
                return (s);
            }
        }
        return 1; // if the size of nums.size() == 1
    }
};