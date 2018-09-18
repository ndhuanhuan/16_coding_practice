//https://zxi.mytechroad.com/blog/stack/leetcode-901-online-stock-span/
// Author: Huahua
class StockSpanner {
public:
  StockSpanner() {}
 
  int next(int price) {
    int span = 1;
    while (!s_.empty() && price >= s_.top().first) {
      span += s_.top().second;  
      s_.pop();
    }
    s_.emplace(price, span);
    return span;
  }
private:
  stack<pair<int, int>> s_; // {price, span}, ordered by price DESC.
};
