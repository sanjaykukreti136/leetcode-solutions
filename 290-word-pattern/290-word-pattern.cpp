class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string>m1;
        map<string,char>m2;
        istringstream s(str);
        string word;
        int i=0;
        while(s>>word){
            if(i==pattern.length()) return false;
            char pt = pattern[i++];
            
            if( m2.find(word)==m2.end() && m1.find(pt)==m1.end() ){
                m2[word] = pt;
                m1[pt] = word;
                continue;
            }
            
            if(m2[word]!=pt) return false;
            
        }
        return i==pattern.length();
    }
};