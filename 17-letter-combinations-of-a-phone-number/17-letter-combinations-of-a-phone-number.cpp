class Solution {
public:
    vector<string>codes={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string s) 
    {        
      if(s.size()==0)
      {
       vector<string> empty;
       return empty;
      }
  char ch=s[0];
  string ros=s.substr(1);
  vector<string>ans=letterCombinations(ros);
  vector<string>myans;
  string codeforch=codes[ch-'0'];
  for(int i=0;i<codeforch.size();i++)
  {
    char chcode=codeforch[i];
     if(ans.size()!=0){
    for(string j:ans)
    {
        myans.push_back(chcode+j);
    }
     }else{
         string t="";
         myans.push_back(chcode+t);
     }
  }

  return myans;    
    }
};