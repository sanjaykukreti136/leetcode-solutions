class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int a[n+1];
        a[n] = INT_MAX;
        for(int i=n-1;i>=0;i--){
            a[i] = min(arr[i]  , a[i+1]);
        }
        
        int c = 0;
        int max_val = 0;
        for(int i=0;i<arr.size();i++){
            max_val = max(max_val , arr[i]);
            if(max_val <= a[i+1]){
                c++;
            }
        }
        return c;
        
    }
};