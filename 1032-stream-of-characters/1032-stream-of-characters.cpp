
class Node {
    Node * child[26];
    bool eow;
public:
    Node():eow(false)
    {
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }
    
    void insert(string s)
    {
        Node *t=this;
        for(char c:s)
        {
            if(t->child[c-'a']==nullptr)
                t->child[c-'a']=new Node();
            t=t->child[c-'a'];
        }
        t->eow=true;
    }
    
    bool search(deque<char>& s){
        
        Node * t=this;
        
        for(char c:s){
            if(t->child[c-'a']==nullptr)return false;
            t=t->child[c-'a'];
            if(t->eow)return true;
        }
        return false;
    }
};

class StreamChecker {
    public:
   // StreamChecker(vector<string>& words) {
        
        Node node;
        deque<char> stream;
        
        
          StreamChecker(vector<string>& words){
              for(string& w : words){
                  reverse(w.begin(),w.end());
                  node.insert(w);
              }
          }
    
    
    bool query(char letter) {
        
        stream.push_front(letter);
        return node.search(stream);
    }
};

// class Trie {
// public:
    

//     Trie* child[26];
//     bool isEnd;
//     Trie() {
        
//         isEnd = false;
//         for(int i=0;i<26;i++)
//             child[i]=NULL;
//     }
//     ~Trie() {for (int i=0; i<26; i++) if (child[i] != nullptr) delete child[i]; }
//     void insert(string word) 
//     {
//         Trie *curr = this;
//         for(int i=word.size()-1;i>=0;i--){
//           char ch = word[i];
//           if(curr->child[ch-'a']==NULL){
//             curr->child[ch-'a'] = new Trie();
//           }
//           curr = curr->child[ch-'a'];
//         }
//         curr->isEnd = true;
//     }
    
//     bool search(string word , Trie *t) 
//     {
//        Trie *curr = t;
//         for(int i=0;i<word.size();i++){
//           char ch = word[i];
//           if(curr->isEnd) return true;
//           if(curr->child[ch-'a']==NULL) return false;   
//           curr = curr->child[ch-'a'];
//         } 

//         if(curr->isEnd) return true;  
//         return false;
//     }

// };




// class StreamChecker {
// public:
    
    
    
    
//     Trie *t = new Trie();
//     StreamChecker(vector<string>& words) {
//         for(auto i : words){
//             // reverse(i.begin(), i.end());
//             t->insert(i);
//         }
//     }
//     string s = "";
//     bool query(char letter) {
//         s=letter+s;
        
//         return t->search(s , t);
//     }
// };

// /**
//  * Your StreamChecker object will be instantiated and called as such:
//  * StreamChecker* obj = new StreamChecker(words);
//  * bool param_1 = obj->query(letter);
//  */