class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       if(n==0) return true;
        vector<vector<int>> graph(n);
        for(auto ele: prerequisites)
        {
            graph[ele[1]].push_back(ele[0]);
        }
        
        vector<int> indegree(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     for(auto ele: prerequisites[i])
        //         indegree[ele[0]]++;
        // }
        
        for(auto i : prerequisites){
            indegree[i[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        int cnt=0;
        stack<int> st;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            cnt++;
            for(auto ele: graph[node])
            {
                indegree[ele]--;
                if(indegree[ele]==0)
                    q.push(ele);
            }
        }
        if(cnt==n) return true;
        return false;
    }
};