class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int>v;
        int j=0;
        for(auto i : pushed){
            v.push_back(i);
            while(!v.empty() && v[v.size()-1]==popped[j]){
                v.pop_back();
                j++;
            }
        }
        return v.empty();
    }
};