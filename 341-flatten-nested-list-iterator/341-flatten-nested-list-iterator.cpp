/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>mainList;
    int idx = 0;
    void helper(NestedInteger i){
        if(i.isInteger())
            mainList.push_back(i.getInteger());
        vector<NestedInteger> temp = i.getList();
        if(temp.size())
            for(auto i:temp)
                helper(i);
            
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i : nestedList){
            helper(i);
        }
    }
    
    int next() {
        return mainList[idx++];
    }
    
    bool hasNext() {
        if(idx < mainList.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */