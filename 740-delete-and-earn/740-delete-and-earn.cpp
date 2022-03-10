class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = INT_MIN;
        for(auto i : nums){
            n = max(i , n);
        }
vector<int>a(n+1, 0);
        for(auto i : nums){
            a[i]+=1;
        }
        int inc=0;
        int exc = 0;
        for(int i=0;i<=n;i++){
            int ni = exc + a[i]*i;
            int ne = max(exc , inc);
            inc = ni;
            exc = ne;
        }
        return max(inc , exc);
    }
};