
class Trie {
public:
    

  Trie* child[26];
    bool isEnd;
    // Trie *root;
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

    bool search(string word) 
    {
       Trie *curr = this;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL){
            return false;

          }
          curr = curr->child[ch-'a'];
        } 

        if(curr->isEnd) return true;  
        return false;
    }

 
    bool startsWith(string prefix) 
    {
        Trie *curr = this;
        for(int i=0;i<prefix.size();i++){
          char ch = prefix[i];
          if(curr->child[ch-'a']==NULL){
            return false;

          }
          curr = curr->child[ch-'a'];
          
        } 
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */