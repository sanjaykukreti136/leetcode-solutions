/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void check(Node *c, set<Node *>&s,map<Node*,Node*>&m ){
        s.insert(c);
        Node *copy = new Node(c->val);
        m.insert({c, copy});
        for(auto i : c->neighbors){
            if(s.find(i)==s.end()){
                check(i , s, m);
            }
        }
    }
    void add(map<Node*,Node*>m){
        for(auto i: m){
            for(auto j : i.first->neighbors){
                i.second->neighbors.push_back(m[j]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
       if(!node) return NULL;
        map<Node*,Node*>m;
        set<Node *>s;
        Node *copy = new Node(node->val);
        s.insert(node);
        m.insert({node , copy});
        for(auto i : node->neighbors){
            if(s.find(i)==s.end()){
                check(i , s, m);
            }
        }
        add(m);
        return m[node];
    }
};