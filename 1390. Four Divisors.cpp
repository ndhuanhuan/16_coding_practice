// https://zxi.mytechroad.com/blog/math/leetcode-1390-four-divisors/
class Solution {
public:
  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    for (int n : nums) {
      int r = sqrt(n);
      if (n <= 4 || r * r == n) continue;
      int count = 2;
      int sum = 1 + n;
      for (int d = 2; d <= r; ++d)
        if (n % d == 0) {
          count += 2;
          sum += n / d + d;
        }      
      if (count == 4) ans += sum;
    }
    return ans;
  }
};
