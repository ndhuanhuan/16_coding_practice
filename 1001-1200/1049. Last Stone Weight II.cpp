// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-137/
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    const int n = stones.size();
    const int max_sum = accumulate(begin(stones), end(stones), 0);    
    unordered_set<int> sums;
    sums.insert(stones[0]);
    sums.insert(-stones[0]);
    for (int i = 1; i < n; ++i) {
      unordered_set<int> tmp;
      for (int s : sums) {
        tmp.insert(s + stones[i]);
        tmp.insert(s - stones[i]);
      }
      swap(tmp, sums);
    }
    int ans = INT_MAX;
    for (int s : sums)           
      ans = min(ans, abs(s));
    return ans;
  }
};
