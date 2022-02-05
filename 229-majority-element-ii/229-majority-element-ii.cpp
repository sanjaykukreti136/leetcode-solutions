class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = INT_MIN, c1 = 0;
        int val2 =INT_MIN , c2 =0;
        for(auto i : nums){
            if(i==val1){
                c1++;
            }else if(i==val2){
                c2++;
            }else{
                if(c1 == 0) {
                    c1= 1;
                    val1 = i;
                }
                else if(c2 == 0){
                  val2 = i;
                    c2 = 1;
                } 
                else{
                    c1--;
                    c2--;
                }
            }
        }
        vector<int>ans ; 
        c1 = 0;
        for(auto i : nums) if(i==val1) c1++;
        if(c1>(nums.size()/3)) ans.push_back(val1);
        
        c2 = 0;
        for(auto i : nums) if(i==val2) c2++;
        if(c2>(nums.size()/3)) ans.push_back(val2);
        return ans;
        
    }
};