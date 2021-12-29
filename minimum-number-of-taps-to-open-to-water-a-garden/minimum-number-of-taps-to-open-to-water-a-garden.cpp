class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int minv = 0 , maxv = 0;
        int c=0;
        while(maxv < n){
            
            for(int i=0;i<ranges.size();i++){
                if((i-ranges[i])<=minv && (i+ranges[i])>maxv ){
                    maxv = i+ranges[i];
                }
            }
            if(maxv==minv) return -1;
            c++;
            minv  = maxv;
            
        }
        return c;
    }
};