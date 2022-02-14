class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int first_even = 0 , freq_first_even =0;
        int second_even = 0 , freq_second_even =0;
        int first_odd = 0 , freq_first_odd =0;
        int second_odd = 0 , freq_second_odd =0;
        int n= nums.size();
        int even[100001]={0};
        int odd[100001]= {0};
        int maxv=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                even[nums[i]]++;
            }else{
                odd[nums[i]]++;
            }
            maxv = max(maxv , nums[i]);
        }
        
        for(int i=1;i<=maxv;i++){
            
            if(even[i] >= freq_first_even){
                freq_second_even = freq_first_even;
                second_even = first_even;
                first_even = i;
                freq_first_even = even[i];
                
            }else if(even[i] > freq_second_even){
                freq_second_even = even[i];
                second_even = i;
            }
            
            
        if(odd[i] >= freq_first_odd){
                freq_second_odd = freq_first_odd;
                second_odd = first_odd;
                first_odd = i;
                freq_first_odd = odd[i];
                
            }else if(odd[i] > freq_second_odd){
                freq_second_odd = odd[i];
                second_odd = i;
            }
            
        }
        
        if(first_even != first_odd){
            return n-freq_first_even - freq_first_odd;
        }else{
            return min(n-freq_first_even-freq_second_odd , n - freq_second_even - freq_first_odd);
        }
        
    }
};