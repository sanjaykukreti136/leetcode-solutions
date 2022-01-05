class Solution {
public:
    bool isp(string s){
    int i=0, j= s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    void check(string s,  vector<vector<string>>&ans, vector<string>temp){
         
        if(s.length()==0){
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<s.length();j++){
        string left = s.substr(0, j+1);
        string right = s.substr(j+1);
        if(isp(left)){
            temp.push_back(left);
            check(right, ans, temp );
            temp.pop_back();
           }
        
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        check(s, ans, temp);
        return ans;
    }
};