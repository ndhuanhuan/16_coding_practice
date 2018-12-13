//https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/201585/Simple-c%2B%2B-solution-with-explanation(beats-100)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> ans;
        int len = deck.size();
        while(len-->0){
            if(!ans.empty()){
                ans.insert(ans.begin(),ans.back());
                ans.pop_back();
            }
            ans.insert(ans.begin(),deck.back());
            deck.pop_back();
        }
        return ans;
    }
};
