// https://zxi.mytechroad.com/blog/hashtable/leetcode-888-fair-candy-swap/
class Solution {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {    
    int sum_a = accumulate(begin(A), end(A), 0);
    int sum_b = 0;
    unordered_set<int> s;
    for (int b : B) {
      sum_b += b;
      s.insert(b);
    }
    int diff = (sum_b - sum_a) / 2;
    for (int a : A)
      if (s.count(a + diff)) return {a, a + diff};
      
     return {0 , 0};
  }
};
