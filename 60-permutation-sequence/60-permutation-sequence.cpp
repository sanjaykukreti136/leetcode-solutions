class Solution {
public:
    
    int factorial( int n)
    {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
    vector<int>index;
    void solve(string &ans , int n , int k){
        
            if(n==1){
                ans+=to_string(index.back());
                return ;
            }
            int f = factorial(n-1);
            int idx = k/f;
            if(k%f == 0){
                idx-=1;
            }
            int val = index[idx];
            index.erase(index.begin() + idx);
            ans+=to_string(val);
            k-=f*idx;
            solve(ans , n-1 , k);
    }
    
    string getPermutation(int n, int k) {
        string ans = "";

        for(int i=1;i<=n;i++){
            index.push_back(i);
        }
        solve(ans  , n , k);
        return ans;
    }
};