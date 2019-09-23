
class Solution {
public:
    using Counter = unordered_map<char, int>; 
    int maxNumberOfBalloons(string text) {
        Counter cnt;
        for (auto ch: text) {
            ++cnt[ch];
        }
        return min({cnt['b'], cnt['a'], cnt['l'] / 2, cnt['o'] / 2, cnt['n']});
    }
};
