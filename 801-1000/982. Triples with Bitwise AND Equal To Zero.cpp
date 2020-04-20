//https://zxi.mytechroad.com/blog/bit/leetcode-982-triples-with-bitwise-and-equal-to-zero/
class Solution {
public:
  int countTriplets(vector<int>& A) {
    const int n = *max_element(begin(A), end(A));
    vector<int> count(n + 1);
    for (int a: A)
      for (int b: A)
        ++count[a & b];
    int ans = 0;
    for (int a : A)
      for (int i = 0; i <= n; ++i)
        if ((a & i) == 0) ans += count[i];
    return ans;
  }
};
