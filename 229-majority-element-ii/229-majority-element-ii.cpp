class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, ans1 = INT_MIN;
        int c2 = 0, ans2 = INT_MIN;
        
        for(auto i : nums){
            
            if(i==ans1){
                c1++;
                ans1 = i;
            }
            else if(i==ans2){
                c2++;
                ans2 = i;
            }
            else{
                if(c1==0){
                    ans1 = i;
                    c1=1;
                }else if(c2 == 0){
                    ans2 = i;
                    c2 = 1;
                }else{
                c1--;
                c2--;
                }
            }
            
        }
        cout<<ans1<<" "<<ans2<<"\n";
        c1 = 0;
        for(auto i : nums) if(i==ans1) c1++;
        c2 = 0;
        for(auto i : nums) if(i==ans2) c2++;
        vector<int>res;
        if(c1 > nums.size()/3) res.push_back(ans1);
        if(c2 > nums.size()/3) res.push_back(ans2);
        return res;
        
    }
};