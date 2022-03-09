class Solution {
public:

    map<pair<string,string>,bool> mp;
    
    bool check(string a, string b){
       
     
        if(mp.find({a,b})!=mp.end()) return mp[{a,b}];
        if(a==b) return mp[{a,b}]=true;
        if(a.length()<=1 || b.length()<=1) return mp[{a,b}]=false;
        int sum1=0;
        int sum2=0;
        for(int i=0; i<a.length(); i++){
            sum1=sum1+int(a[i]);
        }
        for(int i=0; i<b.length(); i++){
            sum2=sum2+int(b[i]);
        }
        if(sum1!=sum2) return mp[{a,b}]=false;
        
        int n=a.length();
        bool f   = false;
        for(int i=1; i< a.length(); i++){
            if( check(a.substr(0,i),b.substr(0,i)) && check(a.substr(i,n-i),b.substr(i,n-i)) ){
                 f = true;
                 break;
             }
            if( check(a.substr(0,i),b.substr(n-i,i)) && check(a.substr(i,n-i),b.substr(0,n-i))) {
                 f =  true;
                 break;
             }
        }
        return mp[{a,b}]=f;
        
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;        
        return check(s1,s2);
    }
};