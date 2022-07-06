class Solution {
public:
    int mod = 1e9+7;
    int maxSubarraySum(vector<int>&arr){
        int s=0;
        int res = 0;
        for(auto i : arr){
            s= (s%mod + i%mod)%mod;
            res = max(res , s);
            if(s<0){
                s = 0;
            }
        }
        return res;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long  s =0 ;
        for(auto i : arr) s+=i;
        if(s<=0){
            vector<int>arr1;
            for(auto i : arr){
                arr1.push_back(i);
            }
            for(auto i : arr){
                arr1.push_back(i);
            }
            return max(maxSubarraySum(arr), k>1 ?  maxSubarraySum(arr1) : 0);
        }
        else{
            s=((s%mod)*(k-1)%mod)%mod;
            int n = arr.size();
            vector<int>a(n,0);
            a[0] = arr[0];
            int res = a[0];
            for(int i=1;i<n;i++){
                a[i] = arr[i] + a[i-1];
                res = max(res , a[i]);
            }
            int minv = 0;
            for(int i=n-1;i>=0;i--){
                if(a[i]<0){
                    minv = min(a[i],minv);
                }
            }
            return ((s%mod)+(res%mod)+(abs(minv)%mod))%mod;
        }
    }
};