// https://zxi.mytechroad.com/blog/simulation/leetcode-1357-apply-discount-every-n-orders/
class Cashier {
public:
  Cashier(int n, int discount, 
          vector<int>& products, 
          vector<int>& prices): n_(n), c_(0), discount_(discount) {
    for (int i = 0; i < products.size(); ++i)
      prices_[products[i]] = prices[i];
  }
 
  double getBill(vector<int> product, vector<int> amount) {
    ++c_;
    double bill = 0.0;
    for (int i = 0; i < product.size(); ++i)
      bill += prices_[product[i]] * amount[i];
    if (c_ % n_ == 0)
      bill *= 1.0 - discount_ / 100.0;
    return bill;
   }
private:
  int n_;
  int c_;
  int discount_;
  array<int, 201> prices_;
};
