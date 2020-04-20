// https://zxi.mytechroad.com/blog/math/leetcode-1362-closest-divisors/
class Solution {
public:
  vector<int> closestDivisors(int num) {
    auto divisors = [](int n) {
      for (int i = sqrt(n); i >= 2; --i)
        if (n % i == 0) return vector<int>{i, n / i};
      return vector<int>{1, n};
    };
    
    auto ans1 = divisors(num + 1);
    auto ans2 = divisors(num + 2);
    return ans1[1] - ans1[0] < ans2[1] - ans2[0] ? ans1 : ans2;
  }
};
