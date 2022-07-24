class FoodRatings {
public:
    map<string, int> foodR;
    map<string, string> foodC;
    map<string, set<pair<int, string>>> TFood;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            foodR[foods[i]] = ratings[i];
            foodC[foods[i]] = cuisines[i];
            TFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old = foodR[food];
        TFood[foodC[food]].erase({-old, food});
        foodR[food] = newRating;
        TFood[foodC[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return TFood[cuisine].begin()->second;
    }
};