class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxr = 0, c=0;
        for(int i=0;i<arr.size();i++){
            maxr = max(maxr , arr[i]);
            if(maxr == i) c++;
        }
        return c;
    }
};