/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int check(map<int,int>&m, map<int,vector<int>>&graph, int id, int c){
        
        
        int sum = m[id];
        m.erase(id);
        for(auto i : graph[id]){
          if(m.find(i)!=m.end()) {
              sum+= check(m , graph , i  , c );
          }
        }
        
        return sum;
        
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        map<int,vector<int>>graph;
        map<int,int>m;
        vector<int>t;
        for(auto i : employees){
            graph[i->id-1] = t;
            for(auto j : i->subordinates){
                graph[i->id-1].push_back(j-1);
            }
            m[i->id-1] = i->importance;
        }
        
        int c = 0;
       c =  check(m , graph , id-1 , 0);
        return c;
        
    }
};