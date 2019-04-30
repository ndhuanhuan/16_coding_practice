// https://zxi.mytechroad.com/blog/greedy/leetcode-846-hand-of-straights/
class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> counts;
    for (int h : hand) ++counts[h];
    while (!counts.empty()) {
      auto it = counts.begin();
      int start = it->first;
      for (int j = 0; j < W; ++j) {        
        if (it == counts.end() 
            || it->first != start + j) return false;
        auto prev = it++;
        if (--(prev->second) == 0) 
          counts.erase(prev);
      }
    }    
    return true;
  }
};
