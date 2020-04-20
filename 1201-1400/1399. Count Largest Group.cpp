// https://zxi.mytechroad.com/blog/hashtable/leetcode-1399-count-largest-group/
class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> c(37); // max sum is 9+9+9+9 = 36
    for (int i = 1; i <= n; ++i) {
      int x = i;
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      ++c[sum];
    }    
    return count(begin(c), end(c), *max_element(begin(c), end(c)));
  }
};
