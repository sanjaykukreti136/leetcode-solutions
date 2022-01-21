class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minus =0;
        int val = 0;
        int start = 0;
        for(int i= 0;i<gas.size();i++){
            val+= gas[i]-cost[i];
            if(val < 0 ){
                start = i+1;
                minus+= val;
                val =0;
            }
        }
        if(val +minus >=0) return start;
        return -1;
    }
};