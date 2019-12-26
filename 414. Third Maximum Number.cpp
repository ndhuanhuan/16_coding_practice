// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-414-third-maximum-number/
class Solution {
public:
  int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int num : nums) {
      s.insert(num);
      if (s.size() > 3) s.erase(s.begin());
    }
    return s.size() != 3 ? *s.rbegin() : *s.begin();
  }
};
