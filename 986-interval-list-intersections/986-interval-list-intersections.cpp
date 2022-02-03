class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>>ans;
        int i=0, j= 0;
        while(i<f.size() && j<s.size()){
            int f_s = f[i][0];
            int f_e = f[i][1];
            int s_s=  s[j][0];
            int s_e = s[j][1];
            
            int start = max(f_s, s_s);
            int end = min(f_e , s_e);
            if(start<=end){
            vector<int>t = { start , end};
            ans.push_back(t);
            }
            if(f_e < s_e) i++;
            else if(f_e > s_e) j++;
            else {
                i++;
                j++;
            }
        }
        return ans;
    }
};