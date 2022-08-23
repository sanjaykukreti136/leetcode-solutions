class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         set<string>st;
         for(auto i : wordList) st.insert(i);
        
        queue<string>q;
        q.push(beginWord);
        int seq = 0;
        while(!q.empty()){
            
            int x = q.size();
            seq++;
            while(x--){
                
                string s = q.front();
                q.pop();
                if(s == endWord) return seq;
                
                for(int i=0;i<s.size();i++){
                    string temp = s;
                    for(char ch = 'a';ch<='z';ch++){
                        temp[i] = ch;
                        
                        if(temp == s) continue;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                        
                    }
                    
                }
                
            }
            
        }
        return 0;
    }
};