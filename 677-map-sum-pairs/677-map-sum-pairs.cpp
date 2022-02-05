struct Trie{
    Trie *child[26];
    bool isEnd;
    int c;
    Trie(){
        c = 0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    map<string,int>mp;
    void addWord(string word , int val) {
        int minus=0;
        if(mp.find(word)!=mp.end()){
            minus = mp[word];
            mp[word] = val;
        }else{
            mp[word] = val;
        }
        Trie *curr = root;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL){
            curr->child[ch-'a'] = new Trie();
          }
          curr->child[ch-'a']->c+=val-minus;
          curr = curr->child[ch-'a'];
        }

        curr->isEnd = true;
        // if(curr->isEnd)
    }
    
   int search(string word) 
    {
       string ans = "";
       Trie *curr = root;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL){
            return 0;

          }

          curr = curr->child[ch-'a'];
        } 
        return curr->c;
       
    }
};


class MapSum {
public:
    
     WordDictionary* obj = new WordDictionary();
     // obj->addWord(word);
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        obj->addWord(key , val);
    }
    
    int sum(string prefix) {
        return obj->search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */