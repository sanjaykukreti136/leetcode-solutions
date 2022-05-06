class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st; //making stack with pair which store no of times a char occur in string
        for(auto c:s){
            if(!st.empty()&&st.top().first==c){
                ++st.top().second;//incrementing count of similar char 
            }
            else{
                st.push({c,1}); //pushing a new char with count 1
            }
            
            if(st.top().second==k){
                st.pop(); //remove the char if it's equals the target
            }
        }
        string ans="";
        while(st.empty()==false){
           pair<char,int>c=st.top();//making pair of top of stack char make the resultant string
            for(int i=0;i<c.second;i++){
                ans.push_back(c.first);
            }
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};