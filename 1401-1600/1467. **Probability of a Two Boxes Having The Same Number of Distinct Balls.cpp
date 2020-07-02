// https://zxi.mytechroad.com/blog/searching/leetcode-1467-probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
// https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/discuss/662154/C%2B%2B-24ms%3A-Permutations-of-Combination
class Solution {
public:
  double getProbability(vector<int>& balls) {
    const int n = accumulate(begin(balls), end(balls), 0);
    const int k = balls.size();        
    double total = 0.0;
    double valid = 0.0;
    vector<double> fact(50, 1.0);
    for (int i = 1; i < fact.size(); ++i)
      fact[i] = fact[i - 1] * i;
    // d: depth
    // b1, b2: # of balls in box1, box2
    // c1, c2: # of distinct colors in box1, box2
    // p1, p2: # permutations of duplicate balls in box1, box2
    function<void(int, int, int, int, int, double, double)> dfs = [&]
      (int d, int b1, int b2, int c1, int c2, double p1, double p2) {
      if (b1 > n / 2 || b2 > n / 2) return;
      if (d == k) {
        const double count = fact[b1] / p1 * fact[b2] / p2;
        total += count;
        valid += count * (c1 == c2);
        return;
      }
      for (int s1 = 0; s1 <= balls[d]; ++s1) {
        const int s2 = balls[d] - s1;
        dfs(d + 1,
            b1 + s1, 
            b2 + s2,
            c1 + (s1 > 0), 
            c2 + (s2 > 0), 
            p1 * fact[s1], 
            p2 * fact[s2]);
      }
    };
    dfs(0, 0, 0, 0, 0, 1.0, 1.0);
    return valid / total;
  }
};
