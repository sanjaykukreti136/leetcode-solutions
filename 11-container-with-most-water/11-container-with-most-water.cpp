class Solution {
public:
    int maxArea(vector<int>& v)  {
        int i=0, j= v.size()-1;
        int ans = 0;
        while(i<=j){
            ans = max(ans , min(v[i],v[j])*(j-i) );
            if(v[i]<v[j]) i++;
            else j--;
        }
        return ans;
    }
};