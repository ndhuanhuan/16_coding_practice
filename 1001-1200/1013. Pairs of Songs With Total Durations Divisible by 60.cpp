// https://zxi.mytechroad.com/blog/hashtable/leetcode-1013-pairs-of-songs-with-total-durations-divisible-by-60/
class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> c(60);
    int ans = 0;    
    for (int t : time) {
      t %= 60;
      ans += c[(60 - t) % 60];
      ++c[t];
    }
    return ans;
  }
};
