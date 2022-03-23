/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int n ;
    vector<int>t;
    int i=0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    n = nums.size();
        t = nums;
	}
	
	int peek() {
        return t[i];
	}
	
   
	int next() {
	    return t[i++];
	}
	
	bool hasNext() const {
	    if(i < n) return true;
        return false;
	}
};