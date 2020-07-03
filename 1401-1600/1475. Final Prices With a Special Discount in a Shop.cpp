// https://zxi.mytechroad.com/blog/stack/leetcode-1475-final-prices-with-a-special-discount-in-a-shop/
class Solution {
public:
  vector<int> finalPrices(vector<int> prices) {
    // stores indices of monotonically incraseing elements.
    stack<int> s; 
    for (int i = 0; i < prices.size(); ++i) {
      while (!s.empty() && prices[s.top()] >= prices[i]) {
        prices[s.top()] -= prices[i];
        s.pop();
      }
      s.push(i);
    }      
    return prices;
  }
};
