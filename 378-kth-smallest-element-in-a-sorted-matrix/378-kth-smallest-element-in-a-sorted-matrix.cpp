class Solution {
public:
    
    int check(vector<vector<int>>&matrix , int target , int n){
        int r = 0 , c = n-1;
        int count = 0;
        while(r < n && c>=0){
            if(matrix[r][c]<=target){
                r++;
                count+=c+1;
                
            }else{
                while(c>=0 && matrix[r][c] > target){
                    c--;
                }
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int minv = matrix[0][0] , maxv = matrix[n-1][n-1];
        
        int ans = 0;
        while(minv <= maxv){
            int mid = (maxv + minv)/2;
            
            int count = check(matrix , mid , n );
            if(count >= k){
                maxv = mid-1;
                ans  = mid;
            }else{
                minv = mid+1;
            }
        }
        return ans;
        
    }
};