class WordDictionary {
public:
    
   class Trie{
        public :
         Trie *child[26];
         bool isEnd;
        
        Trie(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            isEnd = false;
        }
    };
    Trie *root;
    WordDictionary() {
          root= new Trie();
    }
    
    void addWord(string word) {
        
        Trie *t = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(t->child[ch-'a']==NULL){
                t->child[ch-'a'] = new Trie();
            }
            t = t->child[ch-'a'];
        }
        t->isEnd = true;
        
    }
    
      bool check(Trie *curr, string s, int idx){
        
        if(idx == s.length()){
            if(curr->isEnd) return true;
            return false;
        }
        
        
        char ch = s[idx];
        if(ch!='.'){
            if(curr->child[ch-'a']==NULL) return false;
            return check(curr->child[ch-'a'] , s , idx+1);
        }else{
            
            for(int i=0;i<26;i++){
                if(curr->child[i]!=NULL){
                    if(check(curr->child[i] , s , idx+1)==true) return true;
                }
            }
            return false;
            
        }
        
    }
    
    bool search(string word) {
         Trie *curr = root;
         return check(curr , word , 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */