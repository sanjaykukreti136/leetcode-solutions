class Solution {
public:
    int countTriplets(vector<int>& arr) {
      
        int c =0 ;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int val = arr[i];
            for(int j=i+1;j<n;j++){
                val = val ^ arr[j];
              if(val == 0)  c+=j-i;
            }
        }
        return c;
        
    }
};