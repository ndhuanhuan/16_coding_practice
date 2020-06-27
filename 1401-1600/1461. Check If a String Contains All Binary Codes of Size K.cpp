// https://zxi.mytechroad.com/blog/hashtable/leetcode-1461-check-if-a-string-contains-all-binary-codes-of-size-k/
class Solution {
public:
  bool hasAllCodes(string_view s, int k) {
    const int n = s.length();
    if ((n - k + 1) * k < (1 << k)) return false;
    unordered_set<string_view> c;
    for (int i = 0; i + k <= n; ++i)
      c.insert(s.substr(i, k));    
    return c.size() == (1 << k);
  }
};
