class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int>ans(n);
        int i=1 , k = n-1;
        while(i<n){
            ans[i]=a[k];
            k--;
            i+=2;
        }
        i=(n%2==0) ? n-2 : n-1 ,k=0;
        while(i>=0){
            ans[i] = a[k];
            k++;
            i-=2;
        }
        a = ans;
        
    }
};