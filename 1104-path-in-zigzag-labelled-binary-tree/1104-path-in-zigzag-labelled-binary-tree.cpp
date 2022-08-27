class Solution {
public:
    int find_level(int l){
        int c  = 1;
        int total = 0;
        while(total < l){
            total+=c;
            c*=2;
        }
        return c;
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int>res;
        int llv = find_level(label);
        llv/=2;
        while(label!=1){
            res.push_back(label);
            int com = 3*llv - label-1;
            int par = com/2;
            label = par;
            llv/=2;
        }
        
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
        
    }
};