// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1356-sort-integers-by-the-number-of-1-bits/
class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(begin(arr), end(arr), [](const int a, const int b){
      int key_a = __builtin_popcount(a);
      int key_b = __builtin_popcount(b);
      if (key_a != key_b) return key_a < key_b;
      return a < b;
    });
    return arr;
  }
};