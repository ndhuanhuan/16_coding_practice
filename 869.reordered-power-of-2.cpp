// https://zxi.mytechroad.com/blog/hashtable/leetcode-869-reordered-power-of-2/
class Solution {
public:
  bool reorderedPowerOf2(int N) {    
    auto m = countMap(N);
    for (int i = 0; i < 31; ++i)
      if (m == countMap(1 << i)) return true;
    return false;
  }
private:
  map<int, int> countMap(int n) {
    map<int, int> m;
    while (n) {
      ++m[n % 10];
      n /= 10;
    }
    return m;
  }
};
