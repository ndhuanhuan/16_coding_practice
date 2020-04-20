// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1359-count-all-valid-pickup-and-delivery-options/
class Solution {
public:
  int countOrders(int n) {
    constexpr int kMod = 1e9 + 7;
    long ans = 1;
    for (int i = 2; i <= n; ++i)
      ans = ans * i * (2 * i - 1) % kMod;      
    return ans;
  }
};
