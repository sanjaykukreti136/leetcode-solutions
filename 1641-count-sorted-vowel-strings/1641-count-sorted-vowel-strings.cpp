class Solution {
public:
    int countVowelStrings(int n) {
        vector <int> pos(5, 1);
        int res = 5;
        int j = 1;
        while (j <= n) {
            for (int i = 3; i >= 0; i--) {
                pos[i] = pos[i] + pos[i+1];
            }
            res = pos[0];
            j++;
        }
        return res;
    }
};