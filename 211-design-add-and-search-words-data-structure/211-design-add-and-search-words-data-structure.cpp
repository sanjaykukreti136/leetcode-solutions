class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
     map<int,vector<string>> m;
    void addWord(string word) {
       
        int len=word.size();
        m[len].push_back(word);        
    }
    
    bool searchHelper(string s1,string s2,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(s2[i]=='.') continue;
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    
    bool search(string word) {
        int len=word.size();
        vector<string> str=m[len];
        for(auto ele : str)
        {
            if(searchHelper(ele,word,len)) return true;
        }
        return false;
    }
};