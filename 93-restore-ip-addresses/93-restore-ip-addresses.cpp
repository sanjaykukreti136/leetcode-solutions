class Solution {
public:
    bool isvalid(string &s)
    {
        if(s.length()>3)
        {
            return false;
        }
        if(s[0]=='0' && s.length()>1)
        {
            return false;
        }
        int num=stoll(s);
        return num>=0 && num<=255;
    }
    vector<string> restoreIpAddresses(string s) {
      int n = s.length();
       vector<string>v;
       for(int i=1;i<n && i<4 ;i++){
           string first= s.substr(0 , i);
          // if(isvalid(first)){
             if(isvalid(first)){
               
               for(int j =1 ;(i+j)<n && j<4;j++){
                   string second= s.substr(i, j);
                   if(isvalid(second)){
                       if(!isvalid(second)) continue;
                       for(int k =1;(i+j+k)<n && k<4;k++){
                           
                           string third = s.substr(i+j, k);
                           string fourth = s.substr(i+j+k);
                           
                            if(!isvalid(third) || !isvalid(fourth)) continue;
                           if(isvalid(third) && isvalid(fourth)){
                               string temp = first+"."+second+"."+third+"."+fourth;
                               v.push_back(temp);
                           }
                       }
                       
                  }
                   
               }
               
           }
       }
       return v;
    }
};