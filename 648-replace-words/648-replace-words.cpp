struct Trie{
    Trie *child[26];
    bool isEnd;
    
    Trie(){
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
    
    void addWord(string word) {
        Trie *curr = root;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL){
            curr->child[ch-'a'] = new Trie();
          }
          curr = curr->child[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    int search(string word) 
    {
        Trie *curr = root;
        for(int i=0;i<word.size();i++){
          char ch = word[i];
          if(curr->child[ch-'a']==NULL || curr->isEnd ){
            if(curr->isEnd) return i;
            else return 0;

          }
          curr = curr->child[ch-'a'];
        } 

        if(curr->isEnd) return word.size();  
        return -1;
    }

};



class Solution {
public:
    
    
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
           WordDictionary* obj = new WordDictionary();
           // obj->addWord(word);
           for(auto i : dictionary) obj->addWord(i);
           istringstream str(sentence);
           string word;
          string ans  ="";
           while(str>>word){
               int idx = obj->search(word);
               if(idx==0){
                   ans+=word;
               }else{
                   ans+= word.substr(0 , idx);
               }
               ans+=" ";
           }
        int n = ans.size();
        return ans.substr(0 , n-1);
    }
};