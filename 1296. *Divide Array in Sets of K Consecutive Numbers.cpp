// https://zxi.mytechroad.com/blog/greedy/leetcode-1296-divide-array-in-sets-of-k-consecutive-numbers/
// Solution 2 is tricky
class Solution {
public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k) return false;
    map<int, int> m;
    for (int num : nums) ++m[num];
    while (m.size()) {
      const int s = m.cbegin()->first;
      for (int i = 0; i < k; ++i) {
        auto it = m.find(s + i);
        if (it == m.cend()) return false;
        if (--it->second == 0) m.erase(it);
      }
    }
    return true;
  }
};
