// https://zxi.mytechroad.com/blog/math/leetcode-914-x-of-a-kind-in-a-deck-of-cards/
class Solution {
public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> counts;
    for (int card : deck) ++counts[card];
    for (int i = 2; i <= deck.size(); ++i) {
      if (deck.size() % i) continue;
      bool ok = true;
      for (const auto& pair : counts)
        if (pair.second % i) {
          ok = false;
          break;
        }
      if (ok) return true;
    }
    return false;
  }
};
