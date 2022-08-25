class Solution {
public:
    int kSimilarity(string A, string B) {
        vector<vector<int>>vis(6);
        queue<pair<string,int>>q;
        q.push({A,  0});
        
        for(int i=0;i<B.length();i++) vis[B[i]-'a'].push_back(i);
        while(!q.empty()){
            string curr = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(curr == B) return dis;
            int i =0;
            for(;i<B.length();i++) if(B[i]!=curr[i]) break;
            char ch = curr[i];
            for(auto j : vis[ch-'a']){
                if(curr[j]!=B[j]){
                    string temp = curr;
                    temp[i] = curr[j];
                    temp[j] = curr[i];
                    q.push({temp, dis+1});
                }
            }
        }
        return -1;
        
    }
};