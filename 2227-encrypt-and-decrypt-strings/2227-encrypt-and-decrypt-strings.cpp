class Encrypter {
public:
    map<char,string>m;
    map<string,int>m2;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            m[keys[i]] = values[i];
        }
        
        for(auto i : dictionary){
            m2[encrypt(i)]++;
        }
        
    }
    
    string encrypt(string word1) {
      string s=  "";
        for(auto i : word1){
            s+=m[i];
        }
        return s;
    }
    
    int decrypt(string word2) {
        return m2[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */