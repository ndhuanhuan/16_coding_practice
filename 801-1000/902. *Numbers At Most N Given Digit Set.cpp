
// https://zxi.mytechroad.com/blog/math/leetcode-902-numbers-at-most-n-given-digit-set/
class Solution {
public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    const string s = to_string(N);
    const int n = s.length();
    int ans = 0;
    for (int i = 1; i < n; ++i)
      ans += pow(D.size(), i);
    
    for (int i = 0; i < n; ++i) {
      bool prefix = false;
      for (const string& d : D) {
        if (d[0] < s[i]) {
          ans += pow(D.size(), n - i - 1);
        } else if (d[0] == s[i]) {
          prefix = true;
          break;
        }
      }
      if (!prefix) return ans;
    }
    
    // plus one for solution N itself, all the digits are from D.
    return ans + 1;
  }
};
