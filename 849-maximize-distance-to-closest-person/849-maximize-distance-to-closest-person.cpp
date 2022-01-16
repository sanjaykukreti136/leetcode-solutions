class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = -1; 
        int ans= 0;
        int n= seats.size();
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                
                if(left == -1){
                    ans = max(ans , i);
                }else{
                    ans = max(ans, (i-left)/2);
                }
                left = i;
                
            }
        }
        
        if(seats[n-1]==0){
            ans = max(ans , n - 1 -  left);
        }
        return ans;
        
    }
};