class Solution {
public:
    
    bool isEqual(map<char,int>m1, map<char,int>m2){
        for(auto i : m1){
            if(m2.find(i.first)==m2.end() || m2[i.first]!=i.second) return false;
            m2.erase(i.first);
        }
        return m2.size()==0;
    }
    
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m1;
        for(auto i : p) m1[i]++;
        int i=0, j=0;
        map<char,int>m2;
        for(i=0;i<p.length();i++){
            m2[s[i]]++;
        }
        vector<int>ans;
        while(i < s.length()){
            if(isEqual(m1 , m2)==true){
                ans.push_back(j);
            }
            m2[s[i]]++;
            
            m2[s[j]]--;
            if(m2[s[j]]==0) m2.erase(s[j]);
            i++;
            j++;
        }
        if(isEqual(m1 , m2)==true){
                ans.push_back(j);
        }
        
        
        return ans;
    }
};