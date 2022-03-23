class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        
        vector<int>res;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int>res1 =diffWaysToCompute(s.substr(0 , i));
                vector<int>res2 =diffWaysToCompute(s.substr(i+1));
                for(auto a : res1){
                    for(auto b : res2){
                        if(ch=='+') res.push_back(a+b);
                        else if(ch=='-') res.push_back(a-b);
                        else res.push_back(a*b);
                    }
                }
            }
        }
        if(res.size()==0){
            res.push_back(stoi(s));
        }
        return res;
    }
};