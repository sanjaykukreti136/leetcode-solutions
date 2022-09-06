class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>m;
        for(auto i : wall){
            int s = 0;
            for(int j=0;j<i.size()-1;j++){
                s+=i[j];
                m[s]++;
            }
        }
        
        int n = wall.size();
        int ans = 0;
        for(auto i : m){
            ans = max(ans , i.second);
        }
        return n-ans;
        
    }
};