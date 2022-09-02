class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                v.push(-1);
            }
            else {
                if(v.top()==(-1)){
                    v.pop();
                    v.push(1);
                }
                else{
                    int val=0;
                    while(v.top()!=-1){
                        val = val + v.top();
                        v.pop();
                    }
                    v.pop();
                    v.push(2*val);
                }
            }
        }
        int sum=0;
        while(!v.empty()){
            sum += v.top();
            v.pop();
        }
        return sum;
    }
};