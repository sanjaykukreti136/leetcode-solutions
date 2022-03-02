class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>a(n+1);
        a[0] = 0;
        // a[1] = 1;
        // a[2] = 1;
        for(int i=1;i<=n;i++){
            int idx = i/2;
            int c = a[idx];
            if(i%2!=0){
                c+=1;
            }
            a[i] = c;
        }
        return a;
    }
};