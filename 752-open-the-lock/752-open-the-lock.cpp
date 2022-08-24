class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>m;
        for(auto i : deadends) m[i]++;
        if(m.find("0000")!=m.end()) return -1;
        unordered_set<string>st;
        queue<string>q;
        q.push("0000");
        st.insert("0000");
        int dis = -1;
        while(!q.empty()){
            int size = q.size();
            dis++;
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == target) return dis;
                string up = curr;
                string down = curr;
                for(int i=0;i<4;i++){
                    up = down = curr;
                    up[i] = ( up[i]=='9' ? '0' : up[i]+1 );
                    down[i] = down[i]=='0' ? '9' : down[i]-1;
                    
                    if(st.find(up)==st.end() &&  m.find(up)==m.end() ){
                        st.insert(up);
                        q.push(up);
                    }
                    
                    if(st.find(down)==st.end() && m.find(down)==m.end()){
                        st.insert(down);
                        q.push(down);
                    }
                    
                }
            }
            
        }
        return -1;
    }
};