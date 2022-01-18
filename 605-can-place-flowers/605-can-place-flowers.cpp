class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int c = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0 &&  i==0 ){
                if(i+1 == v.size() || v[i+1]==0 ){
                    v[i] = 1;
                    c++;
                }
            }
            else if(v[i]==0 && v[i-1]==0 && v[i]==0 && ( i+1 == v.size() ||  v[i+1]==0)){
                v[i] = 1;
                c++;
            }
            
        }
        return c>=n;
    }
};