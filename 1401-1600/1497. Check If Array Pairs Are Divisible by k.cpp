// https://zxi.mytechroad.com/blog/math/leetcode-1497-check-if-array-pairs-are-divisible-by-k/
class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> f(k);
    for (int x : arr) ++f[(x % k + k) % k];
    for (int i = 1; i < k; ++i)
      if (f[i] != f[k - i]) return false;
    return f[0] % 2 == 0;
  }
};
