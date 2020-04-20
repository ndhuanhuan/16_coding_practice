class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for(auto i : J) {
            jewels.insert(i);
        }
        
        int result=0;
        for(auto i : S) {
            if(jewels.count(i) > 0) {
                ++result;
            }
        }
        return result;
    }
};
