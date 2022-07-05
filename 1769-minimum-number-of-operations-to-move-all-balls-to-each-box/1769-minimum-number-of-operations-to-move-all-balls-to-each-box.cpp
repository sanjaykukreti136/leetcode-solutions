class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_map<int,int>m;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                m[i] = 1;
            }
        }
        int n= boxes.size();
        vector<int>res(n, 0);
        for(int i=0;i<n;i++){
            int c = 0;
            for(auto j : m ){
                int x = j.first;
                c+=abs(i-x);
            }
            res[i] = c;
        }
        return res;
    }
};