class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        bool x = false;
        for(auto i : wordList){
            st.insert(i);
            if(i==endWord) x = true;
        }
        
        if(x==false) return 0;
        queue<string>q;
        q.push(beginWord);
        int d = 0;
        while(!q.empty()){
            d+=1;
            int x = q.size();
            while(x--){
                string s = q.front();
                q.pop();
                for(int i=0;i<s.size();i++){
                    string temp = s;
                    for(char j = 'a';j<='z';j++){
                        temp[i] = j;
                        if(temp.compare(endWord)==0) return d+1;
                        if(temp.compare(s)==0) continue;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                            // break;
                        }
                    }
                }
            }
        }
        return 0;
    }
};