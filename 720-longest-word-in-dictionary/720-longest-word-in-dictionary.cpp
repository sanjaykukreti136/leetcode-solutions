
class Trie {
public:
    

    Trie* child[26];
    bool isEnd;
    Trie() {
        
        isEnd = false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
   
    void insert(string word) 
    {
        Trie *curr = this;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL){
            curr->child[ch-'a'] = new Trie();
          }
          curr = curr->child[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    // void dfs(/)
    
};



class Solution {
public:
    string ans = "";
    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    void dfs(Trie *root , string s){
        if(root->isEnd==true){
            if(s.size() > ans.size()){
                ans = s;
            }
        }
        
        for(int i=0;i<26;i++){
            if(root->child[i]!=NULL && root->child[i]->isEnd ){
                dfs(root->child[i] , s+arr[i] );
            }
        }
        
        
    }
    
    string longestWord(vector<string>& words) {
        Trie *t = new Trie();
        for(auto i : words){
            t->insert(i);
        }
        dfs(t , "");
        return ans;
    }
};