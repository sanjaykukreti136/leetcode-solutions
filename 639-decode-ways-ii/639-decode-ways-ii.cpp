
class Solution {
public:
    long mod = 1000000007;
    long helper(vector<long> &dp, string &s, int indx) {
        if (s.size() == indx) return 1;
        if (indx > s.length() || s[indx] == '0') return 0;
        if (dp[indx] > -1) return dp[indx];
        long ones = helper(dp, s, indx + 1) * (s[indx] == '*' ? 9  : 1);
        long twos = 0;
        if (indx < s.length() - 1 && s[indx] < '3') {
            if (s[indx] == '*' && s[indx + 1] == '*')
                twos = 15;
            else if (s[indx] == '*')
                twos = s[indx + 1] < '7' ? 2 : 1;
            else if (s[indx + 1] == '*')
                twos = s[indx] == '1' ? 9 : 6;
            else {
                int tw = stoi(s.substr(indx, 2));
                twos = tw <= 26 ? 1 : 0;
            }
            twos *= twos ? helper(dp, s, indx + 2) : 0;
        }
        return dp[indx] = (ones + twos) % mod;
    }
    int numDecodings(string s) {
        vector<long> dp(s.size(), -1);
        return helper(dp, s, 0);
    }
};
// class Solution {
// public:
//     long long modulo = 1e9+7;
    
//     int check(string s , int idx , vector<int>&dp){
//         if(idx == s.length()) return 1;
//         if(idx > s.length() || s[idx]=='0') return 0;
//         if(dp[idx]>-1) return dp[idx];
        
//         long ones = check(s , idx+1 , dp)%modulo*(s[idx]=='*' ? 9 : 1);
//         long twos = 0;
//         if(idx < s.length()-1 && s[idx]<'3'){
//             if(s[idx]=='*' && s[idx+1]=='*'){
//                 twos = 15;
//             }
//             else if(s[idx]=='*'){
//                 twos = s[idx+1]<'7' ? 2 : 1;
//             }
//             else if(s[idx+1]=='*'){
//                 twos = s[idx]=='1' ? 9 : 6;
//             }
//             else {
//                 string temp = "";
//                 temp.push_back(s[idx]);
//                 temp.push_back(s[idx+1]);
//                 twos = (stoi(temp)>=10 && stoi(temp)<=26 ) ? 1 : 0;
//             }
            
//             twos*= twos ? check(s , idx+2 , dp) : 0;
//         }
        
//         return dp[idx] = (ones+twos)%modulo;
//     }
    
//     int numDecodings(string s) {
//         vector<int>dp(s.size() , -1);
//         return check(s , 0 , dp);
//     }
// };