// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        sort(arr.begin(), arr.end());
        if(arr.size()==0) return 0;
        vector<int>first = arr[0];
        int ans = 0;
        for(int i=1;i<arr.size();i++){
            if(first[0]==arr[i][0]){
                ans = max(ans  ,__gcd(first[1],
                            arr[i][1]) );
            }
            first = arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends