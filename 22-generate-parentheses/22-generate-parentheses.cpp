class Solution {
public:
    
    void check(int n , int m,int i, int j, string s, vector<string>&ans){
        if( i==n && j==m){
            ans.push_back(s);
            
            cout<<s<<"\n";
            return ;
        }else if(i>n || j>m || j>i) return ;
        
         check(n , m ,i+1 , j , s+'(' , ans);
           check(n , m , i , j+1 , s+')' , ans);
            
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>v;
        check(n , n,0,0 , s , v);
        return v;
    }
};