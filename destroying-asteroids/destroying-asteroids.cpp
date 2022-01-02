class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& v) {
        long long ans = mass;
        sort(v.begin(),  v.end());
        for(auto i : v){
            if(i>ans && i>mass) return false;
            ans+=i;
        }
        return true;
    }
};