class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, set<int>>m;
        m[stones[0]].insert(1);
        for(int i = 0;i<stones.size();i++){
            int idx = stones[i];
            set<int>jumps = m[idx];
            for(auto jump : jumps){
                int pos = jump+idx;
                if(pos == stones[stones.size()-1]) return true;
                if(jump -1 > 0){
                    m[pos].insert(jump-1);
                }
                m[pos].insert(jump);
                m[pos].insert(jump+1);
                
            }
        }
        return false;
    }
};