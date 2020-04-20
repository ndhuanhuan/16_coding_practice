// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1352-product-of-the-last-k-numbers/
class ProductOfNumbers {
public:
  ProductOfNumbers(): p_(1, 1) { }
 
  void add(int num) {
    if (num == 0) {
      p_.clear();
      p_.push_back(1);
    } else {
      p_.push_back(p_.back() * num);
    }
  }
 
  int getProduct(int k) {
    if (k >= p_.size()) return 0; // tricky
    // a_1*a_2*...*a_n / a_1*a_2*...*a_n-k-1.
    return p_.back() / p_[p_.size() - k - 1];
  }
private:
  vector<int> p_;
};
