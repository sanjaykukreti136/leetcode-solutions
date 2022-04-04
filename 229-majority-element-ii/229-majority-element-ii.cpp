class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0 , val1 = INT_MIN;
        int c2 = 0 , val2 = INT_MIN;
        
        
         // 1 
        // x-y   
         
//           1 2 
//           1 -1 
//           2- 1
        
        for(auto i : nums){
            if(i==val1){
                c1++;
            }
            else if(i==val2){
                c2++;
            }else{

                if(c1==0){
                    c1 = 1;
                    val1 = i;
                }
                else if(c2==0){
                    c2 = 1;
                    val2 = i;
                }else{
                    c1--;
                    c2--;
                }
            }
        }
        int c = 0;
        vector<int>ans;
        for(auto i : nums){
            if(i==val1) c++;
        }
        if(c>nums.size()/3){
            ans.push_back(val1);
        }
        c=0;
        // if(val1 == val2) return ans;
        for(auto i : nums){
            if(i==val2) c++;
        }
        if(c>nums.size()/3){
            ans.push_back(val2);
        }
        return ans;
     }
};