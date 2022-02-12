class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        bool ans = false;
        queue<string>q;
        for(auto i : wordList){
            if(i.compare(endWord)== 0){
                ans = true;
            }
            s.insert(i);
        }
        q.push(beginWord);
        if(ans == false) return 0;
        int depth = 0;
        while(!q.empty()){
            depth+= 1;
            int lsize = q.size();
            while(lsize--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(char j= 'a' ;j<='z';j++){
                        temp[i] = j;
                        if(endWord.compare(temp)==0){
                            return depth+1;
                        }
                        if(temp.compare(curr)==0){
                            continue;
                        }
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};