#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool compareEnd(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]);
    }

    int findMaxProfit(vector<vector<int>> &jobs, int endTime, int currentIndex, vector<int> &dp)
    {
        if (jobs.size() == currentIndex)
        {
            return 0;
        }
        if (endTime > jobs[currentIndex][0])
        {
            return findMaxProfit(jobs, endTime, currentIndex + 1, dp);
        }
        if (dp[currentIndex] != 0)
        {
            return dp[currentIndex];
        }
        return dp[currentIndex] = max(jobs[currentIndex][2] + findMaxProfit(jobs, jobs[currentIndex][1], currentIndex + 1, dp), findMaxProfit(jobs, endTime, currentIndex + 1, dp));
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++)
        {
            int st = startTime[i];
            int et = endTime[i];
            int pr = profit[i];
            jobs.push_back({st, et, pr});
        }
        vector<int> dp(startTime.size(), 0);
        sort(jobs.begin(), jobs.end(), compareEnd);
        return findMaxProfit(jobs, 0, 0, dp); //(jobs,endTime,index,dp)
    }
};
// class Solution {
// public:
//     struct pairP{
//         int start;
//         int end;
//         int pro;
        
//         pairP(int a , int b, int c){
//             start = a;
//             end = b;
//             pro = c;
//         }
//     };
    
//     int check(vector<pairP>&v, int idx , vector<int>&dp , int prev_end_time ){
//         if(idx == v.size()) return 0;
        
//         int current_start_time = v[idx].start;
//         int current_end_time = v[idx].end;
//         int profit = v[idx].pro;
        
//         if(current_start_time < prev_end_time){
//             return  dp[idx] = (check(v, idx+1 , dp , prev_end_time));
//         }
        
//         if(dp[idx]!=0) return dp[idx];
        
//         // if(current_start_time>=prev_end_time){
//             dp[idx] = max( check(v , idx+1 , dp , current_end_time )+ profit , check(v, idx+1,dp ,prev_end_time) );
//         // }
        
//         return dp[idx];
        
//     }
    
//     int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& c) {
//         vector<pairP>v;
//         for(int i=0;i<a.size();i++){
//             pairP *p = new pairP(a[i] , b[i], c[i]);
//             v.push_back(*p);
//         }
//         int n = v.size();
//         sort(v.begin() , v.end() , comp);
//         for(auto i : v){
//             cout<<i.start<<" - "<<i.end<<" - "<<i.pro<<"\n";
//         }
//         vector<int>dp(n , 0);
        
//         int ans =  check(v , 0 , dp , 0);
//         for(auto i : dp) cout<<i<<" ";
//         return ans;
//     }
    
// private : 
//     static bool comp(pairP &a ,pairP &b){
//         if(a.start!=b.start) return a.start<b.start;
//         if(a.end != b.end ) return a.end < b.end;
//         return a.pro > b.pro;
//     }
// };