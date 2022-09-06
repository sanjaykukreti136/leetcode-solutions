class Solution {
public:
    int missingNumber(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int idx = arr[i]==INT_MIN ? 0 : abs(arr[i]);
            if(idx>=arr.size()) continue;
            arr[idx]*= -1;
            arr[idx] = arr[idx]==0 ? INT_MIN : arr[idx];
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i] >= 0) return i;
        }
        
        return arr.size();
    }
};