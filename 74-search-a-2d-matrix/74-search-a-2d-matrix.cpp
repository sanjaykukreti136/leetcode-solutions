class Solution {
public:
    bool search(vector<vector<int>>&v, int row , int t){
        int i = 0;
        int j = v[0].size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(v[row][mid]==t) return true;
            if(v[row][mid] > t){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& v, int t) {
        
        int n = v.size();
        int m = v[0].size();
        for(int i =0;i<n;i++){
            
            if(t>=v[i][0] && t<=v[i][m-1]){
                return search(v , i  , t );
            }
            else if(i-1>=0 &&  v[i-1][m-1] > t) return false;
        }
        return false;
        
    }
};