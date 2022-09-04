class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        int n = v.size();
        vector<int>res(n);
        
        // res.push_back(-1);
        res[n-1] = -1;
        int idx  = n-1 , val = v[n-1];
        // val = max()
        for(int i=v.size()-2;i>=0;i--){
            if(val  > v[i]){
                res[i] = idx;
                
            }else if(v[i] > val){
                val = v[i];
                idx = i;
                res[i] = -1;
            }else{
                res[i] = -1;
            }
        }

        for(int i=0;i<v.size();i++){
            cout<<res[i]<<" ";
            if(res[i]!=-1){
                swap(v[i], v[res[i]]);
                break;
            }
        }
        int ans = 0;
        for(auto i : v){
            ans = ans*10 + i;
        }
        return ans;
    }
};