class NumberContainers {
public:
    unordered_map<int,int> mpp ;
    unordered_map<int,set<int>> aux ;
    NumberContainers() {
        mpp.clear() , aux.clear() ;
    }
    
    void change(int index, int number) {
        if(mpp.find(index) != end(mpp)){
            //there is already other number y present at index "index" ; 
            aux[mpp[index]].erase(index) ; // remove the index from number's set aux[number]
            if(aux[mpp[index]].empty()) aux.erase(mpp[index]) ; //if size is zero then remove it entry from map because it no longer exists now
            mpp.erase(index) ;
        }
        aux[number].insert(index) ;
        mpp[index] = number ;
    }
    
    int find(int number) {
        if(aux.find(number) == end(aux)) return -1 ;
        return *begin(aux[number]) ;
    }
};